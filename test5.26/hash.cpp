#include <stdio.h>
#include <stdlib.h>
#include <string.h>




#define TABLE_SIZE 10

// 定义哈希表的条目
typedef struct {
    int key;
    int value;
    int status; // 0 表示空闲，1 表示占用，2 表示已删除
} HashTableEntry;

// 哈希函数
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// 初始化哈希表
void initializeTable(HashTableEntry table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i].status = 0; // 0 表示空闲
    }
}

// 插入键值对
void insert(HashTableEntry table[], int key, int value) {
    int hashIndex = hashFunction(key);
    int originalIndex = hashIndex;
    int i = 1;

    while (table[hashIndex].status == 1) {
        hashIndex = (originalIndex + i) % TABLE_SIZE;
        i++;
        if (hashIndex == originalIndex) {
            printf("哈希表已满\n");
            return;
        }
    }

    table[hashIndex].key = key;
    table[hashIndex].value = value;
    table[hashIndex].status = 1; // 1 表示占用
}

// 查找键值对
int search(HashTableEntry table[], int key) {
    int hashIndex = hashFunction(key);
    int originalIndex = hashIndex;
    int i = 1;

    while (table[hashIndex].status != 0) {
        if (table[hashIndex].status == 1 && table[hashIndex].key == key) {
            return table[hashIndex].value;
        }
        hashIndex = (originalIndex + i) % TABLE_SIZE;
        i++;
        if (hashIndex == originalIndex) {
            break;
        }
    }

    return -1; // -1 表示未找到
}

// 删除键值对
void del(HashTableEntry table[], int key) {
    int hashIndex = hashFunction(key);
    int originalIndex = hashIndex;
    int i = 1;

    while (table[hashIndex].status != 0) {
        if (table[hashIndex].status == 1 && table[hashIndex].key == key) {
            table[hashIndex].status = 2; // 2 表示已删除
            printf("键 %d 已删除\n", key);
            return;
        }
        hashIndex = (originalIndex + i) % TABLE_SIZE;
        i++;
        if (hashIndex == originalIndex) {
            break;
        }
    }

    printf("未找到键 %d\n", key);
}

// 显示哈希表
void displayTable(HashTableEntry table[]) {
    printf("哈希表:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("[%d]: ", i);
        if (table[i].status == 1) {
            printf("Key: %d, Value: %d\n", table[i].key, table[i].value);
        }
        else if (table[i].status == 2) {
            printf("已删除\n");
        }
        else {
            printf("空闲\n");
        }
    }
}
