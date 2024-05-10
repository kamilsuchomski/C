#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/errno.h>

void my_SIGUSR2(int sig){
	printf("Otrzymalem sygnal SIGUSR2 od innego procesu.\n");
}

int main()
{
	pid_t child_pid;

	printf("ID procesu: %d\n", (int) getpid());
	printf("ID procesu rodzica: %d\n", (int) getppid());
	printf("ID rzeczywiste uzytkownika: %d\n", (int) getuid());
	printf("ID efektywne uzytkownika: %d\n", (int) geteuid());
	printf("ID rzeczywiste grupy: %d\n", (int) getgid());
	printf("ID efektywne grupy: %d\n", (int) getegid());

	child_pid = fork();

	if(child_pid != 0)
	{
		printf("Jestm procesem macierzystym.\n");
		printf("Moj PID: %d\n", (int) getpid());
		printf("PID potomka: %d\n", (int) child_pid);
		if(signal(SIGUSR2, my_SIGUSR2) == SIG_ERR){
			printf("Funkcja signal ma problem z SIGUSR2.\n");
			exit(EXIT_FAILURE);
		}

		sleep(15);
		getchar();
	}
	else
	{
		printf("Jestem procesem potomnym.\n");
		printf("Moj PID %d\n", (int) getpid());
		printf("PID rodzica: %d\n", (int) getppid());
		kill(getppid(), SIGUSR2);
		sleep(5);
	}

	return 0;
}