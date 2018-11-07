#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

main()
{
	int for_rv;
	printf("before: my pid is %d\n", getpid());
fork_rv=fork();
if(fork_rv==-1)
perror("fork");
else if (fork_rv==0)
printf("i am the child. my pid=%d\n", getpid());
else printf("i am the parent . my child is %d\n", fork_rv);
}
