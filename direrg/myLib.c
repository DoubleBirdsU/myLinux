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


int myErg(void * mydir, Func Vist, int deep)
{
	int Eret = 0;

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
		// 判断是否为目录文件  或 .* 目录
		if (tfile->d_type == 4 || tfile->d_name[0] == '.')
			continue;	// 目录文件

		Space(deep);
		Vist((void *)tfile);
	}

	// 遍历目录
	rewinddir(dirp);
	while ((tfile = readdir(dirp)) != NULL)
	{
		// 判断是否为目录文件  或 .* 目录
		if (tfile->d_type != 4 || tfile->d_name[0] == '.')
			continue;	// 非目录文件或 .* 目录

		Space(deep);
		Vist((void *)tfile);

		memset(tcwd, 0,sizeof(tcwd));
		sprintf(tcwd, "%s/%s", (char *)mydir, tfile->d_name);

		myErg(tcwd, Vist, deep + 1);
	}

End1:
	return Eret;
}



int Ergotic(int argc, char * argv[], Func Vist)
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

		if ((Eret = access(tcwd, F_OK)))
			return Eret;

		do
		{
			printf(".\n");
			myErg(tcwd, Vist, 1);
			itc++;
		}while(itc < argc);

		return Eret;
}

