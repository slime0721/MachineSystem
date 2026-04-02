cmake_minimum_required(VERSION 3.10)
project(MachineManager)

# 鐠佸墽鐤� C++ 閺嶅洤鍣稉锟� 11
set(CMAKE_CXX_STANDARD 11)

# 1. 閸涘﹨鐦旂紓鏍槯閸ｎ煉绱伴崢鏄忕箹娑擃亝鏋冩禒璺恒仚閹碉拷 .h 婢跺瓨鏋冩禒锟�
include_directories(include)

# 2. 閸涘﹨鐦旂紓鏍槯閸ｎ煉绱伴崢鏄忕箹娑擃亝鏋冩禒璺恒仚閹电偓澧嶉張澶屾畱 .cpp 濠ф劖鏋冩禒锟�
file(GLOB SOURCES "src/*.cpp")

# 3. 閸涘﹨鐦旂紓鏍槯閸ｎ煉绱伴幎濠呯箹娴滄稒绨弬鍥︽缂傛牞鐦ч幋鎰娑擃亜褰� MachineManager.exe 閻ㄥ嫮鈻兼惔锟�
add_executable(MachineManager ${SOURCES})