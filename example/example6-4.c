struct x;       /* incomplete type */

/* valid uses of the tag */
struct x *p, func(void);

void f1(void) {
  struct x{int i;};       /* redeclaration! */
}

/* full declaration now */
struct x {
  float f;
} s_x;

void f2(void) {
  /* valid statements */
  p = &s_x;
  *p = func();
  s_x = func();
}

struct x
func(void) {
  struct x tmp;
  tmp.f = 0;
  return (tmp);
}
