#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>

unsigned int _strlen(char *str);
int _strcmp(char *str1, char *str2);
char *_strncpy(char *dest, char *src, int n);
char *_strdup(char *dest, const char *src, int len);
unsigned int const_strlen(const char *str);

void _getnewline(char *buffer);
int prompt(void);
void _sighandler(int feed);

unsigned int cmd_count(char *str);
char **_getCmdTok(char *str);

void flush_tok_arr(char **ptr);
void _flush_abort(char *buffer, char **cmds);
void _flush_buf(char *buffer);
void _flush_parent(char *buffer, char **cmds);

void _writeEnv(char **env);
void _printEnv(char *buf, char **tok, char **env);

void _searchPath(char **cmds, char *buf, char **env, char **argv, int t);

unsigned int _dirCount(char *p);
char **_readdir(char *cmd_name, char **env);
char *_readEnv(const char *str, char **ev);
char *_catEnvVar(char *dest, char *src, char *cmd, int dest_len, int cmd_len);

void _geterrors(char **argv, char *cmd_name, int tally);
int write_err(char err);

void _perror(void);
#endif
