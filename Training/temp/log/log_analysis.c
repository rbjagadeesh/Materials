#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LOG 31
#define MIN_LOG 1
#define MAX_MSG_SIZE 40
#define MSG_INDEX 7

typedef char LogId;

//structure for each system
struct SrcSystem {
	char *sys_name;
	int log[MAX_LOG];
	struct SrcSystem *next;
}*head = NULL;

//prototypes
int read_log_msg(char *);
void update_log_count(char *, int);
void print_master_summary();
void print_Invalid_msg_summary(int);
void print_individual_system_summary(int []);

int main (int argc, char *argv[])
{
	FILE *fp;
	FILE *fp1;
	char str[MAX_MSG_SIZE];
	char *sys_name;
	char *arg[10];
	char ch;
	int incorrect_msg_cnt[MAX_LOG];
	int i = 0;
	int j = 0;
	int number = 0;
	unsigned short incorrect_msg_count = 0;

    if ( argc < 2 ){
        printf(" No input log files\n");
		exit(EXIT_FAILURE);

    } else {

		if(NULL == (fp1 = fopen("final_logs", "a"))){
			printf("fopen final_logs ");
			exit(EXIT_FAILURE);
       	}

        for (i = 1; i < argc; i++){
            arg[i] = argv[i];

            while((*arg[i] != '.') && (*arg[i] != '\0'))//validate correct input file
                *++arg[i];

            if( (*++arg[i] == 'l') && (*++arg[i] == 'o') && (*++arg[i] == 'g')){
                printf("Valid file\n");
                if(NULL == (fp = fopen(argv[i], "r+"))){
                    perror("fopen failed");
					exit(EXIT_FAILURE);
                }
                while((ch = fgetc(fp)) != EOF){
                    fputc(ch, fp1);
                }
			}
		}
	}

	if (NULL == (fp = fopen ("final_logs", "r+"))) { //open file
		perror("fopen failed");
		exit(EXIT_FAILURE);
	}

	for (i = MIN_LOG; i <= MAX_LOG; i++) //initializing incorrect msg counter for individual system with 0 
		incorrect_msg_cnt[i] = 0;

	while (1) {

		if(NULL == (sys_name = (char *)malloc (sizeof(char) * 10))) {
        	perror("malloc failed");
        	exit(EXIT_FAILURE);
		}	

		for (i = 0; (ch = fgetc(fp)) != '\n'; i++) {
			if (feof(fp))
				break;
			str[i] = ch;		//extracting line from file
		}

		if (feof(fp))
			break;

		str[i] = '\0';
		for (i = MSG_INDEX, j = 0; str[i] != ','; i++, j++)
			sys_name[j] = str[i];	// for system name in message

		sys_name[j] = '\0';

		if (number = read_log_msg(str)) {
			update_log_count(sys_name, number);
		} else {
			number = 0;
			number = (sys_name[j-2] - '0');
			number = (number * 10 + (sys_name[j-1] - '0'));
			incorrect_msg_cnt[number]++;	//updating count
			
			incorrect_msg_count++;
		}
	}

	print_master_summary();
	print_Invalid_msg_summary(incorrect_msg_count);
	print_individual_system_summary(incorrect_msg_cnt);

	fclose (fp);
	fclose (fp1);

	exit(EXIT_SUCCESS);
}

/*	For detecting errors in message in logfile
	On correct message, return logid
	On Incorrect message, return 0
*/

int read_log_msg (char *str)
{
	char *ptr;
	char *substr;
	unsigned short int num;
	unsigned short int count = 0;
	int i = 0;

	ptr = strtok(str, ",");

//for checking incorrect LogId
	if (NULL == (substr = strstr(str, "Log0"))) 
		return 0;

	num = ptr[4] - '0';

	if((num >= 0) && (num < 3)) {
		;
	} else if((num == 3) && ((ptr[5] - '0') == 0)) {
		;
	} else {
		return 0;
	}

	num = ((num * 10) + (ptr[5] - '0'));

//for checking incorrect message length

	while (NULL != ptr) {

		count++;
		if (count == 3) {
			count = atoi(ptr);
			if (count > 0 && count <= 20)
				return num;
		}
		ptr = strtok(NULL, ",");		//parse log message 
	}

	return 0;
}

void update_log_count(char *sys, int logid_number)
{
	int i;
	struct SrcSystem *new_sys = NULL;
	struct SrcSystem *temp = NULL;

	if(NULL == (temp = (struct SrcSystem *) malloc(sizeof (struct SrcSystem)))) {
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}

	if (NULL == head) {
		;
	} else {
		temp = head;
		while (temp->next != NULL) {	//For itiration over list
			
			if (0 == (strcmp(temp->sys_name,sys))) {
				(temp->log[logid_number])++;	//updating log count
				return;		
			} else {
				temp = temp->next;
				if (temp == NULL) 
					break;
			}
		}
		if (head->next == NULL) {
			if (0 == (strcmp(temp->sys_name,sys))) {
				(temp->log[logid_number])++;
				return;		
			}
		}
	}

	if(NULL == (new_sys = (struct SrcSystem *) malloc(sizeof (struct SrcSystem)))) {
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}

//iniliazation for new system
	for (i = MIN_LOG; i <= MAX_LOG; i++) 
		new_sys->log[i] = 0;

	new_sys->log[MAX_LOG] = 0;
	new_sys->sys_name = sys;
	new_sys->next = NULL;

	if (NULL == head) {
		head = new_sys;
		(head->log[logid_number])++;
		head->next = NULL;
	} else {
		(new_sys->log[logid_number])++;
		temp->next = new_sys;			// adding it to list
	}
}

void print_master_summary()
{
	int i = 0;
	int total = 0;
	struct SrcSystem *temp = NULL;
	int logs[MAX_LOG];

	if(NULL == (temp = (struct SrcSystem *) malloc(sizeof (struct SrcSystem)))) {
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}

	for (i = MIN_LOG; i <= MAX_LOG; i++) 
		logs[i] = 0; 					//iniliazation of logs array

	logs[MAX_LOG] = 0;
	printf ("\tMaster Summary\n  -----------------------------\n");
	printf ("     LogId | # of msgs\n");
	printf ("  -----------------------------\n");

	for (i = MIN_LOG; i <= MAX_LOG; i++) {
		temp = head;
		while (temp != NULL) {
			logs[i] = logs[i] + temp->log[i]; //adding it to array to display summary
			temp = temp->next;
		}
	}

	for (i = MIN_LOG; i <= MAX_LOG - 1; i++) {
		total = total + logs[i];
		printf ("      Log0%2d | %d\n", i, logs[i]);
	}

	printf ("\n      Total  | %d \n\n", total);

	free(temp);
}

void print_Invalid_msg_summary(int n)
{

	printf ("\tInvalid Log Summary\n  -----------------------------\n");
	printf ("     Total  Invalid Logs | %d\n", n);
	printf ("  -----------------------------\n");

	printf ("\n\n");
}

void print_individual_system_summary(int incorrect_msg_cnt [])
{
	int i = 0;	
	int j = 1;
	int total = 0;
	struct SrcSystem *temp = NULL;

	if(NULL == (temp = (struct SrcSystem *) malloc(sizeof (struct SrcSystem)))) {
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}

	temp = head;		//temp node for iteration 
	while(temp != NULL) {
		printf ("\tSummary for: <%s>\n  -----------------------------\n", temp->sys_name);
		printf ("     LogId | # of msgs\n");
		printf ("  -----------------------------\n");

//printing each system log 

		for (i = MIN_LOG; i <= MAX_LOG - 1; i++) {
			total = total + temp->log[i];
			printf ("      Log0%2d | %d\n", i, temp->log[i]);
		}

		printf ("\n      Total  | %d \n\n", total);

//printing each system invalid msg count

		printf ("\tInvalid Log Summary for <%s>\n  -----------------------------\n", temp->sys_name);
		printf("     Total  Invalid Logs | %d\n", incorrect_msg_cnt[j]);
		printf ("  -----------------------------\n");
	
		printf ("\n\n");

		if (j < MAX_LOG)
			j++;

		temp = temp->next;
	}

	free(temp);
}
