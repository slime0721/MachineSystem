#include "identity.h"

class Teacher : public Identity
{
public:
    Teacher();

    Teacher(int emId, string name, string pwd);

    // 菜单
    virtual void operMeun();
    // 查看所有预约
    void showAllOrder();
    // 审核预约
    void validOrder();
    // 职工号
    int mEmid;
};