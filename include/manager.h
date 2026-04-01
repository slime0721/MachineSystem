#include "identity.h"

class Manager final : public Identity
{
public:
    Manager() = default;

    explicit Manager(const std::string &name, const std::string &pwd = "");

    // 菜单界面
    void operMenu() override;
    // 添加账号
    void addPerson();
    // 查看账号
    void showPerson();
    // 查看机房信息
    void showComputer();
    // 清空预约记录
    void clearFile();
};