# 프린터 큐  
Using _Circular queue_  
## C code

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue {
    int front;
    int rear;
    int max;
    int *data;
}CircularQ;

CircularQ* Init(int size) {
    CircularQ *q;
    q = (CircularQ*)malloc(sizeof(CircularQ));
    q->data = (int*)malloc(sizeof(int)*size);
    q->front = 0;
    q->rear = 0;
    q->max = size;
    return q;
}

void Inqueue(CircularQ *q, char *data) {
    int *ptr;
    int i = 0;
    ptr = strtok(data," ");
    while(ptr != NULL) {
        q->data[i++] = atoi(ptr);
        ptr = strtok(NULL, " ");
    }
}

int priority(CircularQ *q) {
    int num = q->data[0];
    for (int i = 1; i < q->max; ++i) {
        if(num < q->data[i]) {
            num = q->data[i];
        }
    }
    return num;
}

int dequeue(CircularQ *q, int M) {
    while(1) {
        if(q->data[q->rear] < priority(q)) {
            q->rear++;
            if(q->rear == q->max) { // Circular queue
                q->rear = 0;
            }
        } else {
            q->front++; //front = 인쇄된 순번
            if(q->rear == M) { // 구하고자 하는 문서가 출력될 때 종료
                break;
            }
            q->data[q->rear] = 0; // 출력된 문서의 우선순위는 0으로 표시
        }
    }
    return q->front;
}

int main() {
    CircularQ *q;
    int T, N, M;
    char data[200]; // 최대 N의 개수는 100개지만 공백포함 입력 받으려면 2배의 크기가 필요
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        scanf("%d %d", &N, &M);
        q = Init(N);
        getchar();
        scanf("%[^\n]s", data);
        Inqueue(q, data);
        printf("%d\n", dequeue(q, M));
    }
    free(q);
    return 0;
}
```
