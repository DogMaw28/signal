#include <signal.h>
#include <stdio.h>
#include <error.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	if(signal(SIGCLD,SIG_IGN)==SIG_ERR)
		perror("signal error");
	pid_t pid=fork();
	if(pid<0)
		perror("fork error");
	else if(pid>0)
	{
		printf("%d\n",getpid());
		while(1)
			sleep(1);
	}
	else 
	{
		printf("%d\n",getpid());
	}
	return 0;
}
