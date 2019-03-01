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

	printf("Start %i %s %s %s",argc,argv[0],argv[1],argv[2]);

	/*	creating variables	
*/

	int behaviour;
	FILE *fp;
	char *filename=strtok(argv[1]," \0");;
	char *find=strtok(argv[2]," \0");;
	char * replace;

	/*	check if mygrep is called or myreplace	
*/

	printf("\n%i\n",strcmp(argv[1],"./mygrep"));
	char* op=strtok(argv[0]," \0");
	printf("%s %li %li",op,strlen(op),strlen(argv[0]));
	if(strcmp(op,"./mygrep")==0 )
	{
	//	if(argc != 3)
	//	{-
			printf("usage\t./mygrep %s %s\n",filename,find);
	//		exit(1);
	//	}

		behaviour = GREP;
		printf("behaviour %i\n",behaviour);
	}
	else if(strcmp(argv[1],"./myreplace")==0 )
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
	printf("Here\n");

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


	while(fgets(c1,500,fp))
	{
		printf("%s",c1);
		/*	Add your code here to search a string find on string c1 readed from file	
*/
//		if(/*	found the string 	*/)
//		{
			/*	replace the finded string with replace string	*/
//		}
	}



}


