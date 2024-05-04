/**
  ******************************************************************************
  * @file           : JsonTest.cpp
  * @author         : wlx
  * @brief          : None
  * @attention      : None
  * @date           : 2024/5/4
  * 实例参考链接: https://www.cnblogs.com/RioTian/p/17669943.html
  ******************************************************************************
  */
#include <iostream>
#include <fstream>
#include <filesystem>
#include "nlohmann/json.hpp"

using namespace std;
using Json = nlohmann::json;

void JsonPackageTest()
{
    Json jsonPersonInfo;

    jsonPersonInfo["name"] = "wlx";
    jsonPersonInfo["age"] = 28;

    cout << jsonPersonInfo << endl;

    ofstream o("json.json");
    o << std::setw(4) << jsonPersonInfo << std::endl;
}

void JsonParse()
{

}

void JsonTest()
{
    JsonPackageTest();
    JsonParse();
}