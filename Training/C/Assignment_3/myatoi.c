int myatoi(char * str)
{
	int i;
	int num = 0;

	for ( i = 0; str[i] != '\0'; i++) {
		num = num * 10 + (str[i] - '0');			
	}	
	return num;
}



