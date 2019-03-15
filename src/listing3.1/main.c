#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	printf("The process ID is %d\n", (int)getpid());
	printf("The parent process ID is %d\n", (int)getppid());
	return 0;
}