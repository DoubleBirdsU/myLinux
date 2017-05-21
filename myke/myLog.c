/*
 * myLog.c
 *
 *  Created on: 2017年5月17日
 *      Author: JYS1105
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

static int Len = 128;


// 获取时间信息
void logTime(char * log)
{
	time_t tDate;
	struct tm * eventTime;
	time(&tDate);	// 得到系统当前时间
	eventTime = localtime(&tDate);	// 将time
	int iYear	= eventTime->tm_year + 1900;
	int iMon	= eventTime->tm_mon + 1;
	int iDay	= eventTime->tm_mday;
	int iHour	= eventTime->tm_hour;
	int iMin	= eventTime->tm_min;
	int iSec	= eventTime->tm_sec;

	char sDate[Len];
	sprintf(sDate, "%04d-%02d-%02d", iYear, iMon, iDay);
	char sTime[Len];
	sprintf(sTime, "%02d:%02d:%02d", iHour, iMin, iSec);

	sprintf(log, "%s %s\n", sDate, sTime);

	return;
}


// 获取当前文件夹名称
int getEC(char * tch)
{
	int Eret = 0;
	int iCwd = 0;
	char mycwd[Len * Len];

	getcwd(mycwd, sizeof(mycwd));
	iCwd = strlen(mycwd);
	if (mycwd == NULL)
	{
		Eret = -1;
		printf("func getEC() err:  line: %d\n", __LINE__ - 3);
		return Eret;
	}

	while (mycwd[--iCwd] != '/' && iCwd > 0);
	strcpy(tch, &mycwd[iCwd + 1]);

	return Eret;
}


// 输出错误信息
int orderrlog(char * log, int arg, char * argv[])
{
	int Eret = 0;
	int iArg = 0;
	char tLog[4 * Len * Len];

	if (argv == NULL)
	{
		Eret = -1;
		printf("func orderrlog() error: if (argv == NULL)");
		return Eret;
	}

	memset(tLog, 0, sizeof(tLog));
	sprintf(tLog, "Error: \"myke");
	for (iArg = 1; iArg < arg; iArg++)
	{
		sprintf(&tLog[strlen(tLog)], " %s", argv[iArg]);
	}
	sprintf(&tLog[strlen(tLog)], "\" command not found");

	if (log == NULL)
	{
		printf("%s\n", tLog);
		return Eret;
	}

	strcpy(log, tLog);

	return Eret;
}


void helplog()
{
	printf("Usage: myke [options] [target] ...\n\
Options:\n  -b\t\t\tRename old-makefile as \"makefile.bak\"\
\n  -m\t\t\tStart making this makefile\n");
	return;
}
