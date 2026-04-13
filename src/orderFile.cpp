#include "orderFile.h"

// 封装读取记录函数
void OrderFile::parseAndInsert(std::map<std::string, std::string> &m, const std::string &str)
{
    size_t pos = str.find(":");
    if (pos != std::string::npos)
    {
        std::string key = str.substr(0, pos);
        std::string value = str.substr(pos + 1, str.size() - pos - 1);
        m.emplace(std::move(key), std::move(value));
    }
}

OrderFile::OrderFile()
{
    std::ifstream ifs(ORDER_FILE);
    if (!ifs)
    {
        std::cerr << "预约记录文件打开失败！" << std::endl;
        return;
    }

    std::string date = "";     // 日期
    std::string interval = ""; // 时间段
    std::string stuId = "";    // 学生编号
    std::string stuName = "";  // 学生姓名
    std::string roomId = "";   // 机房编号
    std::string status = "";   // 预约状态

    int count = 0;

    while (ifs >> date >> interval >> stuId >> stuName >> roomId >> status)
    {
        std::map<std::string, std::string> m;

        parseAndInsert(m, date);
        parseAndInsert(m, interval);
        parseAndInsert(m, stuId);
        parseAndInsert(m, stuName);
        parseAndInsert(m, roomId);
        parseAndInsert(m, status);

        mOrderData.emplace(count++, std::move(m));
    }
}

// 更新预约记录
void OrderFile::updateOrder()
{
    std::ofstream ofs(ORDER_FILE, std::ios::trunc);
    if (!ofs)
    {
        std::cerr << "预约记录文件打开失败！" << std::endl;
        return;
    }
    
    for (const auto &pair : mOrderData)
    {
        const auto &data = pair.second;
        ofs << "date:" << data.at("date") << " "
            << "interval:" << data.at("interval") << " "
            << "stuId:" << data.at("stuId") << " "
            << "stuName:" << data.at("stuName") << " "
            << "roomId:" << data.at("roomId") << " "
            << "status:" << data.at("status") << std::endl;
    }
    ofs.close();
}