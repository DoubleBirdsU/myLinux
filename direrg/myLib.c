/*
 * myLib.c
 *
 *  Created on: 2017年5月22日
 *      Author: JYS1105
 */


#include "myLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>



int Space(int deep)
{
	int idp = 0;

	while(++idp < deep)
		printf("    ");

	printf("|——", (char)192, (char)196);
	return 0;
}

int getDir(void * mydir)
{
	int Eret = 0;
	char mycwd[1024*32];
	getcwd(mycwd, sizeof(mycwd));

	strcpy(mydir, mycwd);

	return Eret;
}

int isDir(void * mydir)
{
	int Eret = 0;

	char * tch = mydir;

	Eret = access(tch, F_OK);

	return Eret;
}

int myErg(void * mydir, Func Vist, int deep)
{
	int Eret = 0;
	DIR * dirp = NULL;
	struct dirent * tfile;

	if (mydir == NULL)
	{
		printf("Error: myErg() -> if (mydir == NULL)");

		return -1;
	}

	dirp = opendir(mydir);

	while ((tfile = readdir(dirp)) != NULL)
	{
		if (tfile->d_type != 4)
		{
			Space(deep);
			Vist((void *)tfile);
		}
	}

	rewinddir(dirp);
	while ((tfile = readdir(dirp)) != NULL)
	{
		if (tfile->d_type == 4)
			if (strcmp(tfile->d_name, ".") != 0 && strcmp(tfile->d_name, "..") != 0)
			{
				Space(deep);
				Vist((void *)tfile);

				deep++;
				myErg(tfile->d_name, Vist, deep);
				deep--;
			}
	}

	return Eret;
}
