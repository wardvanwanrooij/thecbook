struct list_ele {
  int data;
  struct list_ele *pointer;
} ar[3];

main() {
  ar[0].data = 5;
  ar[0].pointer = &ar[1];
  ar[1].data = 99;
  ar[1].pointer = &ar[2];
  ar[2].data = -7;
  ar[2].pointer = 0;      /* mark end of list */
  return(0);
}
