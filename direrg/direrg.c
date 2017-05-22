/*
 * direrg.c
 *
 *  Created on: 2017年5月22日
 *      Author: JYS1105
 */

#include "direrg.h"
#include "myLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>


int Vist(void * tch);

int main(int argc, char * argv[])
{
	int Eret = 0;

	char tcwd[1024 * 32];
	int itc = 0;

	if (argv == NULL)
	{
		printf("Error:");
		return -1;
	}

	if (argc == 1)
	{
		itc = 1;
		getcwd(tcwd, sizeof(tcwd));
	}
	else
	{
		itc = argc - 1;
		strcpy(tcwd, argv[itc]);
	}

	do
	{
		printf(".\n");
		myErg(tcwd, (void *)Vist, 1);
		itc++;
	}while(itc < argc);



	return Eret;
}


int Vist(void * tfile)
{
	int Eret = 0;
	struct dirent *myf = tfile;
	if (tfile == NULL)
	{
		return -1;
	}

	printf(" %s\n", myf->d_name);

	return Eret;
}
