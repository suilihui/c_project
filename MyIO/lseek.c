#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
	int fd, ret;

	fd = open("aa", O_RDWR);
	if (fd == -1) {
		perror("open");
		exit(1);
	}

	ret = lseek(fd, 0, SEEK_END);
	printf("file length = %d\n", ret);

	ret = lseek(fd, 2000, SEEK_END);
	printf("return value %d\n", ret);
	
	write(fd, "\0", 1);

	close(fd);
}
