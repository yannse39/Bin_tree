#include <stdio.h>
#include <stdlib.h>

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

    int key1 = 10;
    int key2 = 5;
    int key3 = 15;
    int value1 = 100;
    int value2 = 50;
    int value3 = 150;

    T = insert_leaf_bt_p(T, key1, sizeof(int), &value1);
    T = insert_leaf_bt_p(T, key2, sizeof(int), &value2);
    T = insert_leaf_bt_p(T, key3, sizeof(int), &value3);

    printf("Roulement de tambour et voilà :\n");
    print_bt_p(T);

    T = insert_leaf_bt_p(T, key2, sizeof(int), &value2);
    if (T == NULL)
    {
        printf("Tout fonctionne :)\n");
    }
    else
    {
        printf("Erreur, crotte de bique insertion n'a pas été prise en compte "
               ":(\n");
    }
    T = remove_node_bt_p(T, 5);
    printf("Voici notre abérrant arbre après avoir enlevé 5:\n");
    print_bt_p(T);

    T = remove_node_bt_p(T, 15);
    printf("Voici notre abérrant arbre après avoir enlevé 15:\n");
    print_bt_p(T);

    T = remove_node_bt_p(T, 20);
    if (T == NULL)
    {
        printf("Element non retiré car n'existe pas :)\n");
    }
    else
    {
        printf("Erreur, crotte de bique j'arrive pas à gérer l'élt non "
               "existant\n");
    }

    clear_bt_p(T);
    return 0;
}