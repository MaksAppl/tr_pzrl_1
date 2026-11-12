#include "module.h"

int main(void)
{
    char tok[64];
    long long a, b, key;
    char op;
    int count = 0;
    int capacity = 1;
    long long* results = malloc(capacity * sizeof * results);

    // Считываем выражения до получения флага -k
    while (scanf("%63s", tok) == 1 && strcmp(tok, "-k") != 0) {
        a = atoll(tok);
        scanf(" %c", &op);
        scanf("%lld", &b);
        // Когда требуется увеличиваем вместимость
        if (count == capacity) {
            capacity *= 2;
            results = realloc(results, capacity * sizeof * results);
        }
        // Сразу считаем результат, увеличиваем их счетчик и добавляем рез. в массив
        results[count++] = calc_expression(a, op, b);
    }

    scanf("%lld", &key);

    char* text = malloc(count + 1);
    decrypt(results, count, key, text);
    print_results(results, count, text);
	// Очищаем память, выделенную под массивы
    free(results);
    free(text);
    return 0;
}