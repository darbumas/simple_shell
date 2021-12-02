# Simple Shell
===============

## Introduction

This repository is for the simple shell project. In this project, we explore how
a UNIX-like command-line interpreter (or shell) works, and try to
implement a basic version of it.

## Implemented Features

* Interactive and non-interactive modes.
* Interprets basic commands and executes if executables can be found in path.
* Interprets arguments to executable commands.
* Interprets exit, and with status.
* Interprets `Ctrl+c`
* Interprets and executes `env` to print environment variables.

## Development Environment

The simple shell in this repository was built, compiled and tested in a virtual instance using Vagrant - Ubuntu 20.4 LTS.

## Getting Started

Clone the repo

```
https://github.com/darbumas/simple_shell
```

Compilation with flags:

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Example of Output to Expect

* In interactive mode, the shell should work like this
```
~/simple_shell$ ./hsh
($) /bin/ls
README.md      _printEnv.c    _sighandler.c  _strncpy.c       hsh
_dirCount.c    _readEnv.c     _strcmp.c      flush_tok_arr.c  main.c
_geterrors.c   _readdir.c     _strdup.c      header.h      parser.c
_getnewline.c  _searchPath.c  _strlen.c      helper.c      prompt.c
($) exit
~/simple_shell$

```
* In non-interactive mode, shell works like this
```
~/simple_shell$ echo "/bin/ls" | ./hsh
README.md      _printEnv.c    _sighandler.c  _strncpy.c       hsh
_dirCount.c    _readEnv.c     _strcmp.c      flush_tok_arr.c  main.c
_geterrors.c   _readdir.c     _strdup.c      header.h      parser.c
_getnewline.c  _searchPath.c  _strlen.c      helper.c      prompt.c

```
## AUTHORS

* [**Bertrand Bwashi**](https://github.com/darbumas)
* [**Hayden Cooper**](https://github.com/ZugustheDugus)
