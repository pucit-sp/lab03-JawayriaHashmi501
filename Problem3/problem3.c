/*
**	This program is a template for SP lab 3 task 3 you are 
**	required to implement its one function.
*/


#include<stdio.h>
#include<string.h>
#include <stdlib.h>
# define GREP 1
# define REPLACE 2
/*	
**	This function take file pointer as paramter to read content from and 
**	char pointer as an second argument which points to string to search in file
*/
void mygrep(FILE*, char*);

/*	
**	This function take file pointer as paramter to read content from and 
**	char pointer as an second argument which points to string to search in file
** 	and char pointer as an third argument to replace the string finded with it.
*/
void myreplace(FILE *fp,char *find, char * replace);


int  main(int argc,char *argv[])
{

	/*	creating variables	
*/

	int behaviour;
	FILE *fp;
	char *filename=strtok(argv[1]," \0");;
	char *find=strtok(argv[2]," \0");;
	char * replace;
	/*	check if mygrep is called or myreplace	
*/

	char* op=strtok(argv[0]," \0");
	if(strcmp(op,"./mygrep")==0 )
	{
		if(argc != 3)
		{
			printf("usage\t./mygrep %s %s\n",filename,find);
			exit(1);
		}

		behaviour = GREP;
	}
	else if(strcmp(op,"./myreplace")==0 )
	{
		if(argc != 4)
		{
			printf("\t./myreplace filename  <string-to-search> <string-to-replace>");
			exit(1);
		}
		behaviour = REPLACE;
		replace = argv[3];
	}
	else
	{
		behaviour = -1;
	}



	/* opening file	
*/

	fp=fopen(filename,"rt");
	if(fp==NULL)
		printf("Couldn't Open file");

	if(behaviour == GREP)
	{
		mygrep(fp,find);		/*	caling function	
*/
	}
	else if ( behaviour == REPLACE )
	{
		myreplace(fp,find,replace);		/*	calling myreplace	
*/
	}
	
	fclose(fp);		/*	closing file	
*/
	return 0;
}


void mygrep(FILE *fp,char *find)
{
	char c1[500];
	char *line;
	char *str;

	/*	Add code to get strings from file
*/ 
	while(fgets(c1,500,fp))
	{
		if(strstr(c1,find))
			printf("%s",c1);
	}
}





void myreplace(FILE *fp,char *find, char * replace)
{
	char c1[500];
	int flen = strlen(find);
	int flag = 0;
	int found=0;
	int i;
	char *part;
	char ch[]=find[0];
	while(fgets(c1,500,fp))
	{
		/*	Add your code here to search a string find on string c1 readed from file	
*/		
		if(strstr(c1,find))
		{
			
			
		}
	}



}


