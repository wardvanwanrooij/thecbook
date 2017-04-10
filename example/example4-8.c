/*
* Recursive descent parser for simple C expressions.
* Very little error checking.
*/

#include <stdio.h>
#include <stdlib.h>

int expr(void);
int mul_exp(void);
int unary_exp(void);
int primary(void);

main(){
      int val;

      for(;;){
              printf("expression: ");
              val = expr();
              if(getchar() != '\n'){
                      printf("error\n");
                      while(getchar() != '\n')
                              ; /* NULL */
              } else{
                      printf("result is %d\n", val);
              }
      }
      exit(EXIT_SUCCESS);
}

int
expr(void){
      int val, ch_in;

      val = mul_exp();
      for(;;){
              switch(ch_in = getchar()){
              default:
                      ungetc(ch_in,stdin);
                      return(val);
              case '+':
                      val = val + mul_exp();
                      break;
              case '-':
                      val = val - mul_exp();
                      break;
              }
      }
}

int
mul_exp(void){
      int val, ch_in;

      val = unary_exp();
      for(;;){
              switch(ch_in = getchar()){
              default:
                      ungetc(ch_in, stdin);
                      return(val);
              case '*':
                      val = val * unary_exp();
                      break;
              case '/':
                      val = val / unary_exp();
                      break;
              case '%':
                      val = val % unary_exp();
                      break;
              }
      }
}

int
unary_exp(void){
      int val, ch_in;

      switch(ch_in = getchar()){
      default:
              ungetc(ch_in, stdin);
              val = primary();
              break;
      case '+':
              val = unary_exp();
              break;
      case '-':
              val = -unary_exp();
              break;
      }
      return(val);
}

int
primary(void){
      int val, ch_in;

      ch_in = getchar();
      if(ch_in >= '0' && ch_in <= '9'){
              val = ch_in - '0';
              goto out;
      }
      if(ch_in == '('){
              val = expr();
              getchar();      /* skip closing ')' */
              goto out;
      }
      printf("error: primary read %d\n", ch_in);
      exit(EXIT_FAILURE);
out:
      return(val);
}