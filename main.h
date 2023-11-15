#ifndef MAIN_H
#define MAIN_H

#define PROMPT "simple_shell$ "

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

char *read_input(int argc, char *argv[]);
void execute_command(char *command);
int main(int argc, char *argv[], char *envp[]);
char **handle_arguments(char *command);
void free_arguments(char **args);
char *exe_command_path(char *command);
void print_env(char **envp);

#endif
