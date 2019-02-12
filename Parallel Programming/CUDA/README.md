# CUDA Programming

### Kernels
 #### __global__
 * 커널을 정의할 때 사용한다.
 * <<< >>>을 사용하여 CUDA 스레드의 개수를 명시한다.
 * 커널을 실행시키는 각 스레드는 자신만의 ID를 갖고 있고, built-in variable(내장형 변수) threadIdx로 접근한다.
 ### threadIdx
 * 3개의 백터(x, y, z)
 * 한 블럭 당 스레드 개수의 제한이 있는데 GPUs에서는 1024개의 스레드까지 수용할 수 있다.
 * 하나의 1차원, 2차원 또는 3차원 grid(격자)에 블럭들이 존재하고, 블럭에는 여러 개의 스레드가 존재한다.
 * 스레드 개수를 명시할 때는 int 또는 dim3 타입을 사용한다.
### blockIdx & blockDim
 * 둘 다 built-in variable이다.
 * blockIdx를 통해 각 블럭에 접근이 가능하다.
 * blockDim을 통해 커널 내에서 스레드 블럭의 차원에 접근이 가능하다.
 ```c++ 
 // Kernel definition (device)
__global__ void MatAdd(float A[N][N], float B[N][N],
float C[N][N])
{
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    int j = blockIdx.y * blockDim.y + threadIdx.y;
    if (i < N && j < N)
        C[i][j] = A[i][j] + B[i][j];
}
// Host
int main()
{
    // 스레드 블럭 크기 16*16(256개의 스레드)
    dim3 threadsPerBlock(16, 16);
    dim3 numBlocks(N / threadsPerBlock.x, N / threadsPerBlock.y);
    
    // N개의 스레드
    MatAdd<<<1, N>>>(A, B, C);
    // N * N * 1 개의 스레드
    MatAdd<<<1, threadsPerBlock>>>(A, B, C);
    
    MatAdd<<<numBlocks, threadsPerBlock>>>(A, B, C);
   
}
```
 
