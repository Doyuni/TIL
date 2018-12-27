# 조세퍼스 문제  
 Using _Circular queue_
## C code

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    //int front;
    int rear;
    int max;
    int *data;
}CircularQ;

CircularQ* Init(int size) {
    CircularQ *q;
    q = (CircularQ*)malloc(sizeof(CircularQ));
    q->data = (int*)malloc(sizeof(int)*size);
    //q->front = 0;
    q->rear = 0;
    q->max = size;
    return q;
}

void Inqueue(CircularQ *q) {
    int num = 1;
    for (int i = 0; i < q->max; ++i) {
        q->data[i] = num++;
    }
}

int dequeue(CircularQ *q, int M) {
    int temp = 0;
    for (int i = 0; i < M; ++i) {
        if(q->rear == q->max) { // using circular queue
            q->rear = 0;
        }
        if(q->data[q->rear++] == 0) { // IsEmpty : yes -> skip
            i--;
            continue;
        }
    }
    temp = q->data[q->rear-1];
    q->data[q->rear-1] = 0; // IsDequeue : yes -> 0
    return temp;
}

int main() {
    CircularQ *q;
    int N, M;
    scanf("%d %d", &N, &M);
    q = Init(N);
    Inqueue(q);
    printf("<");
    for (int i = 0; i < N-1; ++i) {
        printf("%d, ", dequeue(q, M));
    }
    printf("%d>", dequeue(q, M));
    free(q);
    return 0;
}
```
