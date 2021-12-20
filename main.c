#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{
	char name[10], birthday[20],birthday_temp[20],ming_birth[20],years[4],line[100];
	FILE *in,*out;
	char *p;
	int i,j,k,n; 

	printf("please input ming's birthday!\n");
	scanf("%s",ming_birth);
	ming_birth[4]='\0';//¶ÁÈ¡Ð¡Ã÷µÄ³öÉúÄê·Ý 

	in  = fopen("db.in", "r"); 
	out = fopen("db.out", "w");
	
	if (in==NULL)
	{
		printf("Can't open db.in!");
	} 
	
	k= 0;
		
	while(fgets(line, 128, in) != NULL)//¶ÁÈ¡ÎÄ¼þÐÐÊý£¬ÖªµÀÎÄ¼þÖÐÓÐ¼¸¸öÍ¬Ñ§µÄÉúÈÕ 
	{
		i++;
		if(i<3)
			continue;
		//printf("line %d is %s\n", i, line);
		strcpy(name ,strtok(line, " "));
		p = strtok(NULL, " ");
		strcpy(birthday,p);

		strcpy(birthday_temp,birthday);
		birthday[4] = '\0';
		//printf("birthday = %s\n",birthday) ;
		
		if(strcmp(birthday, ming_birth)==0)
		{
			fprintf(out, "%s\n", name);
			printf("name = %s, birthday= %s\n", name, birthday_temp);
			k++;
		}
		i++;
	}

	
	if (k>0)
	{} 
	else
	{
		fprintf(out,"%s","only ming");
	}
	 
}
