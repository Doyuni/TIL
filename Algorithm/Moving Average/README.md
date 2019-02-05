# 이동 평균

* 시간에 따라 변화하는 값들을 관찰할 떄 유용하게 사용할 수 있는 통계적 기준

* N개의 측정치가 주어질 때 M간의 이동 평균 측정법
  * 각 위치에서 지난 M개 측정치의 합을 구하고, 이를 M으로 나눈다.

```c++
vector<double> moving_average(const vector<double>& A, int M) {
    vector<double> result;
    int N = A.size();
    for(int i = M-1; i < N; ++i)
    {
        double partial_sum = 0;
        for(int j = 0; j < M; ++j)
        {
            partial_sum += A[i-j];
        }
        result.push_back(partial_sum / M);
    }
    return result;
}
```
**Time complexity**  
  M * (N-M+1)

* 5일 간 몸무게 이동 평균을 구하고자 한다면 다음을 확인할 수 있다.
  이전의 처음 값을 빼면 현재 이동 평균을 구할 때 현재 측정치를 빼고 값이 겹치는 것을 알 수 있다.
```
1 2 3 4 5 일 평균 = (1+2+3+4+5) / 5
2 3 4 5 6 일 평균 = (2+3+4+5+6) / 5
3 4 5 6 7 일 평균 = (3+4+5+6+7) / 5
```

```c++
vector<double> moving_average_linear(const vector<double>& A, int M) {
    vector<double> result;
    int N = A.size();
    double partial_sum = 0;
    for(int i = 0; i < M-1; ++i)
    {
        partial_sum += A[i];
    }
    for(int j = M-1; j < N; ++j)
    {
        partial_sum += A[j]; // 현재 측정치를 더한다.
        result.push_back(partial_sum / M); // 현재 이동 평균
        partial_sum -= A[j-(M-1)]; // 이전의 처음 값을 뺀다.
    }
    return result;
}
```

**Time complexity**  
  M-1+(N-M+1) = N
  
