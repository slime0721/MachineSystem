#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

// 身份抽象基类
class Identity
{
public:
    Identity(const std::string &name, const std::string &pwd) : mName(name), mPwd(pwd)
    {
    }

    // 虚析构函数
    virtual ~Identity() = default;

    // 操作菜单
    virtual void operMenu() = 0;

    // 提供接口
    std::string getName() const { return mName; }

private:
    std::string mName = "";
    std::string mPwd = "";
};