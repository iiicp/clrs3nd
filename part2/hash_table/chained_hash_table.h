#ifndef chained_hash_table_h
#define chained_hash_table_h

#include <stdio.h>

typedef struct{
    char *key;
    char *value;
    char *next;
}cht_item;

typedef struct{
    int buckets;
    cht_item **item;
}cht_table;

cht_table *cht_new_table(int buckets);
void cht_hash_insert(cht_table *table, char *key, char *value);
char *cht_hash_search(cht_table *table, char *key);
void cht_hash_delete(cht_table *table, char *key);
void cht_del_table(cht_table *table);

#endif /* chained_hash_table_h */
