# LCS
* LCS(Longest Common Subsequence) : 연속적이지 않은 부분 문자열 중 제일 긴 문자열   

  Subsequence 와 Substring의 차이점 : 불연속 / 연속
  
 Using _bottom-up_
 
 ## C++
 ```c++
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int d[1001][1001]; // s1의 i번째까지 문자열과 s2의 j번째까지 문자열의 LCS 길이
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	// 대각선, 왼쪽, 위를 비교하는 점화식이므로 문자 하나를 추가하여 공간을 확장한다.
	s1 = "0" + s1; 
	s2 = "0" + s2;

	for (unsigned int i = 1; i < s2.size(); i++)
	{
		for (unsigned int j = 1; j < s1.size(); j++)
		{	//문자가 같을 때
			if(s2[i] == s1[j]) // 대각선 LCS의 길이+1
			{
				d[i][j] = d[i - 1][j - 1] + 1;
			} else // 위와 왼쪽 LCS의 길이 중 최댓값
			{
				d[i][j] = max(d[i - 1][j], d[i][j - 1]);
			}
		}
	}
	cout << d[s2.size() - 1][s1.size() - 1] << endl;
	return 0;
}
```

