/*
 * myLog.h
 *
 *  Created on: 2017年5月17日
 *      Author: JYS1105
 */

#ifndef MYLOG_H_
#define MYLOG_H_
#ifdef __cplusplus
extern "C" {
#endif

	void logTime(char *log);

	int getEC(char * tch);

	int orderrlog(char * log, int arg, char * argv[]);

	void helplog();

#ifdef __cplusplus
}
#endif

#endif /* MYLOG_H_ */
