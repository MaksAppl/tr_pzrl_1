#ifndef MODULE_H
#define MODULE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long calc_expression(long long a, char op, long long b);
void decrypt(const long long* results, int count, long long key, char* text);
void print_results(const long long* results, int count, const char* text);

#endif // MODULE_H