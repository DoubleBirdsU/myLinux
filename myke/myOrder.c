/*
 * myAnalyse.c
 *
 *  Created on: 2017年5月19日
 *      Author: JYS1105
 */

#include "myMake.h"
#include "myLog.h"
#include "myOrder.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int Len = 1024;
// 命令函数
void myOrder(int arg, char * argv[])
{
	char tch[Len * 32];

	if (strcmp(argv[1], "-mf") == 0)
	{
		if (arg == 2)
		{
			system("cat makefile");
			return;
		}
		printf("Error! myke -mf ~\n");
	}
	else if(strcmp(argv[1], "-m") == 0)
	{
		if (arg == 2)
		{
			system("make");
			return;
		}
		printf("Error! myke -m ~\n");
	}
	else if (strcmp(argv[1], "-r") == 0)
	{
		if(arg == 2)
		{
			system("rm -f makefile");
			return;
		}
		printf("Error! myke -dm ~\n");
	}
	else if (strcmp(argv[1], "-rb") == 0)
	{
		if(arg == 2)
		{
			system("rm -f makefile.bak");
			return;
		}
		printf("Error! myke -rb ~\n");
	}
	else if (strcmp(argv[1], "-c") == 0)
	{
		if(arg == 2)
		{
			system("cat makefile");
			return;
		}
		printf("Error! myke -c ~\n");

	}
	else if (strcmp(argv[1], "-cb") == 0)
	{
		if(arg == 2)
		{
			system("cat makefile.bak");
			return;
		}
		printf("Error! myke -cb ~\n");

	}
	else if (strcmp(argv[1], "-lp") == 0)
	{
		if (arg == 2)
		{
			sprintf(tch, "myke ");

			getEC(&tch[strlen(tch)]);

			sprintf(&tch[strlen(tch)], " cpp");

			system(tch);
			return;
		}
		printf("Error! myke -lp ~\n");

	}
	else
	{
		helplog();
	}

	return;
}



