#include <stdio.h>
#include <stdlib.h>
#include <string.h>




#define TABLE_SIZE 10

// �����ϣ�����Ŀ
typedef struct {
    int key;
    int value;
    int status; // 0 ��ʾ���У�1 ��ʾռ�ã�2 ��ʾ��ɾ��
} HashTableEntry;

// ��ϣ����
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// ��ʼ����ϣ��
void initializeTable(HashTableEntry table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i].status = 0; // 0 ��ʾ����
    }
}

// �����ֵ��
void insert(HashTableEntry table[], int key, int value) {
    int hashIndex = hashFunction(key);
    int originalIndex = hashIndex;
    int i = 1;

    while (table[hashIndex].status == 1) {
        hashIndex = (originalIndex + i) % TABLE_SIZE;
        i++;
        if (hashIndex == originalIndex) {
            printf("��ϣ������\n");
            return;
        }
    }

    table[hashIndex].key = key;
    table[hashIndex].value = value;
    table[hashIndex].status = 1; // 1 ��ʾռ��
}

// ���Ҽ�ֵ��
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

    return -1; // -1 ��ʾδ�ҵ�
}

// ɾ����ֵ��
void del(HashTableEntry table[], int key) {
    int hashIndex = hashFunction(key);
    int originalIndex = hashIndex;
    int i = 1;

    while (table[hashIndex].status != 0) {
        if (table[hashIndex].status == 1 && table[hashIndex].key == key) {
            table[hashIndex].status = 2; // 2 ��ʾ��ɾ��
            printf("�� %d ��ɾ��\n", key);
            return;
        }
        hashIndex = (originalIndex + i) % TABLE_SIZE;
        i++;
        if (hashIndex == originalIndex) {
            break;
        }
    }

    printf("δ�ҵ��� %d\n", key);
}

// ��ʾ��ϣ��
void displayTable(HashTableEntry table[]) {
    printf("��ϣ��:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("[%d]: ", i);
        if (table[i].status == 1) {
            printf("Key: %d, Value: %d\n", table[i].key, table[i].value);
        }
        else if (table[i].status == 2) {
            printf("��ɾ��\n");
        }
        else {
            printf("����\n");
        }
    }
}
