
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"


//#define ASSERT TRY_
#define ASSERT(a) a;

int list_push(list_t * apList, void * apItem, int aItemSize) {
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

int list_getLenght(list_t * apList) {
    int vLen = 0;
    list_foreach(it, apList) {
        vLen++;
    }
    return vLen;
}

int list_clear(list_t * apList) {
    list_item_t * it = apList->pHead;
    list_item_t * vpNext = NULL;
    while(it) {
        vpNext = it->next;
        free(it->pVal);
        free(it);
        it = vpNext;
    }
    
    return 0;
}

int main() {
    list_t list = {0};
    int a = 1;
    int b = 2;

    list_push(&list, &a, sizeof(int));
    list_push(&list, &b, sizeof(int));
    printf("len: %d\n", list_getLenght(&list));
    list_foreach(it, &list) {
        printf("%d\n", *(int *)(it->pVal));
    }
    
    list_clear(&list);

    return 0;
}
