#include <stdio.h>
#include <stdlib.h>

int producer(){
	FILE *t_fpt;
	FILE *d_fpt;
	FILE *m_fpt;
	char turn='0';
	char read=' ';
	int pos=0;
	//const pos=0;


	m_fpt=fopen("mydata.txt","r");	//first open the file to read
	if(m_fpt==NULL) exit(1);



	while(read!=EOF){ 

		while((t_fpt=fopen("TURN.txt","r+"))==NULL);
		

		turn=fgetc(t_fpt);
//	printf("opened TURN.txt: %c",turn);
		fclose(t_fpt);

		if (turn<'0'&&turn>'1')
		{
			printf("producer in exit turn is:%c",turn);
			exit(1);
		}

		if(turn=='0'){
//				printf("producer turn\n");
			
				//write to data before write to turn
			while((d_fpt=fopen("DATA.txt","w+"))==NULL);
			read = fgetc(m_fpt);		//get the char from mydata.txt
//adding = EOF condition
			if(read!=EOF){
				fputc(read,d_fpt);
			}		
//				fclose(d_fpt);	//close data.txt

			if(read==EOF){
				fputc('\0',d_fpt);
			}		
			fclose(d_fpt);
		
			while((t_fpt=fopen("TURN.txt","r+"))==NULL);

			fputc('1',t_fpt);
//				printf("now turn is set to 1 consumer\n");
			fclose(t_fpt);

			
		}
	}


//read is updated through fgetc
//terminate the program

	exit(0); 


	fclose(m_fpt);
	return 0;
}

