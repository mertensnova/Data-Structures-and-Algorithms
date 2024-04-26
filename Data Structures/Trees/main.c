#include "tree.h"
#include <stdio.h>

int main() {

  TreeNode *root = node_create(4);

  bst_insert(node_create(3), root);
  bst_insert(node_create(6), root);
  bst_insert(node_create(2), root);
  bst_insert(node_create(5), root);
  bst_insert(node_create(7), root);

  printf("BFS: \n");
  bfs(root);

  printf("DFS Pre-order: \n");
  traverse_pre(root);
  printf("\n");

  printf("DFS In-order: \n");
  traverse_inorder(root);
  printf("\n");

  printf("DFS Post-order: \n");
  traverse_post(root);
  printf("\n");
  return 0;
}
