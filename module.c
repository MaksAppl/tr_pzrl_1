#include "module.h"

long long calc_expression(long long a, char op, long long b)
{
    if (op == '+')
        return a + b;
    if (op == '-')
        return a - b;
    if (op == '*')
        return a * b;
    return a % b;
    // ДОБАВИТЬ ОШИБКИИИ
}

void decrypt(const long long* results, int count, long long key, char* text)
{
	// Переводим каждый результат в символ  вычитая ключ
    for (int i = 0; i < count; i++)
        text[i] = (char)(results[i] - key);
    text[count] = '\0';
}

void print_results(const long long* results, int count, const char* text)
{
    for (int i = 0; i < count; i++)
        printf("Ответ №%d: %lld\n", i + 1, results[i]);
    printf("Результирующая строка: %s\n", text);
}