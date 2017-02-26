/* Summury:
 * The class-style List implement is not as good as the c-style implement
 *
 * gcc -std=c99 list.c list.h
 *
 * by Jacob Pan
 * Feb 22, 2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"


//#define ASSERT TRY_
#define ASSERT(a) a;

static int _push(List apList, void* apItem, int aItemSize) {
    int vRet = -1;

    // create a new list item
    list_item_t *vpItem = malloc(sizeof(list_item_t));
    ASSERT(vpItem != NULL);
    memset(vpItem, 0, sizeof(list_item_t));

    vpItem->pVal = malloc(aItemSize);
    ASSERT(vpItem->pVal != NULL);
    memcpy(vpItem->pVal, apItem, aItemSize);

    // add to list
    if (apList->pTail != NULL) {
        apList->pTail->next = vpItem;
    } else {
        apList->pHead = vpItem;
    }
    apList->pTail = vpItem;

    vRet = 0;
CATCH:
    return vRet;
}

List List_init() {
    List vpList = malloc(sizeof(struct list));
    memset(vpList, 0, sizeof(struct list));
    vpList->push = _push;
    return vpList;
}

int List_deinit() {
    
}

/* trying to use macro to call a member method, but fail */
//mcall(list, push, &a, sizeof(int));
//#define mcall(aObj, aMethod, ...) (aObj->aMethodk

int main() {
    List list = List_init();
    int a = 1;
    int b = 2;
    int c = 3;

    list->push(list, &a, sizeof(int));
    list->push(list, &b, sizeof(int));
    List_foreach(it, list) {
        printf("%d\n", *(int *)(it->pVal));
    }
    
    return 0;
}
