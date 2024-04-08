#include <stdio.h>
#include <stdlib.h>

#include "../src/bt_basics.h"
#include "../src/bt_bst.h"

int main(void)
{
    bt_p *node1 = create_bt_p(1, sizeof(int), (void *)&(int){ 10 }, NULL, NULL);
    bt_p *node2 = create_bt_p(2, sizeof(int), (void *)&(int){ 20 }, NULL, NULL);
    bt_p *node3 = create_bt_p(3, sizeof(int), (void *)&(int){ 30 }, NULL, NULL);
    bt_p *node4 = create_bt_p(4, sizeof(int), (void *)&(int){ 40 }, NULL, NULL);
    bt_p *node5 = create_bt_p(5, sizeof(int), (void *)&(int){ 50 }, NULL, NULL);

    node1->lc = node2;
    node1->rc = node3;
    node2->lc = node4;
    node2->rc = node5;

    printf("Key of node1: %d\n", get_key_bt_p(node1));
    printf("Element of node3: %d\n", *((int *)get_elt_bt_p(node3)));
    printf("Depth of node5: %d\n", deepness_node_bt_p(node1, node5));
    printf("Size of the tree: %d\n", size_bt_p(node1));
    printf("Height of the tree: %d\n", height_bt_p(node1));

    printf("DFS Preorder Traversal: ");
    print_dfs_preorder_bt_p(node1);
    printf("\n");

    printf("DFS Inorder Traversal: ");
    print_dfs_inorder_bt_p(node1);
    printf("\n");

    printf("DFS Postorder Traversal: ");
    print_dfs_postorder_bt_p(node1);
    printf("\n");

    printf("Hierarchical Traversal:\n");
    print_hierarchical_bt_p(node1);

    clear_bt_p(node1);

    return 0;
}
