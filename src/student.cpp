#include "student.h"
#include "orderFile.h"

Student::Student(int id, const std::string &name, const std::string &pwd) : Identity(name, pwd), mId(id)
{
    // 初始化机房信息
    std::ifstream ifs(COMPUTER_FILE);
    if (!ifs)
    {
        std::cerr << "机房文件打开失败！" << std::endl;
        return;
    }

    int fId = 0;
    int fMaxNum = 0;
    while (ifs >> fId >> fMaxNum)
    {
        vCom.emplace_back(fId, fMaxNum);
    }
}

// 菜单界面
void Student::operMenu()
{

    std::cout << "欢迎学生代表：" << getName() << "登录！" << std::endl;
    std::cout << "\t\t ---------------------------------\n";
    std::cout << "\t\t                                 \n";
    std::cout << "\t\t          1.申请预约              \n";
    std::cout << "\t\t                                 \n";
    std::cout << "\t\t          2.查看我的预约          \n";
    std::cout << "\t\t                                 \n";
    std::cout << "\t\t          3.查看所有预约          \n";
    std::cout << "\t\t                                 \n";
    std::cout << "\t\t          4.取消预约              \n";
    std::cout << "\t\t                                 \n";
    std::cout << "\t\t          0.注销登录              \n";
    std::cout << "\t\t                                 \n";
    std::cout << "\t\t ---------------------------------\n";
    std::cout << "请选择您的操作： " << std::endl;
}

// 申请预约
void Student::applyOrder()
{
    std::cout << "机房开放时间为周一到周五" << std::endl;
    std::cout << "请输入预约的时间：" << std::endl;
    std::cout << "1、周一" << std::endl;
    std::cout << "2、周二" << std::endl;
    std::cout << "3、周三" << std::endl;
    std::cout << "4、周四" << std::endl;
    std::cout << "5、周五" << std::endl;

    int date = 0;     // 日期
    int interval = 0; // 时间段
    int room = 0;     // 机房编号

    while (true)
    {
        std::cin >> date;
        if (date >= 1 && date <= 5)
        {
            break;
        }
        std::cout << "输入有误，请重新输入预约的时间" << std::endl;
    }

    std::cout << "请输入预约的时间段：" << std::endl;
    std::cout << "1、上午" << std::endl;
    std::cout << "2、下午" << std::endl;
    while (true)
    {
        std::cin >> interval;
        if (interval == 1 || interval == 2)
        {
            break;
        }
        std::cout << "输入有误，请重新输入预约的时间段" << std::endl;
    }

    std::cout << "请选择机房：" << std::endl;
    for (const auto &c : vCom)
    {
        std::cout << c.getId() << "号机房容量为：" << c.getMaxNum() << std::endl;
    }
    while (true)
    {
        std::cin >> room;
        if (room >= 1 && room <= 3)
        {
            break;
        }
        std::cout << "输入有误，请重新选择机房" << std::endl;
    }
    std::cout << "预约成功！审核中" << std::endl;

    std::ofstream ofs(ORDER_FILE, std::ios::app);
    if (!ofs)
    {
        std::cerr << "文件不存在" << std::endl;
        return;
    }
    ofs << "date:" << date << " "
        << "interval:" << interval << " "
        << "stuId:" << getId() << " "
        << "stuName:" << getName() << " "
        << "roomId:" << room << " "
        << "status:" << 1 << std::endl; // 1表示审核中
    ofs.close();
    system("pause");
    system("cls");
}

// 查看自己预约
void Student::showMyOrder()
{
    OrderFile of;
    if (of.getSize() == 0)
    {
        std::cout << "无预约记录" << std::endl;
        system("pause");
        system("cls");
        return;
    }

    const auto &orderData = of.getOrderData();
    for (const auto &pair : orderData)
    {
        if (std::stoi(pair.second.at("stuId")) == mId) // 找到自身预约
        {
            std::cout << "日期：" << pair.second.at("date") << " "
                      << "时间段：" << (pair.second.at("interval") == "1" ? "上午" : "下午") << " "
                      << "机房编号：" << pair.second.at("roomId") << " "
                      << "状态：";

            // 1 审核中 2 已预约 -1 预约失败 0 取消预约
            switch (std::stoi(pair.second.at("status")))
            {
            case 1:
                std::cout << "审核中";
                break;
            case 2:
                std::cout << "已预约";
                break;
            case -1:
                std::cout << "预约失败";
                break;
            case 0:
                std::cout << "取消预约";
                break;
            default:
                std::cout << "未知状态";
                break;
            }
            std::cout << std::endl;
        }
    }
    system("pause");
    system("cls");
}

// 查看所有预约
void Student::showAllOrder()
{
    OrderFile of;
    if (of.getSize() == 0)
    {
        std::cout << "无预约记录" << std::endl;
        system("pause");
        system("cls");
        return;
    }

    int i = 1;
    const auto &orderData = of.getOrderData();
    for (const auto &pair : orderData)
    {
        std::cout << i++ << "、 ";

        std::cout << "日期：" << pair.second.at("date") << " "
                  << "时间段：" << (pair.second.at("interval") == "1" ? "上午" : "下午") << " "
                  << "机房编号：" << pair.second.at("roomId") << " "
                  << "学生编号：" << pair.second.at("stuId") << " "
                  << "学生姓名：" << pair.second.at("stuName") << " "
                  << "状态：";

        switch (std::stoi(pair.second.at("status")))
        {
        case 1:
            std::cout << "审核中";
            break;
        case 2:
            std::cout << "已预约";
            break;
        case -1:
            std::cout << "预约失败";
            break;
        case 0:
            std::cout << "取消预约";
            break;
        default:
            std::cout << "未知状态";
            break;
        }
        std::cout << std::endl;
    }
    system("pause");
    system("cls");
}

// 取消预约
void Student::cancelOrder()
{
    OrderFile of;
    if (of.getSize() == 0)
    {
        std::cout << "无预约记录" << std::endl;
        system("pause");
        system("cls");
        return;
    }

    std::cout << "审核中或预约成功记录可以取消，请输入取消的记录：" << std::endl;
    // 存储可取消预约的索引
    std::vector<int> v; // 存储 mOrderData 中真实的 Key (即 pair.first)

    int index = 1;
    const auto &orderData = of.getOrderData();
    for (const auto &pair : orderData)
    {
        // 判断是自身学号
        if (std::stoi(pair.second.at("stuId")) == mId && (pair.second.at("status") == "1" || pair.second.at("status") == "2"))
        {
            v.emplace_back(pair.first); // 存储可取消预约的索引
            std::cout << index++ << "、 ";
            std::cout << "日期：" << pair.second.at("date") << " "
                      << "时间段：" << (pair.second.at("interval") == "1" ? "上午" : "下午") << " "
                      << "机房编号：" << pair.second.at("roomId") << " "
                      << "状态：" << (pair.second.at("status") == "1" ? "审核中" : "已预约") << std::endl;
        }
    }

    if (v.empty())
    {
        std::cout << "暂无可取消的预约记录。" << std::endl;
        system("pause");
        system("cls");
        return;
    }

    std::cout << "请输入取消的记录 0代表返回：" << std::endl;
    int select = 0;
    while (true)
    {
        std::cin >> select;

        if (select >= 0 && select <= v.size())
        {
            if (select == 0)
            {
                break;
            }
            else
            {
                of.updateStatus(v[select - 1], "0");
                of.updateOrder();
                std::cout << "取消预约成功！" << std::endl;
                break;
            }
        }
        std::cout << "输入有误，请重新输入取消的记录编号" << std::endl;
    }
    system("pause");
    system("cls");
}