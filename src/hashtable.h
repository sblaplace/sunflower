#ifndef HASHTABLE_H_
#define HASHTABLE_H_

unsigned long hash(char *str);

typedef struct Ht_item
{
    char *key;
    char *value;
} Ht_item;