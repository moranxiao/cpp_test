#include <stdlib.h>
#include <stdio.h>
//队列

typedef struct {
int front; // 队头指针
int rear;  // 队尾指针
unsigned capacity; // 队列的容量
int* array; // 队列的数组
} Queue;

// 初始化队列
Queue* createQueue(unsigned capacity) {
Queue* queue = (Queue*) malloc(sizeof(Queue));
if (!queue) return NULL;

queue->front = 0;
queue->rear = -1;
queue->capacity = capacity;
queue->array = (int*) malloc(queue->capacity * sizeof(int));

if (!queue->array) {
free(queue);
return NULL;
}

return queue;
}

// 判断队列是否为空
bool isEmpty(Queue* queue) {
return queue->front > queue->rear;
}

// 判断队列是否已满
bool isFull(Queue* queue) {
return ((queue->rear + 1) % queue->capacity == queue->front);
}

// 入队操作
bool enqueue(Queue* queue, int item) {
if (isFull(queue))
return false;

queue->array[++queue->rear] = item;
return true;
}

// 出队操作
bool dequeue(Queue* queue, int* item) {
if (isEmpty(queue))
return false;

*item = queue->array[queue->front++];
return true;
}

// 获取队头元素
bool front(Queue* queue, int* item) {
if (isEmpty(queue))
return false;

*item = queue->array[queue->front];
return true;
}

// 销毁队列
void destroyQueue(Queue* queue) {
free(queue->array);
free(queue);
}
