#include "identity.h"

class Student:public Identity
{
    Student();

    Student(int id,string name,string pwd);

    //菜单界面
    virtual void operMeun();

    //申请预约
    void applyOrder();
    //查看自己预约
    void showMyOrder();
    //查看所有预约
    void showAllOrder();
    //取消预约
    void cancelOrder();
    //学生学号
    int mId;
};