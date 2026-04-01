#include "identity.h"

class Teacher final: public Identity
{
public:
    Teacher() = default;

    explicit Teacher(int id,const std:: string& name,const std:: string& pwd);

    // 菜单
    void operMenu() override;
    // 查看所有预约
    void showAllOrder();
    // 审核预约
    void validOrder();
    // 职工号
    int mEmid = 0;
};