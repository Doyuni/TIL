# 피보나치 수 2
최대 90번째 피보나치 수(10의 18승보다 큼)를 구할 수 있어야 함. >> long long(C/C++)

## C++
```c++
#include <iostream>
using namespace std;
long long d[91]; // 90번째 피보나치 수(10의 18승보다 큼)를 담으려면 long long을 쓴다.(long은 안됨)
long long fibo(int n)
{
	d[0] = 0, d[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		d[i] = d[i - 1] + d[i - 2];
	}
	return d[n];
}

int main()
{
	int n;
	cin >> n;
	cout << fibo(n) << endl;
	return 0;
}
```
## Java
Java에는 long long이 없음 long이 이를 대신한다.
```java
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        if(n<=90) {
            long fib[] = new long[91];
            fib[0] = 0;
            fib[1] = 1;
            for(int i=2; i<=n; i++) {
                fib[i] = fib[i-1] + fib[i-2];
            }
            System.out.println(fib[n]);
        }
    }
}
```
