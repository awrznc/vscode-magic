#include <stdio.h>
#include <stdlib.h>

typedef signed char INT8;
typedef signed short int INT16;
typedef signed int INT32;
typedef signed long long int INT64;
typedef float FLOAT32;
typedef double FLOAT64;

_Static_assert(sizeof(INT8) == 1, "Expecting 8 bit integers");
_Static_assert(sizeof(INT16) == 2, "Expecting 16 bit integers");
_Static_assert(sizeof(INT32) == 4, "Expecting 32 bit integers");
_Static_assert(sizeof(INT64) == 8, "Expecting 64 bit integers");
_Static_assert(sizeof(FLOAT32) == 4, "Expecting 32 bit floats");
_Static_assert(sizeof(FLOAT64) == 8, "Expecting 64 bit floats");

typedef struct {
    INT8    string_data[4];
    INT8    flag;
    INT8    byte_data;
    INT16   short_data;
    INT32   long_data;
    FLOAT32 float_data;
    INT64   quad_data;
    FLOAT64 double_data;
} Example;

int write_file(char* filename, Example* data) {
    FILE *file = fopen(filename, "wb");

    if ( file == NULL ) {
        printf("error.\n");
        return 0;
    }

    fwrite(data, sizeof(*data), 1, file);
    fclose(file);

    return 1;
}

int main() {

    Example data_1 = { { 'E', 'X', 'P', 'L' }, 1, 2, 3, 4, 5.5, 6, 7.7 };
    write_file("example_1.bin", &data_1);

    Example data_2 = { { 'E', 'X', 'P', 'L' }, 0, 1, 3, 4, 5.5, 6, 7.7 };
    write_file("example_2.bin", &data_2);

    return 0;
}
