# Auto tools使用教程

**Step 1** 

确保代码在同一目录下

**Step 2** 

输入命令autoscan扫描当前目录并生成configure.scan

**Step 3** 

将configure.scan重命名为configure.ac并编辑

```
#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(DEMO,1.0,hello@qq.com)
AM_INIT_AUTOMAKE(DEMO,1.0)
AC_CONFIG_SRCDIR([main.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([fun.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CONFIG_FILES([Makefile])

AC_OUTPUT

```

**标签说明**

AC_PREREQ

声明autoconf要求的版本号

AC_INIT

定义软件名称、版本号、联系方式

AM_INIT_AUTOMAKE

必须要的，参数为软件名称和版本号

AC_CONFIG_SCRDIR

宏用来侦测所指定的源码文件是否存在, 来确定源码目录的有效性.。此处为当前目录下main.c。

AC_CONFIG_HEADER

宏用于生成config.h文件，以便 autoheader 命令使用。

AC_PROG_CC

指定编译器，默认GCC

AC_CONFIG_FILES

生成相应的Makefile文件，不同文件夹下的Makefile通过空格分隔。例如：AC_CONFIG_FILES([Makefile, src/Makefile]) 

AC_OUTPUT

用来设定 configure 所要产生的文件，如果是makefile，configure 会把它检查出来的结果带入makefile.in文件产生合适的makefile。

**Step 4**

输入命令aclocal

> 扫描 configure.ac 文件生成 aclocal.m4文件, 该文件主要处理本地的宏定义，它根据已经安装的宏、用户定义宏和 acinclude.m4 文件中的宏将 configure.ac 文件需要的宏集中定义到文件 aclocal.m4 中。 

**Step 5**

输入命令autoconf

> 这个命令将 configure.ac 文件中的宏展开，生成 configure 脚本。这个过程可能要用到aclocal.m4中定义的宏。

**Step 6**

输入命令autoheader

> 该命令生成 config.h.in 文件。该命令通常会从 "acconfig.h” 文件中复制用户附加的符号定义。该例子中没有附加的符号定义, 所以不需要创建 "acconfig.h” 文件。

**Step 7**

创建Makefile.am

> Automake工具会根据 configure.in 中的参量把 Makefile.am 转换成 Makefile.in 文件。最终通过Makefile.in生成Makefile文件，所以Makefile.am这个文件非常重要，定义了一些生成Makefile的规则。

编辑内容：

```
AUTOMARK_OPTIONS = foreign
bin_PROGRAMS = demo
demo_SOURCES = main.c fun.c fun.h
```

参数解释：

1. AUTOMAKE_OPTIONS：由于GNU对自己发布的软件有严格的规范, 比如必须附带许可证声明文件COPYING等，否则automake执行时会报错. automake提供了3中软件等级:foreign, gnu和gnits, 供用户选择。默认级别是gnu. 在本例中， 使用了foreign等级, 它只检测必须的文件。

2. bin_PROGRAMS = demo ：生成的可执行文件名称，生成多个可执行文件，可以用空格隔开。

3. demo_SOURCES：生成可执行文件demo需要依赖的源文件。其中demo_为可执行文件的名称。

**Step 8**

执行`automake --add-missing`

> 该命令生成 Makefile.in 文件。使用选项 "--add-missing" 可以让 Automake 自动添加一些必需的脚本文件。如果发现一些文件不存在，可以通过手工 touch命令创建。

本试验中还需添加以下文件

```
touch NEWS README AUTHORS ChangeLog
```

**Step 9**

最熟悉的环节——执行`./configure`，生成Makefile

**Step 10**

make
