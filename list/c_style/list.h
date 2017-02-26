
#ifndef __TPAPPS_COMMON_UTIL_LIST__
#define __TPAPPS_COMMON_UTIL_LIST__

typedef struct _list_item_t list_item_t;
struct _list_item_t
{
    void *pVal;
    list_item_t *next;
};

typedef struct _list_t list_t;
struct _list_t {
    list_item_t * pHead;
    list_item_t * pTail;
};

int list_push(list_t * apList, void * apItem, int aItemSize);
int list_getLenght(list_t * apList);
int list_clear(list_t * apList);


#define list_foreach(aIt, aList) \
    for (list_item_t *(aIt) = (aList)->pHead; (aIt) != NULL; (aIt) = (aIt)->next)

#endif
