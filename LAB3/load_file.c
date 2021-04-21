#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "load_file.h"

int* load_file(const char* fName)
{
    int* input;

    input = (int*)malloc(MAX_NUM_ELEMENTS);
    int num_elements = 0;

    FILE* file = fopen(fName, "r");
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (input != NULL)
            input[num_elements++] = atoi(line);
    }
    fclose(file);

    int* data = (int*)malloc((num_elements + 1) * sizeof(int));
    for (int i = 1; i <= num_elements; i++)
    {
        data[i] = input[i - 1];
    }
    if (data != NULL) {
        data[0] = num_elements;
    }
    free(input);
    return data;
}