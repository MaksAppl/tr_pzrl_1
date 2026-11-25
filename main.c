#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long calc_expression(long long a, char op, long long b)
{
    if (op == '+')
    {
        return a + b;
    }
    if (op == '-')
    {
        return a - b;
    }
    if (op == '*')
    {
        return a * b;
    }
    else
    {
        return a % b;
    }
    // ДОБАВИТЬ ОШИБКИИИ
}

void decrypt(const long long* results, int count, long long key, char* text)
{
    // Переводим каждый результат в символ  вычитая ключ
    for (int i = 0; i < count; i++)
    {
        text[i] = (char)(results[i] - key);
    }
    text[count] = '\0';
}

void print_results(const long long* results, int count, const char* text)
{
    for (int i = 0; i < count; i++)
    {
        printf("Ответ №%d: %lld\n", i + 1, results[i]);
    }
    printf("Результирующая строка: %s\n", text);
}

int main(void)
{
    char tok[64] = "";
    char op_str[8];
    long long a, b, key;
    char op;
    int count = 0;
    int capacity = 1;
    long long* results = malloc(capacity * sizeof * results);

    // Считываем выражения до получения флага -k
    while (scanf("%63s", tok) == 1 && strcmp(tok, "-k") != 0) {
        a = atoll(tok);

        scanf("%7s", op_str);
        if (strchr(op_str, '*') != NULL)
        {
            op = '*';
        }
        else
        {
            op = op_str[0];
        }

        scanf("%lld", &b);
        // Когда требуется увеличиваем вместимость
        if (count == capacity)
        {
            capacity *= 2;
            results = realloc(results, capacity * sizeof * results);
        }
        // Сразу считаем результат, увеличиваем их счетчик и добавляем рез. в массив
        if (op == '+' || op == '-' || op == '*' || op == '%')
        {
            results[count++] = calc_expression(a, op, b);
        }
        else
        {
            printf("Ошибка: неверный знак операции\n");
            free(results);
            return 1;
        }
    }

    if (tok[0] == '\0')
    {
        printf("Ошибка: пустой ввод\n");
        free(results);
        return 1;
    }
    if (strcmp(tok, "-k") != 0)
    {
        printf("Ошибка: не найден флаг -k\n");
        free(results);
        return 1;
    }
    if (count == 0)
    {
        printf("Ошибка: не задано ни одного выражения\n");
        free(results);
        return 1;
    }

    // Читаем ключ как слово и проверяем, что оно целиком является числом
    char* end;
    if (scanf("%63s", tok) != 1)
    {
        printf("Ошибка: после -k не передан ключ\n");
        free(results);
        return 1;
    }
    key = strtoll(tok, &end, 10);
    if (end == tok || *end != '\0')
    {
        printf("Ошибка: ключ '%s' не является числом\n", tok);
        free(results);
        return 1;
    }

    char* text = malloc(count + 1);
    decrypt(results, count, key, text);
    print_results(results, count, text);
    // Очищаем память, выделенную под массивы
    free(results);
    free(text);
    return 0;
}