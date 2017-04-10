#include <stdio.h>
#include <stdlib.h>

int i_var;
void func(void);

main(){
        while(i_var != 10000){
                func();
                i_var++;
        }
        exit(EXIT_SUCCESS);
}

void
func(void){
        printf("in func, i_var is %d\n", i_var);
}