
#include <stdio.h>
#include <stdlib.h>



int consumer(){
        char c;
        char turn='1';
        FILE *fpt_1;
        FILE *fpt_2;
       
	while(1){
        	while((fpt_1=fopen("TURN.txt","r"))==NULL);    //busy loop open turn

        	turn=fgetc(fpt_1);      //get 0/1
 		fclose(fpt_1);
        	if (turn<48||turn>49){
//	        printf("ERROR!!! consumer exit, turn char: %c\n",turn);
	 	break;
        	}

//	printf("consumer: not my turn, turn char: %c\n",turn);
		if(turn=='0'){
		}

		if(turn=='1'){

			while((fpt_2=fopen("DATA.txt","r"))==NULL);    //busy loop for DATA.txt try to read single 

//printf("consumer: data.txt open successful..\n");
			c=fgetc(fpt_2);

			if(c=='\0'){
		//		printf("reached the end!!!");
				fclose(fpt_2);
				break;//if EOF, then exit
			}
			putchar(c);

//printf("\n");
			fclose(fpt_2);
		  

			while((fpt_1=fopen("TURN.txt","r+"))==NULL);    //busy loop for DATA.txt try to read single char
			fputc('0',fpt_1);       //set turn to 0(producer)
			fclose(fpt_1);
//printf("consumer set the turn to producer\n");
		}

	}

        return 0;

}

