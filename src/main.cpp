#include "identity.h"
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"

// 学生菜单
void studentMenu(Student *&student)
{
    while (true)
    {
        student->operMenu();
        int select = 0;
        std::cin >> select;

        switch (select)
        {
        case 1:
            student->applyOrder();
            break;
        case 2:
            student->showMyOrder();
            break;
        case 3:
            student->showAllOrder();
            break;
        case 4:
            student->cancelOrder();
            break;
        case 0:
            std::cout << "欢迎下次使用" << std::endl;
            delete student;
            student = nullptr;
            system("pause");
            system("cls");
            return;
        default:
            std::cout << "输入有误，请重新选择" << std::endl;
            system("pause");
            system("cls");
            break;
        }
    }
}

// 管理员菜单
void managerMenu(Manager *&manager)
{
    while (true)
    {
        manager->operMenu();
        int select = 0;
        std::cin >> select;

        switch (select)
        {
        case 1:
            manager->addPerson();
            break;
        case 2:
            manager->showPerson();
            break;
        case 3:
            manager->showComputer();
            break;
        case 4:
            manager->clearFile();
            break;
        case 0:
            std::cout << "欢迎下次使用" << std::endl;
            delete manager;
            manager = nullptr;
            system("pause");
            system("cls");
            return;
        default:
            std::cout << "输入有误，请重新选择" << std::endl;
            system("pause");
            system("cls");
            break;
        }
    }
}

// 登录功能
void LoginIn(const std::string &fileName, int type) // 操作文件名 操作身份类型
{
    // Identity *person = nullptr;

    std::ifstream ifs(fileName);
    if (!ifs)
    {
        std::cerr << "文件不存在" << std::endl;
        return;
    }

    int id = 0;
    std::string name = "";
    std::string pwd = "";

    // 判断身份
    if (type == 1)
    {
        std::cout << "请输入你的学号：" << std::endl;
        std::cin >> id;
    }
    else if (type == 2)
    {
        std::cout << "请输入职工号：" << std::endl;
        std::cin >> id;
    }
    std::cout << "请输入用户名：" << std::endl;
    std::cin >> name;
    std::cout << "请输入密码：" << std::endl;
    std::cin >> pwd;

    if (type == 1)
    {
        // 从文件中读取数据
        int fId = 0;
        std::string fName = "";
        std::string fPwd = "";
        while (ifs >> fId >> fName >> fPwd)
        {
            if (fId == id && fName == name && fPwd == pwd)
            {
                std::cout << "学生登录成功！" << std::endl;
                system("pause");
                system("cls");

                Student *stu = new Student(id, name, pwd);
                studentMenu(stu);
                return;
            }
        }
    }
    else if (type == 2)
    {
        int fId = 0;
        std::string fName = "";
        std::string fPwd = "";
        while (ifs >> fId >> fName >> fPwd)
        {
            if (fId == id && fName == name && fPwd == pwd)
            {
                std::cout << "老师登录成功！" << std::endl;
                system("pause");
                system("cls");
                return;
            }
        }
    }
    else if (type == 3)
    {
        std::string fName = "";
        std::string fPwd = "";
        while (ifs >> fName >> fPwd)
        {
            if (fName == name && fPwd == pwd)
            {
                std::cout << "管理员登录成功！" << std::endl;
                system("pause");
                system("cls");

                Manager *man = new Manager(name, pwd);
                managerMenu(man);
                return;
            }
        }
    }

    std::cout << "验证登录失败！" << std::endl;
    system("pause");
    system("cls");
}

void showMenu()
{
    std::cout << "======================  欢迎来到机房预约系统  =======================" << std::endl;
    std::cout << std::endl
              << "请输入您的身份：" << std::endl;
    std::cout << "\t\t -------------------------------\n";
    std::cout << "\t\t                               \n";
    std::cout << "\t\t           1、学生代表          \n";
    std::cout << "\t\t                               \n";
    std::cout << "\t\t           2、老师              \n";
    std::cout << "\t\t                               \n";
    std::cout << "\t\t           3、管理员            \n";
    std::cout << "\t\t                               \n";
    std::cout << "\t\t           0、退出              \n";
    std::cout << "\t\t                               \n";
    std::cout << "\t\t -------------------------------\n";
    std::cout << "请输入您的选择: ";
}

int main(int argc, char const *argv[])
{
    while (true)
    {
        showMenu();

        int select = 0;
        std::cin >> select;

        switch (select)
        {
        case 1:
            LoginIn(STUDENT_FILE, 1);
            break;
        case 2:
            LoginIn(TEACHER_FILE, 2);
            break;
        case 3:
            LoginIn(ADMIN_FILE, 3);
            break;
        case 0:
            std::cout << "欢迎下次使用" << std::endl;
            system("pause");
            system("cls");
            return 0;
        default:
            std::cout << "输入有误，请重新选择" << std::endl;
            system("pause");
            system("cls");
            break;
        }
    }
    return 0;
}
