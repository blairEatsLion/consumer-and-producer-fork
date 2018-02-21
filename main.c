//Partner: Jingyi He 260678541

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int producer();
int consumer();


int main(){


	FILE *fpt=fopen("TURN.txt","w+");
	char read;

	if(fpt==NULL) exit(1);
    
	fputc('0',fpt);
	fclose(fpt);


	int pid;
	pid=fork();
	if(pid<0) exit(1); 
	if(pid>0)       //parent
	{
                producer(); 
                wait(NULL);
        }
    	if(pid==0)      //forked child
        {
            wait(NULL);
            consumer();
        } 

    return 0;
}
