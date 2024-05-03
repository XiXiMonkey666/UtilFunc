/**
  ******************************************************************************
  * @file           : RtspUrlParse.cpp
  * @author         : wlx
  * @brief          : None
  * @attention      : None
  * @date           : 2024/5/3
  ******************************************************************************
  */
#include <iostream>

#include "RtspUrlParse.h"

RtspUrlParse::RtspUrlParse(string &strRtspUrl)
{
    if (strRtspUrl.empty())
    {
        throw("Rtsp URL is null.");
    }

    this->strProtocolHead = "rtsp://";
    if (strRtspUrl.compare(0, this->strProtocolHead.size(), this->strProtocolHead) != 0)
    {
        throw ("Rtsp URL is error.");
    }

    this->strUrl = strRtspUrl;
    this->iAddrStartPos = this->strProtocolHead.size();

    // 获取鉴权信息
    ParseAuthInfo();

    // 获取地址信息
    ParseAddressInfo();

    // 获取uri
    size_t iURIPos = strRtspUrl.find('/', this->iAddrEndtPos);
    if (iURIPos != std::string::npos)
    {
        this->strURI = strRtspUrl.substr(iURIPos);
    }
}

/**
 * @brief 解析用户名 密码
 */
void RtspUrlParse::ParseAuthInfo()
{
    size_t iAuthInfoPos = this->strUrl.find('@');
    if (iAuthInfoPos != std::string::npos)
    {
        string strAuthInfo = this->strUrl.substr(this->strProtocolHead.size(),
                                                 iAuthInfoPos - this->strProtocolHead.size());

        // 从鉴权信息中获取用户名 密码
        size_t iPwdPos = strAuthInfo.find(':');
        this->strUserName = strAuthInfo.substr(0,iPwdPos);
        if (iPwdPos != std::string::npos)
        {
            this->strPwd = strAuthInfo.substr(iPwdPos + 1);
        }

        this->iAddrStartPos = iAuthInfoPos + 1;
    }
}

/**
 * @brief 获取ip port
 */
void RtspUrlParse::ParseAddressInfo()
{
    string strAddressInfo;
    this->iAddrEndtPos = this->strUrl.find('/', this->iAddrStartPos);
    if (this->iAddrEndtPos != std::string::npos)
    {
        strAddressInfo = this->strUrl.substr(this->iAddrStartPos, this->iAddrEndtPos - this->iAddrStartPos);
    }
    else
    {
        throw ("Rtsp address info is error.");
    }

    // 从地址信息中获取ip port
    size_t iPortPos = strAddressInfo.find(':');
    this->strIP = strAddressInfo.substr(0,iPortPos);
    if (this->strIP.empty())
    {
        throw ("Rtsp address info is error.");
    }

    if (iPortPos != std::string::npos)
    {
        string strPort = strAddressInfo.substr(iPortPos + 1);
        this->iPort = std::stoi(strPort);
    }
    else
    {
        this->iPort = 554;
    }
}