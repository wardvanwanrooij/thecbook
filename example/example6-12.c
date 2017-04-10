#include <stdio.h>
#include <stdlib.h>

/* code for types in union */
#define FLOAT_TYPE      1
#define CHAR_TYPE       2
#define INT_TYPE        3

struct var_type{
      int type_in_union;
      union{
              float   un_float;
              char    un_char;
              int     un_int;
      }vt_un;
}var_type;

void
print_vt(void){

      switch(var_type.type_in_union){
              default:
                      printf("Unknown type in union\n");
                      break;
              case FLOAT_TYPE:
                      printf("%f\n", var_type.vt_un.un_float);
                      break;
              case CHAR_TYPE:
                      printf("%c\n", var_type.vt_un.un_char);
                      break;
              case INT_TYPE:
                      printf("%d\n", var_type.vt_un.un_int);
                      break;
      }
}

main(){

      var_type.type_in_union = FLOAT_TYPE;
      var_type.vt_un.un_float = 3.5;

      print_vt();

      var_type.type_in_union = CHAR_TYPE;
      var_type.vt_un.un_char = 'a';

      print_vt();
      exit(EXIT_SUCCESS);
}