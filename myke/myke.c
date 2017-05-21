/*
 * myke.c
 *
 *  Created on: 2017年5月17日
 *      Author: JYS1105
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myMake.h"
#include "myke.h"
#include "myLog.h"
#include "myOrder.h"


/*
 * 目标：能够自动生成 makefile 文件（该目标为方向目标）
 *
 *
 */
static int Len = 1024 * 64;

//int Analyse(int arg, char *argv[]);

int main(int arg, char * argv[])
{
	int Eret = 0;

	Analyse(arg, argv);

	return Eret;
}

// 解析函数
int Analyse(int arg, char *argv[])
{
	int Eret = 0;
	char log[Len];

	memset(log, '\0', sizeof(log));

	if (arg >=2 && argv[1][0] == '-')
	{
		myOrder(arg, argv);

		return Eret;
	}

	Eret = myMakefile(arg, argv);
	if (Eret != 0)
	{
		printf("Error: Creating makefile is failed!\n");
		return Eret;
	}

	printf("Success: Creating makefile is successful!\n");

	return Eret;
}


