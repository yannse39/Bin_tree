#include <stdio.h>
#include <stdlib.h>

#include "../src/bt_basics.h"
#include "../src/bt_bst.h"

int test_convert_tab_bt_p()
{
    bt_p *T = NULL;
    int value_1 = 10;
    int value_2 = 5;
    int value_3 = 15;
    T = insert_leaf_bt_p(T, 10, sizeof(int), &value_1);
    T = insert_leaf_bt_p(T, 5, sizeof(int), &value_2);
    T = insert_leaf_bt_p(T, 15, sizeof(int), &value_3);

    bt_t *table = convert_bt_p_to_tab(T);
    printf("Converted table:\n");
    print_bt_t(table);

    free(table->keys);
    free(table->elts_size);
    free(table->elts);
    free(table);
    clear_bt_p(T);
    return 0;
}