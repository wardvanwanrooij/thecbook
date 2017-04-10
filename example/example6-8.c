#include <stdio.h>
#include <stdlib.h>
struct tree_node{
      int data;
      struct tree_node *left_p, *right_p;
}tree[7];
/*
* Tree search algorithm.
* Searches for value 'v' in tree,
* returns pointer to first node found containing
* the value otherwise 0.
*/
struct tree_node *
t_search(struct tree_node *root, int v){

      while(root){
              if(root->data == v)
                      return(root);
              if(root->data > v)
                      root = root->left_p;
              else
                      root = root->right_p;
      }
      /* value not found, no tree left */
      return(0);
}

main(){
      /* construct tree by hand */
      struct tree_node *tp, *root_p;
      int i;
      for(i = 0; i < 7; i++){
              int j;
              j = i+1;

              tree[i].data = j;
              if(j == 2 || j == 6){
                      tree[i].left_p = &tree[i-1];
                      tree[i].right_p = &tree[i+1];
              }
      }
      /* root */
      root_p = &tree[3];
      root_p->left_p = &tree[1];
      root_p->right_p = &tree[5];

      /* try the search */
      tp = t_search(root_p, 9);
      if(tp)
              printf("found at position %d\n", tp-tree);
      else
              printf("value not found\n");
      exit(EXIT_SUCCESS);
}