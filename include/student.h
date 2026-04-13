#pragma once
#include "identity.h"
#include "computerRoom.h"
#include "globalFile.h"

class Student final : public Identity
{
public:
    explicit Student(int id, const std::string &name, const std::string &pwd);

    // 菜单界面
    void operMenu() override;
    // 申请预约
    void applyOrder();
    // 查看自己预约
    void showMyOrder();
    // 查看所有预约
    void showAllOrder();
    // 取消预约
    void cancelOrder();

    int getId() const { return mId; }

private:
    // 学生学号
    int mId = 0;
    // 机房容器
    std::vector<ComputerRoom> vCom;
};