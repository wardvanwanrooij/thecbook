#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

main(){
        size_t distance;
        struct x{
                int a, b, c;
        }s_tr;

        distance = offsetof(s_tr, c);
        printf("Offset of x.c is %lu bytes\n",
                (unsigned long)distance);

        exit(EXIT_SUCCESS);
}