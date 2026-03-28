#include "identity.h"

class Manager : public Identity
{
public:
    Manager();

    Manager(string name, string pwd);

    // 菜单界面
    virtual void operMeun();
    // 添加账号
    void addPerson();
    // 查看账号
    void showPerson();
    // 查看机房信息
    void showComputer();
    // 清空预约记录
    void clearFile();
};