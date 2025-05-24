#include <stdio.h>

union Data
{
    int i;
    float f;
};

int main()
{
    union Data data;
    data.i = 42;
    printf("Int: %d\n", data.i);
    data.f = 3.14;
    printf("Float: %.2f\n", data.f);

    printf("Int after float assignment: %d\n", data.i);
}