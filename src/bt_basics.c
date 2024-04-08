#include "bt_basics.h"

#include <stdio.h>
#include <stdlib.h>

bt_p *create_bt_p(int key, int elt_size, void *elt, bt_p *left_child,
                  bt_p *right_child)
{
    bt_p *node = calloc(1, sizeof(bt_p));

    if (node == NULL)
    {
        return NULL;
    }
    node->key = key;

    node->elt = elt;

    node->elt_size = elt_size;

    node->lc = left_child;

    node->rc = right_child;

    return node;
}

int get_key_bt_p(bt_p *node)
{
    if (node == NULL)
    {
        return -1;
    }

    return node->key;
}
int get_elt_size_bt_p(bt_p *node)
{
    if (node == NULL)
    {
        return -1;
    }

    return node->elt_size;
}

void *get_elt_bt_p(bt_p *node)
{
    if (node == NULL)
    {
        return NULL;
    }

    return node->elt;
}

int deepness_node_bt_p(bt_p *T, bt_p *node)
{
    if (node == NULL)
    {
        return -1;
    }
    if (T == NULL)
    {
        return -1;
    }

    if (node == T)
    {
        return 0;
    }

    int prof_gauche = deepness_node_bt_p(T->lc, node);
    if (prof_gauche != -1)
    {
        return prof_gauche + 1;
    }

    int prof_droite = deepness_node_bt_p(T->rc, node);
    if (prof_droite != -1)
    {
        return prof_droite + 1;
    }

    return -1;
}

int size_bt_p(bt_p *T)
{
    if (T == NULL)
    {
        return 0;
    }
    return T->elt_size;
}
int height_bt_p(bt_p *T)
{
    if (T == NULL)
    {
        return -1;
    }
    if (T->lc)
    {
        return 0;
    }
    if (T->rc)
    {
        return 0;
    }

    int h_gauche = height_bt_p(T->lc);

    int h_droite = height_bt_p(T->rc);

    return 1 + (h_gauche > h_droite ? h_gauche : h_droite);
}
void print_dfs_preorder_bt_p(bt_p *T)
{
    if (T != NULL)
    {
        printf("%d\n", T->key);
        print_dfs_preorder_bt_p(T->lc);
        print_dfs_preorder_bt_p(T->rc);
    }
}
void print_dfs_inorder_bt_p(bt_p *T)
{
    if (T = NULL)
    {
        return;
    }
    print_dfs_inorder_bt_p(T->lc);
    printf("%d\n", T->key);
    print_dfs_inorder_bt_p(T->rc);
}
void print_dfs_postorder_bt_p(bt_p *T)
{
    if (T == NULL)
    {
        return;
    }

    print_dfs_postorder_bt_p(T->lc);
    print_dfs_postorder_bt_p(T->rc);
    printf("%d\n", T->key);
}
void print_hierarchical_bt_p(bt_p *T)
{
    if (T == NULL)
    {
        return;
    }
    bt_p *queue_bt[100];
    int var = 0, temp = 0;

    queue_bt[temp++] = T;

    while (var < temp)
    {
        bt_p *new = queue_bt[var++];
        printf("%d\n", new->key);

        if (new->lc != NULL)
        {
            queue_bt[temp++] = new->lc;
        }
        if (new->rc != NULL)
        {
            queue_bt[temp++] = new->rc;
        }
    }
}

int hierarchical_number_bt_p(bt_p *T, int key)
{
    if (T == NULL)
    {
        return -1;
    }

    if (T->key == key)
    {
        return 1;
    }

    int lt_num = hierarchical_number_bt_p(T->lc, key);
    int rt_num = hierarchical_number_bt_p(T->rc, key);

    if (lt_num != -1)
    {
        return lt_num + 1;
    }

    if (rt_num != -1)
    {
        return lt_num + rt_num + 1;
    }

    return -1;
}

int clear_bt_p(bt_p *T)
{
    if (T == NULL)
    {
        return 0;
    }
    else
    {
        int clear = 1;

        clear += clear_bt_p(T->lc);

        clear += clear_bt_p(T->rc);

        free(T);

        return clear;
    }
}
