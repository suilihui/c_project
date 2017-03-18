#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MODE S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP
#define BUFSIZE 2048

int main()
{
	// 打开一个已经存在的文件
	int fd, fd1, count, ret;
	char buf[BUFSIZE];

	fd = open("english.txt", O_RDONLY);
	if (fd == -1) {
		perror("open");
		exit(1);
	}
	fd1 = open("newfile", O_CREAT | O_WRONLY, MODE);
	if (fd1 == -1) {
		perror("open1");
		exit(1);
	}

	while ((count = read(fd, buf, BUFSIZE)) > 0) {
		ret = write(fd1, buf, count);
		printf("write byte %d\n", ret);
	}

	close(fd);
	close(fd1);
}
