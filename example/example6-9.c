#include <stdio.h>
#include <stdlib.h>

struct tree_node {
  int data;
  struct tree_node *left_p, *right_p;
};

/*
 * Tree search algorithm.
 * Searches for value 'v' in tree,
 * returns pointer to first node found containing
 * the value otherwise 0.
 */
struct tree_node *
t_search(struct tree_node *root, int v) {
  while(root) {
    printf("looking for %d, looking at %d\n",
	   v, root->data);
    if (root->data == v)
      return(root);
    if (root->data > v)
      root = root->left_p;
    else
      root = root->right_p;
  }
  /* value not found, no tree left */
  return(0);
}

/*
 * Insert node into tree.
 * Return 0 for success,
 * 1 for value already in tree,
 * 2 for malloc error
 */
int
t_insert(struct tree_node **root, int v) {
  while (*root) {
    if ((*root)->data == v)
      return(1);
    if ((*root)->data > v)
      root = &((*root)->left_p);
    else
      root = &((*root)->right_p);
  }
  /* value not found, no tree left */
  if ((*root = (struct tree_node *)
      malloc(sizeof (struct tree_node)))
     == 0)
    return(2);
  (*root)->data = v;
  (*root)->left_p = 0;
  (*root)->right_p = 0;
  return(0);
}

main() {
  /* construct tree by hand */
  struct tree_node *tp, *root_p = 0;
  int i;

  /* we ingore the return value of t_insert */
  t_insert(&root_p, 4);
  t_insert(&root_p, 2);
  t_insert(&root_p, 6);
  t_insert(&root_p, 1);
  t_insert(&root_p, 3);
  t_insert(&root_p, 5);
  t_insert(&root_p, 7);

  /* try the search */
  for (i = 1; i < 9; i++) {
    tp = t_search(root_p, i);
    if (tp)
      printf("%d found\n", i);
    else
      printf("%d not found\n", i);
  }
  exit(EXIT_SUCCESS);
}
