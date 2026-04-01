#pragma once
#include <iostream>
#include <string>

// 身份抽象基类
class Identity
{
public:
    // 操作菜单
    virtual void operMenu() = 0;

protected:
    std::string mName = "";
    std::string mPwd = "";
};