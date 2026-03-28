cmake_minimum_required(VERSION 3.10)
project(MachineManager)

# 璁剧疆 C++ 鏍囧噯涓� 11
set(CMAKE_CXX_STANDARD 11)

# 1. 鍛婅瘔缂栬瘧鍣細鍘昏繖涓枃浠跺す鎵� .h 澶存枃浠�
include_directories(include)

# 2. 鍛婅瘔缂栬瘧鍣細鍘昏繖涓枃浠跺す鎵炬墍鏈夌殑 .cpp 婧愭枃浠�
file(GLOB SOURCES "src/*.cpp")

# 3. 鍛婅瘔缂栬瘧鍣細鎶婅繖浜涙簮鏂囦欢缂栬瘧鎴愪竴涓彨 MachineManager.exe 鐨勭▼搴�
add_executable(MachineManager ${SOURCES})