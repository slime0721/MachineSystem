#pragma once
#include <iostream>
using namespace std;

//身份抽象基类
class Identity
{
    public:
    //操作菜单
    virtual void operMeun() = 0;

    string mName;
    string mPwd;
};