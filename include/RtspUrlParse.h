/**
  ******************************************************************************
  * @file           : RtspUrlParse.h
  * @author         : wlx
  * @brief          : None
  * @attention      : None
  * @date           : 2024/5/3
  ******************************************************************************
  */

#ifndef UTILFUNC_RTSPURLPARSE_H
#define UTILFUNC_RTSPURLPARSE_H

#include "string"

using namespace std;

class RtspUrlParse
{
public:
    //"rtsp://admin:admin123@192.168.61.6:66/cam/realmonitor?channel=1&subtype=0";
    explicit RtspUrlParse(string &strRtspUrl);

    inline string& GetProtocolHead()
    {
        return this->strProtocolHead;
    }

    inline string& GetUserName()
    {
        return this->strUserName;
    }

    inline string& GetPwd()
    {
        return this->strPwd;
    }

    inline string& GetIP()
    {
        return this->strIP;
    }

    inline int GetPort() const
    {
        return this->iPort;
    }

    inline string& GetRtspURI()
    {
        return this->strURI;
    }

private:
    string strUrl;

    string strProtocolHead;
    string strUserName;
    string strPwd;
    size_t iAddrStartPos;
    size_t iAddrEndtPos;
    string strIP;
    int iPort;
    string strURI;

private:
    void ParseAuthInfo();
    void ParseAddressInfo();
};


#endif //UTILFUNC_RTSPURLPARSE_H
