# SRCS = fun.c main.c
# OBJS = fun.o main.o
CC = gcc
CFLAGS = -g -Wall

SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)
main:$(OBJS)
	$(CC) -o $@ $^

# $@：目标的名字

# $^：构造所需文件列表所有文件的名字

# $<：构造所需文件列表的第一个文件的名字

# $?：构造所需文件列表中更新过的文件
 
.PHONY : clean
clean :
	-rm main $(OBJS)

#.PHONY 用来定义这些不是文件的目标。make 会默认调用这些伪目标下的步骤，而不去检查文件名是否存在或最后修改日期。
