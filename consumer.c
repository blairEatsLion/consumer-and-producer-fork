
#include <stdio.h>
#include <stdlib.h>



int consumer(){
        char c;
        char turn='1';
        FILE *fpt_1;
        FILE *fpt_2;
        int pos=0;
while(1){
        while((fpt_1=fopen("TURN.txt","r"))==NULL);    //busy loop open turn

        turn=fgetc(fpt_1);      //get 0/1
 fclose(fpt_1);
        if (turn<48||turn>49){
	        printf("ERROR!!! consumer exit, turn char: %c\n",turn);
	 break;
//        exit(1);
        }
//if(turn=='0'){
//        fclose(fpt_1);          //not my turn yield the right back to producer
//	printf("consumer: not my turn, turn char: %c\n",turn);
        if(turn=='0'){
//        fclose(fpt_1);
        }

        if(turn=='1'){
//fclose(fpt_1);
printf("consumer turn.. open DATA.txt\n");

	while((fpt_2=fopen("DATA.txt","r"))==NULL);    //busy loop for DATA.txt try to read single char
printf("consumer: data.txt open successful..\n");
	c=fgetc(fpt_2);
	//make changes
	if(c=='\0'){
		printf("reached the end!!!");
		fclose(fpt_2);
		break;//if EOF, then exit
	}
	putchar(c);

printf("\n");
	fclose(fpt_2);
        pos=pos+1;      

//fclose(fpt_1);
	while((fpt_1=fopen("TURN.txt","r+"))==NULL);    //busy loop for DATA.txt try to read single char
        fputc('0',fpt_1);       //set turn to 0(producer)
        fclose(fpt_1);
printf("consumer set the turn to producer\n");
}

// while(1){
//      do{
//              turn=getenv("TURN");
//      }while(strcmp(turn,"1")!=0)             //keep looping if turn is in producer
//              //do stuff
//              c=getenv("DATA");
//              printf("%s\n", c);
//              setenv("TURN","0",1);
	}

        return 0;

}

