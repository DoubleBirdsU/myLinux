/*
 * direrg.c
 *
 *  Created on: 2017年5月22日
 *      Author: JYS1105
 */

#include "myLib.h"
#include <stdio.h>
#include <dirent.h>

int Vist(void * tfile)
{
	int Eret = 0;
	struct dirent *myf = tfile;

	printf("%s\n", myf->d_name);

	return Eret;
}

int main(int argc, char * argv[])
{
	int Eret = 0;

	Eret = Ergotic(argc, argv, (void *)Vist);

	return Eret;
}

