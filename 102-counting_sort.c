#include "sort.h"

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void counting_sort(int *array, size_t size) {
    int i, max = 0, *count, *output;

    if (array == NULL || size < 2)
        return;

    output = malloc(sizeof(int) * size);
    if (output == NULL)
        return;

    for (i = 0; i < (int)size; i++)
        if (array[i] > max)
            max = array[i];

    count = malloc(sizeof(int) * (max + 1));
    if (count == NULL) {
        free(output);
        return;
    }

    for (i = 0; i <= max; i++)
        count[i] = 0;

    for (i = 0; i < (int)size; i++)
        count[array[i]] += 1;

    for (i = 1; i <= max; i++)
        count[i] += count[i - 1];

    print_array(count, max + 1);

    for (i = 0; i < (int)size; i++) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]] -= 1;
    }

    for (i = 0; i < (int)size; i++)
        array[i] = output[i];

    free(count);
    free(output);
}
