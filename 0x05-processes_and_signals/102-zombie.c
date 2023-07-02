#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int infinite_while(void);

/**
 * main - This function creates zombie processes
 * Return: This function returns 0
 */
int main(void)
{
	int i = 0;

	while (i < 5)
	{
		pid_t child_pid = fork();

		if (child_pid > 0)
		{
			printf("Zombie process created, PID: %d\n", child_pid);
			sleep(1);
		}

		if (child_pid == 0)
		{
			exit(0);
		}
		i += 1;
	}
	infinite_while();

	return (0);
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
