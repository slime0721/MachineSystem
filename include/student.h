#include "identity.h"

class Student final : public Identity
{
    Student() = default;

    Student(int id, const std::string &name, const std::string &pwd);

    // 菜单界面
    void operMenu() override;

    // 申请预约
    void applyOrder();
    // 查看自己预约
    void showMyOrder();
    // 查看所有F预约
    void showAllOrder();
    // 取消预约
    void cancelOrder();

protected:
    // 学生学号
    int mId = 0;
};