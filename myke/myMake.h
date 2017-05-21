/*
 * myMake.h
 *
 *  Created on: 2017年5月18日
 *      Author: JYS1105
 */

#ifndef MYMAKE_H_
#define MYMAKE_H_
#ifdef __cplusplus
extern "C" {
#endif

	int myFileComments(void * myfile);

	int getArgv(void * myfile, int arg, char * argv[]);

	int myFile(void * myfile, int arg, char * argv[]);

	int myMakefile(int arg, char * argv[]);

#ifdef __cplusplus
}
#endif

#endif /* MYMAKE_H_ */
