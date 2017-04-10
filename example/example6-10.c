void
t_walk(struct tree_node *root_p){

      if(root_p == 0)
              return;
      t_walk(root_p->left_p);
      printf("%d\n", root_p->data);
      t_walk(root_p->right_p);
}