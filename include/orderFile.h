#pragma once
#include "globalFile.h"
#include <map>
#include <string>
#include <fstream>

class OrderFile
{
public:
    OrderFile();
    // 更新预约记录
    void updateOrder();
    // 不另外定义msize成员变量，直接通过mOrderData.size()获取预约记录条数

    size_t getSize() const { return mOrderData.size(); }

    const std::map<int, std::map<std::string, std::string>> &getOrderData() const
    {
        return mOrderData;
    }

    void updateStatus(int key, std::string newStatus)
    {
        auto it = mOrderData.find(key);
        if (it != mOrderData.end())
        {
            it->second["status"] = newStatus;
        }
        else
        {
            std::cerr << "错误：未找到索引为 " << key << " 的预约记录" << std::endl;
        }
    }

private:
    // 解析带冒号的字符串并插入到指定的 map 中
    void parseAndInsert(std::map<std::string, std::string> &m, const std::string &str);
    // 记录所有预约信息的容器
    std::map<int, std::map<std::string, std::string>> mOrderData; // 记录条数 记录中所有信息
};