//
// Created by Administrator on 2024/5/3.
//
#include <iostream>
#include "RtspUrlParseTest.h"
#include "JsonTest.h"

using namespace std;

int main()
{
    cout << "======== rtsp url parse start ========" << endl;
    RtspUrlParseTest();
    cout << endl;
    cout << "======== rtsp url parse end ========" << endl;

    cout << "======== json test start ========" << endl;
    JsonTest();
    cout << "======== json test end ========" << endl;
}