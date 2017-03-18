#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE 1024

int main(void)
{
	int fd;
	// 打开已经存在的文件
	/*fd = open("hello.c", O_RDWR);
	if (fd == -1) {
		perror("open file");
		exit(1);
	}
	// 创建新文件
	fd = open("myhello", O_RDWR | O_CREAT, 0777);
	if (fd == -1) {
		perror("open file");
		exit(1);
	}
	printf("fd = %d\n", fd);
	
	
	// 判断文件是否存在
	fd = open("myhello", O_RDWR | O_CREAT | O_EXCL, 0777);
	if (fd == -1) {
		perror("open file");
		exit(1);
	}*/
	
	char buf[SIZE];
	int count;
	fd = open("myhello", O_RDONLY);
	if (fd == -1) {
		perror("open file");
		exit(1);
	}
	printf("fd = %d\n", fd);

	while ((count = read(fd, buf, SIZE)) > 0) {
		write(fileno(stdout), buf, count);
	}

	// 关闭文件
	int ret = close(fd);
	printf("ret = %d\n", ret);
	if (ret == -1) {
		perror("close file");
	}
}

