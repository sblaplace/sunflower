#define CAPACITY 50000 // Size of the HashTable.

static unsigned long
hash(unsigned char *str)
{
    unsigned long hash = 0;
    int c;

    while (c = *str++)
        hash = c + (hash << 6) + (hash << 16) - hash;

    return hash;
}
