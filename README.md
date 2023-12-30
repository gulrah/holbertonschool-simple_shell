# Simple Shell Project

## Description

This project involves building a simple UNIX command-line interpreter, commonly known as a shell. The shell is designed to execute basic commands and manage functionalities like command-line input, arguments, and built-in commands.

## Learning Objectives

By completing this project, we aim to achieve the following learning objectives:
- Gain insight into the project development process.
- Implement a basic shell to understand its workings.
- Explore the historical background of Unix shells.
- Familiarize ourselves with key figures like Ken Thompson.
- Learn about process handling, environment manipulation, and system calls.

## Table of Contents
- [Concepts](#concepts)
- [Resources](#resources)
- [Learning Objectives](#learning-objectives)
- [Requirements](#requirements)
- [Compilation](#compilation)
- [Testing](#testing)
- [Tasks](#tasks)
- [License](#license)

## Concepts
In this project, you will explore the following concepts:
- Approaching a Project
- UNIX shell
- Thompson shell
- Ken Thompson

## Resources
- [Unix shell](https://en.wikipedia.org/wiki/Unix_shell)
- [Thompson shell](https://en.wikipedia.org/wiki/Thompson_shell)
- [Ken Thompson](https://en.wikipedia.org/wiki/Ken_Thompson)
- [Everything you need to know to start coding your own shell concept page](https://medium.com/@ajtechdeveloper/everything-you-need-to-know-to-start-coding-your-own-shell-5d842b0d7703)

## Learning Objectives
Upon completion of this project, you should be able to:
- Explain the design and implementation of the original Unix operating system.
- Identify the first version of the UNIX shell.
- Understand the connection between the B programming language and the C programming language.
- Describe the role of Ken Thompson in the development of the Unix operating system.
- Comprehend how a shell works.
- Manipulate the environment of the current process.
- Differentiate between a function and a system call.
- Create processes in a Unix environment.
- Understand the three prototypes of the main function.
- Learn how the shell uses the PATH variable to find programs.
- Execute another program with the execve system call.
- Suspend the execution of a process until one of its children terminates.
- Define EOF (end-of-file).

## Requirements
- Allowed editors: vi, vim, emacs
- All files will be compiled on Ubuntu 20.04 LTS using gcc with the options `-Wall -Werror -Wextra -pedantic -std=gnu89`
- All files should end with a new line
- A `README.md` file at the root of the project folder is mandatory
- Code should follow the Betty style
- Shell should not have any memory leaks
- No more than 5 functions per file
- All header files should be include guarded
- Use system calls only when necessary

##List of allowed functions and system calls+
all functions from string.h
access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
_exit (man 2 _exit)
fflush (man 3 fflush)
fork (man 2 fork)
free (man 3 free)
getcwd (man 3 getcwd)
getline (man 3 getline)
getpid (man 2 getpid)
isatty (man 3 isatty)
kill (man 2 kill)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
printf (man 3 printf)
fprintf (man 3 fprintf)
vfprintf (man 3 vfprintf)
sprintf (man 3 sprintf)
putchar (man 3 putchar)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (__xstat) (man 2 stat)
lstat (__lxstat) (man 2 lstat)
fstat (__fxstat) (man 2 fstat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)

Tasks
0. README, man, AUTHORS
Write a README, man, and AUTHORS file for the project.

1. Betty would be proud
Ensure that your code follows the Betty style.

2. Simple shell 0.1
Write a UNIX command-line interpreter that displays a prompt, waits for the user to type a command, and executes the command.

3. Simple shell 0.2
Extend the shell to handle command lines with arguments.

4. Simple shell 0.3
Handle the PATH, ensuring fork is not called if the command doesn't exist.

5. Simple shell 0.4
Implement the exit built-in to exit the shell.

6. Simple shell 1.0
Implement the env built-in, which prints the current environment.