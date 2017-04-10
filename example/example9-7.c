#include <stdio.h>
#include <stdlib.h>

struct xx{
        int xx_int;
        float xx_float;
}ar[20];

main(){

        FILE *fp = fopen("testfile", "w");

        if(fwrite((const void *)ar,
                sizeof(ar[0]), 5, fp) != 5){

                fprintf(stderr,"Error writing\n");
                exit(EXIT_FAILURE);
        }

        rewind(fp);

        if(fread((void *)&ar[10],
                sizeof(ar[0]), 5, fp) != 5){

                if(ferror(fp)){
                        fprintf(stderr,"Error reading\n");
                        exit(EXIT_FAILURE);
                }
                if(feof(fp)){
                        fprintf(stderr,"End of File\n");
                        exit(EXIT_FAILURE);
                }
        }
        exit(EXIT_SUCCESS);
}