
参考资料：[CMake 入门实战](https://www.hahack.com/codes/cmake/)

快速入手：

Step 1  创建CMakeLists.txt

```
# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (Demo)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 指定生成目标
add_executable(Demo ${DIR_SRCS})
```

Step 2 编写 main.c fun.c fun.h

Step 3 命令行输入 `cmake .`

