#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/bt_basics.h"
#include "../src/bt_bst.h"

void print_bt_p(bt_p *T)
{
    if (T == NULL)
    {
        printf("(nul)\n");
        return;
    }
    printf("%d (%d)\n", get_key_bt_p(T), get_elt_size_bt_p(T));
    // Bonus notre fonction affiche l'adresse du noeud
    printf("  @%p\n", T);
    printf("  |- ");
    print_bt_p(T->lc);

    printf("  |-\n");
    print_bt_p(T->rc);
}
int main(void)
{
    bt_p *T = NULL;
    int value_1 = 20;
    int value_2 = 15;
    int value_3 = 10;
    int value_4 = 12;

    T = insert_root_rot_bt_p(T, 20, sizeof(int), &value_1);
    T = insert_root_rot_bt_p(T, 15, sizeof(int), &value_2);
    printf("Notre arbre l'insertion de 20 :\n");
    print_bt_p(T);

    T = insert_root_rot_bt_p(T, 10, sizeof(int), &value_3);
    printf("Notre arbre après l'nsertion de 10 :\n");
    print_dfs_inorder_bt_p(T);

    T = insert_root_rot_bt_p(T, 12, sizeof(int), &value_4);
    printf("Notre arbre l'inserting 12 :\n");
    print_bt_p(T);

    T = insert_root_rot_bt_p(T, 12, sizeof(int), &value_4);

    if (T == NULL)
    {
        printf("Tout fonctionne :)\n");
    }
    else
    {
        printf("Erreur, crotte de bique insertion n'a pas été prise en compte "
               ":(\n");
    }
    T = insert_root_cut_bt_p(T, 20, sizeof(int), &value_1);
    printf("Notre arbre après l'insertion de 20 :\n");
    print_bt_p(T);

    int child_key1 = 10;
    int child_key2 = 30;
    T = insert_leaf_bt_p(T, child_key1, sizeof(int), &child_key1);
    T = insert_leaf_bt_p(T, child_key2, sizeof(int), &child_key2);
    T = insert_root_cut_bt_p(T, 15, sizeof(int), &value_2);
    printf("Notre après l'insertion de 15 :\n");
    print_bt_p(T);

    T = insert_root_cut_bt_p(T, 15, sizeof(int), &value_2);
    if (T == NULL)
    {
        printf("Tout fonctionne :)\n");
    }
    else
    {
        printf("Erreur, crotte de bique insertion n'a pas été prise en compte "
               ":(\n");
    }

    clear_bt_p(T);
    return 0;
}