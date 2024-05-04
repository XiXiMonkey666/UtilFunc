/**
  ******************************************************************************
  * @file           : RtspUrlParseTest.cpp
  * @author         : wlx
  * @brief          : None
  * @attention      : None
  * @date           : 2024/5/4
  ******************************************************************************
  */
#include <string>
#include <iostream>

#include "RtspUrlParseTest.h"
#include "RtspUrlParse.h"

using namespace std;

void __UrlParseTest(string &strRtspUrl)
{
    try
    {
        RtspUrlParse RtspStrObj(strRtspUrl);

        cout << "IP: " << RtspStrObj.GetIP() << std::endl;
        std::cout << "Port: " << RtspStrObj.GetPort() << std::endl;
        std::cout << "UserName: " << RtspStrObj.GetUserName() << std::endl;
        std::cout << "Pwd: " << RtspStrObj.GetPwd() << std::endl;
        std::cout << "URI: " << RtspStrObj.GetRtspURI() << std::endl;
    }
    catch(const char *err)
    {
        cout << "err: " << err << endl;
    }
}

void RtspUrlParseTest()
{
    string strNullRtsp;
    string strNotAuthRtsp("rtsp://192.168.1.30:888/cam/stream=0");
    string strNotAuthAndPortRtsp("rtsp://192.168.1.30/cam/stream=0");
    string strNotPortRtspUrl("rtsp://admin:123456@192.168.1.30/cam/stream=0");
    string strRtspUrl("rtsp://admin:123456@192.168.1.30:888/cam/stream=0");

    cout << endl << "======== parse null rtsp url start  ========" << endl;
    __UrlParseTest(strNullRtsp);

    cout << endl << "======== parse not auth rtsp url start  ========" << endl;
    __UrlParseTest(strNotAuthRtsp);

    cout << endl << "======== parse not auth and port rtsp url start  ========" << endl;
    __UrlParseTest(strNotAuthAndPortRtsp);

    cout << endl << "======== parse not port rtsp url start  ========" << endl;
    __UrlParseTest(strNotPortRtspUrl);

    cout << endl << "======== parse normal rtsp url start  ========" << endl;
    __UrlParseTest(strRtspUrl);
}
