/*
 * myLib.h
 *
 *  Created on: 2017年5月22日
 *      Author: JYS1105
 */

#ifndef MYLINUX_DIRERG_MYLIB_H_
#define MYLINUX_DIRERG_MYLIB_H_
#ifdef __cplusplus
extern "C" {
#endif

typedef void * Func(char ch[]);


int Space(int deep);

int getDir(void * mydir);

int isDir(void * mydir);

int myErg(void * mydir, Func Vist, int deep);

#ifdef __cplusplus
}
#endif

#endif /* MYLINUX_DIRERG_MYLIB_H_ */
