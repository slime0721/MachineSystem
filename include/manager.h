#include "identity.h"
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "computerRoom.h"

class Manager final : public Identity
{
public:
    explicit Manager(const std::string &name, const std::string &pwd = ""); // 要求必须有姓名

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

private:
    // 初始化容器
    void initVector();
    // 检测重复
    bool checkRepeat(int id, int type);
    // 学生容器
    std::vector<Student> vStu;
    // 教师容器
    std::vector<Teacher> vTea;
    // 机房容器
    std::vector<ComputerRoom> vCom;
};