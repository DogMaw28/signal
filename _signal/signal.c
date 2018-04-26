#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>

static void sig_usr(int);
typedef void (*signalhand_t)(int);

int main(void)
{
	signalhand_t old;
	if((old =signal(SIGUSR1,sig_usr))==SIG_ERR)
		perror("can't catch SIGUSR1");

	if(signal(SIGUSR2,old)==SIG_ERR)	
		perror("cant catch SIGUSR2");
	for(;;)
		usleep(10000);
	return 0;
}

static void sig_usr(int signo)
{

	if(signo == SIGUSR1)
		printf("received SIGUSR1\n");
	else if(signo == SIGUSR2)
		printf("received SIGUSR2\n");
	else
		printf("received signal %d\n",signo);
}

