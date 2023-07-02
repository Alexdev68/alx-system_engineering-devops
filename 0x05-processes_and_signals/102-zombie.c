#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int infinite_while(void);

/**
 * main - This function creates zombie processes
 */
void main(void)
{
	int i = 0;
	pid_t parentpid = getpid();

	while (i < 5)
	{
		pid_t child_pid = fork();

		if (child_pid > 0)
		{
			printf("Zombie process created, PID: %d\n", parentpid + i + 1);
			sleep(1);
		}

		if (child_pid == 0)
		{
			exit(0);
		}
		i += 1;
	}
	infinite_while();
}

/**
 * infinite_while - This function loops indefinitely
 * Return: This returns an int
 */
int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}
