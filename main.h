#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#define PID "cisfun$ "
char *read_line(void);
int run_command(char **command);
char **divide_line(char *line);
#endif
