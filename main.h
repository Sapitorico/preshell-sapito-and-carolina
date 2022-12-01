#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#define PID "cisfun$ "
#include <sys/stat.h>
char *read_line(void);
int run_command(char **command);
char **divide_line(char *line);
char **_path(char **command);
#endif
