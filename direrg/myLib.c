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

	printf("|——");
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

	int ict = 0;
	DIR * dirp = NULL;
	char tcwd[1024 * 32];
	struct dirent * tfile;

	if (mydir == NULL)
	{
		printf("Error: myErg() -> if (mydir == NULL)");

		return -1;
	}

	dirp = opendir(mydir);
	if (dirp == NULL)
	{
		goto End1;
	}

	// 遍历文件
	while ((tfile = readdir(dirp)) != NULL)
	{
		if (tfile->d_name[0] != '.')
		{
			ict++;
			if (tfile->d_type != 4)
			{
				Space(deep);
				Vist((void *)tfile);
			}
		}
	}

	// 遍历目录
	rewinddir(dirp);
	while ((tfile = readdir(dirp)) != NULL)
	{
		if (tfile->d_name[0] != '.')
			if (tfile->d_type == 4)
			{
				Space(deep);
				Vist((void *)tfile);

				memset(tcwd, 0,sizeof(tcwd));
				sprintf(tcwd, "%s/%s", (char *)mydir, tfile->d_name);

				myErg(tcwd, Vist, deep + 1);
			}
	}

End1:
	return Eret;
}
