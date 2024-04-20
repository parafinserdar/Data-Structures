#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

struct KeyValue {
    char *key;
    int value;
};

struct HashEntry {
    struct KeyValue *data;
    struct HashEntry *next;
};

struct HashTable {
    struct HashEntry *table[TABLE_SIZE];
};

unsigned int hash(const char *key) {
    unsigned int hashValue = 0;
    while (*key) {
        hashValue = (hashValue << 5) + *key++;
    }
    return hashValue % TABLE_SIZE;
}

struct KeyValue *newKeyValue(const char *key, int value) {
    struct KeyValue *kv = (struct KeyValue *)malloc(sizeof(struct KeyValue));
    kv->key = strdup(key);
    kv->value = value;
    return kv;
}

struct HashEntry *newHashEntry(struct KeyValue *data) {
    struct HashEntry *entry = (struct HashEntry *)malloc(sizeof(struct HashEntry));
    entry->data = data;
    entry->next = NULL;
    return entry;
}

struct HashTable *createHashTable() {
    struct HashTable *hashTable = (struct HashTable *)malloc(sizeof(struct HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}

void insert(struct HashTable *hashTable, const char *key, int value) {
    unsigned int index = hash(key);
    struct KeyValue *kv = newKeyValue(key, value);
    struct HashEntry *entry = newHashEntry(kv);

    if (hashTable->table[index] == NULL) {
        hashTable->table[index] = entry;
    } else {
        struct HashEntry *temp = hashTable->table[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = entry;
    }
}

int get(struct HashTable *hashTable, const char *key) {
    unsigned int index = hash(key);
    struct HashEntry *entry = hashTable->table[index];

    while (entry != NULL) {
        if (strcmp(entry->data->key, key) == 0) {
            return entry->data->value;
        }
        entry = entry->next;
    }
    return 0;
}

void destroyHashTable(struct HashTable *hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct HashEntry *entry = hashTable->table[i];
        while (entry != NULL) {
            struct HashEntry *temp = entry;
            entry = entry->next;
            free(temp->data->key);
            free(temp->data);
            free(temp);
        }
    }
    free(hashTable);
}

int main() {
    struct HashTable *hashTable = createHashTable();

    insert(hashTable, "anahtar1", 10);
    insert(hashTable, "anahtar2", 20);
    insert(hashTable, "anahtar3", 30);

    printf("anahtar1: %d\n", get(hashTable, "anahtar1"));
    printf("anahtar2: %d\n", get(hashTable, "anahtar2"));
    printf("anahtar3: %d\n", get(hashTable, "anahtar3"));

    destroyHashTable(hashTable);

    return 0;
}