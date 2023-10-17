#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _printf(const char *format, ...);
int putstr(char *str);
void printc(char c);
static void print_int(int num, int *length);
#endif
