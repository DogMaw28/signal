#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>


void pr_mask(const char *str)
{

	sigset_t sigset;

	if(sigprocmask(0,NULL,&sigset)<0){
		perror("sigprocmask error");
	}else{
		printf("%s",str);
		if(sigismember(&sigset,SIGQUIT))
			printf(" SIGQUIT");
		if(sigismember(&sigset,SIGINT))
			printf(" SIGINT");
		if(sigismember(&sigset,SIGUSR1))
			printf(" SIGUSR1");
		if(sigismember(&sigset,SIGALRM))
			printf(" SIGALRM");
	printf("\n");
	}
}
