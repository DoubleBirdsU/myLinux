/*
 * myMake.c
 *
 *  Created on: 2017年5月18日
 *      Author: JYS1105
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include "myLog.h"
#include "myMake.h"

static int Len = 1024;

// 写入文件头信息
int myFileComments(void * myf)
{
	int Eret = 0;
	char myC[Len * 2];
	FILE * myfile = myf;

	if (myfile == NULL)
	{
		Eret = -1;
		printf("func myFileComments() error: if (myfile == NULL)  line: %d", __LINE__ - 3);
		return Eret;
	}

	// 写入文件名及创建的时间
	strcpy(myC, "#\n# makefile\n#\n# Created on: ");
	logTime(&myC[strlen(myC)]);

	// 写入作者
	strcpy(&myC[strlen(myC)], "#     Author: \n#\n\n");
	fwrite(myC, 1, strlen(myC), myfile);

	return Eret;
}


// 解析输入参数及写入变量值
int getArgv(void * myf, int arg, char * argv[])
{
	/*
	 * 参数说明：
	 * 1	SFMT	CC
	 *
	 * 2	EXEX	默认为myke所在文件的名称
	 *
	 * 3	CWD		目前不使用
	 */
	int Eret = 0;
	FILE * myfile = myf;
	char mySFMT[32] = ".c";
	char myOBMT[32] = ".o";
	char myCC[32] = "gcc";
	char myEXEC[256];
	char myC[Len*8];

	memset(myEXEC, '\0', sizeof(myEXEC));
	memset(myC, '\0', sizeof(myC));

	// 输入参数过多
	if (arg > 3)
	{
		Eret = -1;
		return Eret;
	}


	if (arg == 3 && strcmp(argv[2], "cpp") == 0)
	{
		sprintf(mySFMT, ".cpp");
		sprintf(myCC, "g++");
	}

	// 根据输入参数个数设定变量的值
	if (arg >= 2)
	{
		strcpy(myEXEC, argv[1]);
	}
	else
	{
		getEC(myEXEC);
	}

	// 写入编译格式及信息
	sprintf(myC, "SFMT=%s\n\nOBMT=%s\n\nCC=%s\n\n", mySFMT, myOBMT, myCC);
	fwrite(myC, 1, strlen(myC), myfile);

	// 写入程序名称
	sprintf(myC, "SRCS=$(wildcard *$(SFMT))\n\nEXEC=%s\n\n", myEXEC);
	fwrite(myC, 1, strlen(myC), myfile);

	return Eret;
}


// 写入makefile内容
int myFile(void * myf, int arg, char * argv[])
{
	int Eret = 0;
	FILE * myfile = myf;
	char myStc[] =
			".SUFFIXES:$(SFMT) $(OBMT)\n\nOBJS=$(SRCS:$(SFMT)=$(OBMT))\n\n\
OBJSWP=$(SRCS:$(SFMT)=$(OBMT).swp)\n\nstart: $(OBJS)\n\t$(CC) -o $(EXEC) $(OBJS)\n\
\t@echo '------OK------'\n\n$(SFMT)$(OBMT):\n\t$(CC) -Wall -g -o $@ -c $<\n\n\
.PHONY:clean\n\nclean:\n\trm -f $(OBJS)\n\trm -f core*\n\ncleswp:\n\trm -f $(OBJSWP)\n\n";

	if (myfile == NULL)
	{
		Eret = -1;
		printf("func myFile() error: if (myfile == NULL)  line: %d",
				__LINE__ - 3);
		return Eret;
	}

	// 写入模板变量部分
	Eret = getArgv(myfile, arg, argv);
	if (Eret == 1)
	{
		return Eret;
	}

	// 写入模板固定部分
	fwrite(myStc, 1, strlen(myStc), myfile);

	return Eret;
}

// makefile
int myMakefile(int arg, char * argv[])
{
	int Eret = 0;
	char fname[] = "makefile";
	FILE *tfile = NULL;

	// 将原文件重命名为 makefile.bak
	if (access(fname, 0) == 0)
	{
		rename(fname, "makefile.bak");
	}

	tfile = fopen(fname, "a+");
	if (tfile == NULL)
	{
		Eret = -1;
		printf("func myMakefile() error: if (tfile == NULL)  line: %d",
				__LINE__ - 3);
		return Eret;
	}

	// FileComments：清理已存在的makefile文件内容
	myFileComments(tfile);

	// Auto-makefile
	Eret = myFile(tfile, arg, argv);
	fclose(tfile);

	return Eret;
}

