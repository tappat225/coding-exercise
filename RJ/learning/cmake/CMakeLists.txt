# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (Demo1)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 指定生成目标(繁琐写法)
# add_executable(Demo main.c fun.c)

# 指定生成目标(精简写法)
add_executable(Demo ${DIR_SRCS})