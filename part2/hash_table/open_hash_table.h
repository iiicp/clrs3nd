#ifndef open_hash_table_h
#define open_hash_table_h

#include <stdio.h>

typedef enum {
    empty,
    used,
    deleted
}oht_item_info;

typedef struct{
    char *key;
    char *value;
    oht_item_info info;
}oht_item;

typedef struct {
    int size;
    int count;
    oht_item **item;
}oht_table;

oht_table *oht_new_table(int base_size);
void oht_hash_insert(oht_table *table, char *key, char *value, oht_item_info info);
void oht_hash_delete(oht_table *table, char *key);
char *oht_hash_search(oht_table *table, char *key);
void oht_delete_table(oht_table *table);

#endif /* open_hash_table_h */
