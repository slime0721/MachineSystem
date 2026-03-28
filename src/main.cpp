#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int select = 0;

    while (true)
    {
        cout << "======================  欢迎来到机房预约系统  =======================" << endl;
        cout << endl
             << "请输入您的身份：" << endl;
        cout << "\t\t -------------------------------\n";
        cout << "\t\t                               \n";
        cout << "\t\t           1、学生代表          \n";
        cout << "\t\t                               \n";
        cout << "\t\t           2、老师              \n";
        cout << "\t\t                               \n";
        cout << "\t\t           3、管理员            \n";
        cout << "\t\t                               \n";
        cout << "\t\t           0、退出              \n";
        cout << "\t\t                               \n";
        cout << "\t\t -------------------------------\n";
        cout << "请输入您的选择: ";

        cin >> select;

        switch (select)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 0:
            cout << "欢迎下次使用" << endl;
            return 0;
        default:
            cout << "输入有误，请重新选择" << endl;
            system("pause");
            system("cls");
            break;
        }
    }

    return 0;
}
