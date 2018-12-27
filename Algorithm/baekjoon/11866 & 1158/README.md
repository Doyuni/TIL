# 조세퍼스 문제  

## C  
  
  '''c  
  CircularQ* Init(int size) {
    CircularQ *q;
    q = (CircularQ*)malloc(sizeof(CircularQ));
    q->data = (int*)malloc(sizeof(int)*size);
    //q->front = 0;
    q->rear = 0;
    q->max = size;
    return q;
 }
 '''
