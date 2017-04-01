#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("%s filename\n", argv[0]);
		exit(1);
	}

	struct stat st;
	int ret = stat(argv[1], &st);
	if (ret == -1)
	{
		perror("stat");
		exit(1);
	}
	int size = st.st_size;
	printf("size = %d\n", size);
}
