//
// Created by Administrator on 2024/5/3.
//

#include <iostream>
#include "string"

#include "RtspUrlParse.h"

using namespace std;

void test(string &strRtspUrl)
{
    try
    {
        RtspUrlParse RtspStrObj(strRtspUrl);

        std::cout << "IP: " << RtspStrObj.GetIP() << std::endl;
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

int main()
{
    string strNullRtsp;
    string strNotAuthRtsp("rtsp://192.168.1.30:888/cam/stream=0");
    string strNotAuthAndPortRtsp("rtsp://192.168.1.30/cam/stream=0");
    string strNotPortRtspUrl("rtsp://admin:123456@192.168.1.30/cam/stream=0");
    string strRtspUrl("rtsp://admin:123456@192.168.1.30:888/cam/stream=0");

    test(strNullRtsp);
    test(strNotAuthRtsp);
    test(strNotAuthAndPortRtsp);
    test(strNotPortRtspUrl);
    test(strRtspUrl);
}