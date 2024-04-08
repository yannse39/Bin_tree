#include "bt_bst.h"

#include <stdio.h>
#include <stdlib.h>

#include "bt_basics.h"

bt_p *search_bt_p(bt_p *T, int key)
{
    if (T == NULL)
    {
        return NULL;
    }
    if (get_key_bt_p(T) == key)
    {
        return T;
    }
    if (key < get_key_bt_p(T))
    {
        return search_bt_p(T->lc, key);
    }
    return search_bt_p(T->rc, key);
}

bt_p *search_verbose_bt_p(bt_p *T, int key)
{
    if (T == NULL)
    {
        return NULL;
    }

    printf("%d\n", T->key);

    if (key == T->key)
    {
        return T;
    }
    else if (key < T->key)
    {
        return search_verbose_bt_p(T->lc, key);
    }
    else
    {
        return search_verbose_bt_p(T->rc, key);
    }
}
bt_p *insert_leaf_bt_p(bt_p *T, int key, int len_elt, void *elt)
{
    if (key <= 0)
    {
        printf("Erreur : la clé doit être strictement positive.\n");
        return T;
    }
    if (len_elt <= 0)
    {
        return T;
    }
    if (elt == NULL)
    {
        return T;
    }
    if (T == NULL)
    {
        T = create_bt_p(key, len_elt, elt, NULL, NULL);
        return T;
    }
    if (key < get_key_bt_p(T))
    {
        if (T->lc == NULL)
        {
            T->lc = create_bt_p(key, len_elt, elt, NULL, NULL);

            return T;
        }
        else
        {
            // Sinon, on continue la recherche dans le sous-arbre gauche
            insert_leaf_bt_p(T->lc, key, len_elt, elt);
        }
    }
    else if (key > get_key_bt_p(T))
    {
        if (T->rc == NULL)
        {
            T->rc = create_bt_p(key, len_elt, elt, NULL, NULL);

            return T;
        }
        else
        {
            insert_leaf_bt_p(T->rc, key, len_elt, elt);
        }
    }
    return T;
}
bt_p *remove_node_bt_p(bt_p *T, int key)
{
    if (key < T->key)
    {
        T->lc = remove_node_bt_p(T->lc, key);
    }
    else if (key > T->key)
    {
        T->rc = remove_node_bt_p(T->rc, key);
    }
    else
    {
        if (T->lc == NULL)
        {
            bt_p *tmp = T->rc;
            free(T);
            return tmp;
        }
        else if (T->rc == NULL)
        {
            bt_p *tmp = T->lc;
            free(T);
            return tmp;
        }
        else
        {
            bt_p *larg = T->lc;
            while (larg->rc != NULL)
            {
                larg = larg->rc;
            }
            T->key = larg->key;
            T->elt = larg->elt;
            T->elt_size = larg->elt_size;
            T->lc = remove_node_bt_p(T->lc, larg->key);
        }
    }

    return T;
}
bt_t *convert_bt_p_to_tab(bt_p *T)
{
    if (T == NULL)
    {
        return NULL;
    }

    int tab_len = size_bt_p(T);

    bt_t *tab = calloc(1, sizeof(bt_t));

    tab->tab_len = tab_len;
    tab->tab_used = 0;
    tab->keys = malloc(tab_len * sizeof(int));
    tab->elts_size = malloc(tab_len * sizeof(int));
    tab->elts = malloc(tab_len * sizeof(void *));
    int idx = 0;
    tab->keys[idx] = T->key;

    tab->elts_size[idx] = T->elt_size;

    tab->elts[idx] = T->elt;

    tab->tab_used++;

    convert_bt_p_to_tab(T->lc);
    convert_bt_p_to_tab(T->rc);

    idx++;

    convert_bt_p_to_tab(T);
    return tab;
}
void print_bt_t(bt_t *T_tab)
{
    if (T_tab == NULL)
    {
        printf("Tableau vide\n");
        return;
    }

    printf("key de l'arbre binaire:\n");

    for (int i = 0; i < T_tab->tab_used; i++)
    {
        if (T_tab->keys[i] != 0)
        {
            printf("%d\n", T_tab->keys[i]);
        }
        else
        {
            printf("(nul)\n");
        }
    }
}
bt_p *insert_root_rot_bt_p(bt_p *T, int key, int elt_size, void *elt)
{
    if (key <= 0)
    {
        return T;
    }

    bt_p *new_node = create_bt_p(key, elt_size, elt, NULL, NULL);

    if (T == NULL)
    {
        return new_node;
    }

    if (key < T->key)
    {
        new_node->rc = T;
        T = new_node;
    }
    else
    {
        new_node->lc = T;
        T = new_node;
    }

    return T;
}
bt_p *insert_root_cut_bt_p(bt_p *T, int key, int elt_size, void *elt)
{
    if (key <= 0)
    {
        return T;
    }

    bt_p *new_node = create_bt_p(key, elt_size, elt, NULL, NULL);

    if (T == NULL)
    {
        return new_node;
    }

    if (key < T->key)
    {
        new_node->rc = insert_root_cut_bt_p(T->rc, T->key, T->elt_size, T->elt);
        new_node->lc = T->lc;
    }
    else
    {
        new_node->lc = insert_root_cut_bt_p(T->lc, T->key, T->elt_size, T->elt);
        new_node->rc = T->rc;
    }

    free(T);

    return new_node;
}
