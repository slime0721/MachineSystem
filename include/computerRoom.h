#pragma once
#include <iostream>

class ComputerRoom
{
public:
    explicit ComputerRoom(int id, int num) : mComId(id), mMaxNum(num)
    {
    }

    int getId() const { return mComId; }
    int getMaxNum() const { return mMaxNum; }

private:
    int mComId = 0;  // 机房编号
    int mMaxNum = 0; // 机房最大容量
};