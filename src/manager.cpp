#include "manager.h"

Manager::Manager(const std::string &name, const std::string &pwd) : Identity(name, pwd)
{
    // 初始化容器 获取学生老师信息
    this->initVector();

    // 初始化机房 (因为不做修改机房功能所以不单独封装函数)
    std::ifstream ifs(COMPUTER_FILE);
    if (!ifs)
    {
        std::cout << "机房文件打开失败！" << std::endl;
        return;
    }

    int fId = 0;
    int fMaxNum = 0;
    while (ifs >> fId >> fMaxNum)
    {
        vCom.emplace_back(fId, fMaxNum);
    }
    std::cout << "机房数量为：" << vCom.size() << std::endl;
}

// 菜单界面
void Manager::operMenu()
{
    std::cout << "欢迎管理员：" << this->getName() << "登录！" << std::endl;
    std::cout << "\t\t ---------------------------------\n";
    std::cout << "\t\t                                 \n";
    std::cout << "\t\t          1.添加账号              \n";
    std::cout << "\t\t                                 \n";
    std::cout << "\t\t          2.查看账号             \n";
    std::cout << "\t\t                                 \n";
    std::cout << "\t\t          3.查看机房             \n";
    std::cout << "\t\t                                 \n";
    std::cout << "\t\t          4.清空预约             \n";
    std::cout << "\t\t                                 \n";
    std::cout << "\t\t          0.注销登录             \n";
    std::cout << "\t\t                                 \n";
    std::cout << "\t\t ---------------------------------\n";
    std::cout << "请选择您的操作： " << std::endl;
}

// 添加账号
void Manager::addPerson()
{
    std::cout << "请输入添加账号的类型：" << std::endl;
    std::cout << "1、添加学生账号" << std::endl;
    std::cout << "2、添加教师账号" << std::endl;

    int select = 0;
    std::cin >> select;
    std::string fileName = "";
    std::string tip = "";
    std::string errorTip = "";
    if (select == 1)
    {
        fileName = STUDENT_FILE;
        tip = "请输入学号：";
        errorTip = "学号重复，请重新输入！";
    }
    else if (select == 2)
    {
        fileName = TEACHER_FILE;
        tip = "请输入职工号：";
        errorTip = "职工号重复，请重新输入！";
    }
    else
    {
        std::cout << "输入有误" << std::endl;
        system("pause");
        return;
    }

    int id = 0;
    std::string name = "";
    std::string pwd = "";

    std::cout << tip << std::endl;

    while (true)
    {
        std::cin >> id;
        bool ret = checkRepeat(id, select);
        if (ret)
        {
            std::cout << errorTip << std::endl;
        }
        else
        {
            break;
        }
    }

    std::cout << "请输入姓名：" << std::endl;
    std::cin >> name;
    std::cout << "请输入的密码：" << std::endl;
    std::cin >> pwd;

    std::ofstream ofs(fileName, std::ios::out | std::ios::app);
    if (!ofs)
    {
        std::cout << "文件不存在" << std::endl;
        return;
    }
    ofs << id << " " << name << " " << pwd << std::endl;
    std::cout << "添加成功！" << std::endl;

    this->initVector();

    system("pause");
    system("cls");
}

// 查看账号
void Manager::showPerson()
{
    std::cout << "请选择查看内容：" << std::endl;
    std::cout << "1、查看学生账号" << std::endl;
    std::cout << "2、查看教师账号" << std::endl;

    int select = 0;
    std::cin >> select;
    if (select == 1)
    {
        std::cout << "学生账号信息如下：" << std::endl;
        for (const auto &s : vStu)
        {
            std::cout << "学号：" << s.getId() << "姓名：" << s.getName() << std::endl;
        }
    }
    else if (select == 2)
    {
        std::cout << "教师账号信息如下：" << std::endl;
        for (const auto &t : vTea)
        {
            std::cout << "职工号：" << t.getId() << "姓名：" << t.getName() << std::endl;
        }
    }
    else
    {
        std::cout << "输入有误" << std::endl;
    }
    system("pause");
    system("cls");
}

// 查看机房信息
void Manager::showComputer()
{
    std::cout << "机房信息如下：" << std::endl;
    for (const auto &c : vCom)
    {
        std::cout << "机房编号：" << c.getId() << "最大容量：" << c.getMaxNum() << std::endl;
    }
    system("pause");
    system("cls");
}

// 清空预约记录
void Manager::clearFile()
{
    std::cout << "确定要清空所有预约记录吗？" << std::endl;
    std::cout << "1、确定" << std::endl;
    std::cout << "按任意数字返回" << std::endl;
    int select = 0;
    std::cin >> select;
    if (select != 1)
    {
        return;
    }

    std::ofstream ofs(ORDER_FILE, std::ios::trunc);
    if (!ofs)
    {
        std::cout << "文件打开失败，清空取消。" << std::endl;
        return;
    }
    std::cout << "清空成功！" << std::endl;
    system("pause");
    system("cls");
}

// 初始化容器
void Manager::initVector()
{
    // 确保容器清空状态
    vStu.clear();
    vTea.clear();

    // 读取信息
    { // 局部代码块
        std::ifstream ifs(STUDENT_FILE);
        if (!ifs)
        {
            std::cout << "学生文件不存在" << std::endl;
            return;
        }
        int id = 0;
        std::string name = "";
        std::string pwd = "";
        while (ifs >> id >> name >> pwd)
        {
            vStu.emplace_back(id, name, pwd);
        }
        std::cout << "学生数量为：" << vStu.size() << std::endl;
    }

    {
        std::ifstream ifs(TEACHER_FILE);
        if (!ifs)
        {
            std::cout << "教师文件不存在" << std::endl;
            return;
        }
        int id = 0;
        std::string name = "";
        std::string pwd = "";
        while (ifs >> id >> name >> pwd)
        {
            vTea.emplace_back(id, name, pwd);
        }
        std::cout << "教师数量为：" << vTea.size() << std::endl;
    }
}

// 检测重复
bool Manager::checkRepeat(int id, int type)
{
    if (type == 1)
    {
        for (const auto &s : vStu)
        {
            if (s.getId() == id)
            {
                return true;
            }
        }
    }
    else if (type == 2)
    {
        for (const auto &t : vTea)
        {
            if (t.getId() == id)
            {
                return true;
            }
        }
    }
    return false;
}