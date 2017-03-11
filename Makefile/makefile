#自定义变量
#obj=main.o add.o sub.o mul.o
target=myapp
#makefile中自己维护的变量
CC = gcc
CPFLAGS = -I
#获取指定路径下的.c文件
src=$(wildcard ./*.c)
obj=$(patsubst ./%.c, ./%.o, $(src))

$(target): $(obj)
	$(CC) $(obj) -o $(target)

#模式规则
# $< 对应规则中的依赖, 即 %.c
# $@ 对应规则中的目标, 即 %.o
%.o: %.c
	$(CC) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(obj) $(target)
