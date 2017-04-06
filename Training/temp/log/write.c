#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int sys_id;
	int log_id;
	FILE *fp;
	int i = 0; 

	char issues[30][30] = {"issue1","issue2","issue3","issue4","issue5","issue6","issue7","issue8","issue9","issue10","issue11","issue12","issue13","issue14","issue15","issue16","issue17","issue18","issue19","issue20","issue21","issue22","issue23","issue24","issue25","issue26","issue27","issue28","issue29","issue30"};

	if(NULL == (fp = fopen("file.log","w"))) {
		printf(".log file not created\n");
		exit(1);
	}	

	for( i = 0 ; i <= 100; i++) { 

		sys_id = (rand() % 30);

		if(sys_id  == 0)
			sys_id++;

		log_id = rand() % 30; 

		fprintf(fp,"Log0%02d,sys_%02d,%d,%s\n" , (log_id + 1) , sys_id , strlen(issues[log_id]) ,issues[log_id]);
	}

	fclose(fp);

	return 0;
} 
