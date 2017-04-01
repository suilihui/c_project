#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void test1(int, char**);
void test2(int, char**);
void test3(int, char**);
void test4(int, char**);
void test5(int, char**);
void test6(int, char**);

int main(int argc, char *argv[])
{
	test6(argc, argv);
}

void test1(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("%s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	int ret = chmod(argv[1], 0700);
	if (ret == -1)
	{
		perror("chmod");
		exit(EXIT_FAILURE);
	}
}

void test2(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("a.out filename\n");
		exit(EXIT_FAILURE);
	}

	int ret = access(argv[1], W_OK);
	if (ret == -1)
	{
		perror("access");
		exit(EXIT_FAILURE);
	}
	printf("you can write this file\n");
	exit(EXIT_SUCCESS);
}

void test3(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("%s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	int ret = truncate(argv[1], 100);
	if (ret == -1)
	{
		perror("truncate");
		exit(EXIT_FAILURE);
	}
}

void test4(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("%s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	int ret = link(argv[1], "123");
	if (ret == -1)
	{
		perror("link");
		exit(EXIT_FAILURE);
	}
}

void test5(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("%s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	int ret = symlink(argv[1], "123");
	if (ret == -1)
	{
		perror("symlink");
		exit(EXIT_FAILURE);
	}
}

void test6(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("%s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	char buf[512];
	int ret = readlink(argv[1], buf, sizeof(buf));
	if (ret == -1)
	{
		perror("readlink");
		exit(EXIT_FAILURE);
	}
	printf("buf = %s\n", buf);
}

