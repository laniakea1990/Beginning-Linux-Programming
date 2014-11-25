/*************************************************************************
    > File Name: getchoice.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 22 Oct 2014 05:26:42 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

char *menu[] = {
	"a - add new record",
	"d - delete record",
	"q - quit",
	NULL,
};

int getchoice(char *greet, char *choices[]);

int main()
{
	int choice = 0;

	do
	{
		choice = getchoice("Please select an action", menu);
		printf("You have chosen: %c\n", choice);
	}while(choice != 'q');
	exit(0);
}

int getchoice(char *greet, char *choices[])
{
	int chosen = 0;
	int selected;
	char **option;
	do
	{
		printf("Choice: %s\n", greet);
		option = choices;
		while(*option)
		{
			printf("%s\n", *option);
			option++;
		}
		option = choices;
		selected = getchar();
		while(*option)
		{
			if(selected == *option[0])
			{
				chosen = 1;
				break;
			}
			option++;
		}
		if(!chosen)
		{
			printf("Incorrect choice, select again\n");
		}

	selected = getchar();
	}while(selected == '\n');
	return selected;
}
