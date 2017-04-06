#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LOG 31
#define MIN_LOG 1
#define MIN 0
#define MAX_MSG_SIZE 40
#define MSG_INDEX 7

//structure for each system
struct SrcSystem {
	char *sys_name;
	int log[MAX_LOG];
	struct SrcSystem *next;
}*head = NULL;

//prototypes
FILE *validate_input_file(char *);
int parse_log_msg(char *);
void update_log_count(char *, int);
void print_master_summary();
void print_Invalid_msg_summary(int);
void print_individual_system_summary();

int main (int argc, char *argv[])
{
	FILE *fp;
	char str[40];
	char *sys_name;
	char *ptr;
	char ch;
	int i = 0;
	int j = 0;
	int k = 1;
	int number = 0;
	unsigned short incorrect_msg_count = 0;

	if (argc < 1){
		printf(" No input log files\n");
		exit(EXIT_FAILURE);
	}

	while (k < argc) {

		ptr = argv[k];
		if (NULL == (fp = validate_input_file(ptr))) {
			k++;
			continue;
		}

		while (1) {

			for (i = MIN; (ch = fgetc(fp)) != '\n'; i++) {
				if (feof(fp))
					break;
				str[i] = ch;		//extracting line from file
			}

			if (feof(fp))
				break;

			str[i] = '\0';

			if(NULL == (sys_name = (char *)malloc (sizeof(char) * 10))) {
				perror("malloc failed");
				exit(EXIT_FAILURE);
			}	

			for (i = MSG_INDEX, j = MIN; str[i] != ','; i++, j++)
				sys_name[j] = str[i];	// for system name in message

			sys_name[j] = '\0';

			if (number = parse_log_msg(str)) {
				update_log_count(sys_name, number);
			} else {
				update_log_count(sys_name, MIN);
				incorrect_msg_count++;
			}
		}

		k++;
	}

	print_master_summary();
	print_Invalid_msg_summary(incorrect_msg_count);
	print_individual_system_summary();

	fclose (fp);

	exit(EXIT_SUCCESS);
}

/*	validating input file:
	If input file is Valid file, file position will return.
	If input file is Invalid file, NULL will return.
 */

FILE *validate_input_file(char *ptr)
{
	FILE *fp;
	char *str = ptr;

	while((*ptr != '.') && (*ptr != '\0'))//validate correct input file
		*++ptr;

	if(!((*++ptr == 'l') && (*++ptr == 'o') && (*++ptr == 'g'))){
		printf("Invalid file %s\n", str);
		return NULL;
	}

	if (NULL == (fp = fopen (str, "r+"))) { //open file
		perror("fopen failed");
		exit(EXIT_FAILURE);
	}
	return fp;
}

/*	For detecting errors in message in logfile
	On correct message, return logid
	On Incorrect message, return 0
 */

int parse_log_msg (char *str)
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
	struct SrcSystem *temp1 = NULL;

	temp = head;
	while (temp != NULL) {	//For itiration over list

		if (0 == (strcmp(temp->sys_name,sys))) {
			(temp->log[logid_number])++;	//updating log count
			return;		
		} else {
			temp1 = temp;
			temp = temp->next;
		}
	}

	if(NULL == (new_sys = (struct SrcSystem *) malloc(sizeof (struct SrcSystem)))) {
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}

	//iniliazation for new system
	for (i = MIN; i < MAX_LOG; i++) 
		new_sys->log[i] = 0;

	new_sys->sys_name = sys;
	new_sys->next = NULL;

	if (NULL == head) {
		head = new_sys;
		(head->log[logid_number])++;
	} else {
		(new_sys->log[logid_number])++;
		temp1->next = new_sys;			// adding it to list
	}
}

void print_master_summary()
{
	int i = 0;
	int total = 0;
	struct SrcSystem *temp = NULL;
	int logs[MAX_LOG];

	for (i = MIN_LOG; i <= MAX_LOG; i++) 
		logs[i] = 0; 					//iniliazation of logs array

	logs[MAX_LOG] = 0;
	printf ("\tMaster Summary\n  -----------------------------\n");
	printf ("     LogId | # of msgs\n");
	printf ("  -----------------------------\n");

	for (i = MIN_LOG; i < MAX_LOG; i++) {
		temp = head;
		while (temp != NULL) {
			logs[i] = logs[i] + temp->log[i]; //adding it to array to display summary
			temp = temp->next;
		}
		total = total + logs[i];
		printf ("      Log0%2d | %d\n", i, logs[i]);	
	}

	printf ("\n      Total  | %d \n\n", total);
}

void print_Invalid_msg_summary(int n)
{

	printf ("\tInvalid Log Summary\n  -----------------------------\n");
	printf ("     Total  Invalid Logs | %d\n", n);
	printf ("  -----------------------------\n");

	printf ("\n\n");
}

void print_individual_system_summary()
{
	int i = 0;	
	int j = 1;
	int total = 0;
	struct SrcSystem *temp = NULL;

	temp = head;		//temp node for iteration 
	while(temp != NULL) {
		printf ("\tSummary for: <%s>\n  -----------------------------\n", temp->sys_name);
		printf ("     LogId | # of msgs\n");
		printf ("  -----------------------------\n");

		//printing each system log 
		total = 0;
		for (i = MIN_LOG; i < MAX_LOG; i++) {
			total = total + temp->log[i];
			printf ("      Log0%2d | %d\n", i, temp->log[i]);
		}

		printf ("\n      Total  | %d \n\n", total);

		//printing each system invalid msg count

		printf ("\tInvalid Log Summary for <%s>\n  -----------------------------\n", temp->sys_name);
		printf("     Total  Invalid Logs | %d\n",temp->log[0]);
		printf ("  -----------------------------\n\n\n");

		temp = temp->next;
	}
}
