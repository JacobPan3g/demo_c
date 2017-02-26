
#ifndef __TPAPPS_COMMON_UTIL_LIST__
#define __TPAPPS_COMMON_UTIL_LIST__


typedef struct list_item list_item_t;
struct list_item
{
    void *pVal;
    list_item_t *next;
};

typedef struct list * List;
struct list {
    int num;
    list_item_t *pHead;
    list_item_t *pTail;
    // methods
    int (*push)(List apList, void *apItem, int aItemSize);
};


#define List_foreach(it, aList) \
    for (list_item_t *it = aList->pHead; it != NULL; it = it->next)

#endif
