# String  

### "파이썬에서는 문자열은 불변으로 변경할 수 없다."

* '', "", '''''', """""" 짝을 맞추어야 문자열 생성 가능(3개 인용 부호는 여러 줄에 사용)  
   print()는 인용 부호를 제거한 뒤 출력한다.

#### 1. 타입 변환: str() / 문자 추출: [] / 결합: + / 복제: *

```python
str(99.9) # 문자열로 변환 (print()에서 내부적으로 쓰는 함수이다.)
str(1.0e4)

a = '3'
a * 3 # aaa
b = "python" # b[0] >> 'p'
c = 'Let's start'
c+b # Let's startpython
```
#### 2. substring 추출(slice): [start : end : step] / 길이: len() / 나누기: split() / 결합: join() / 대체 : replace()
```python

a = "0123456789"
a[:] # 처음부터 끝까지 추출
a[1:] # 1번째부터 문자열 끝까지 추출
a[1:4] # 1번째부터 3번째까지 문자열 추출(end offset은 포함하지 않는다.)
a[-50:] # 끝에서 50번째부터 문자열 끝까지 추출
a[:-2] # 끝에서 2번째까지 문자(끝은 -1부터 시작한다.)
a[::-1] # 백스텝, 역순으로 된 문자열 추출

len(a) # 10

string.split(',') # ,를 기준으로 하나의 문자열을 리스트로 나눈다.
string.split() # 공백문자(\n, \t, " ")를 기준으로 나눈다.

string_list = ['Python', 'is', 'interesting']
# 문자열 list를 결합할 문자열로 이어준다.
string_join = ' '.join(string_list) # Python is interesting

string_join.replace('Python', 'Learning') # Learning is interesting
string_join.replace('n', 'op', 2) # 2회까지 대체, 생략 시 모두 대체
# >> Pythoop is iopteresting
```
**주의)새로운 문자가 함수의 결과로 반환될 뿐, string_join 문자열은 바뀌지 않는다.**

#### 3. 그외

```python
string = """Variable of static language can't be changed.
            But Variable declaration is not required in dynamic language(script lang).
            Interpreter instead of compiler translates the code.
            Dynamic lang is slower than static lang.
            """
string.startswith('Var') # Var로 시작하는가? True
string.endswith('static lang') # static lang으로 끝나는가? False
string.find('static') # 첫 번째로 static이 나오는 offset >> 12
string.rfind('static') # 마지막으로 static이 나오는 offset
string.count('static') # static 횟수
string.isalnum() # 글자와 숫자로만 이루어져 있는가?
string.capitalize() # 첫 번째 단어 대문자로
string.title() # 모든 단어의 첫 글자를 대문자로
string.upper() # 모두 대문자로
string.lower() # 모두 소문자로
string.swapcase() # 대문자 > 소문자, 소문자 > 대문자
string.center(300) # 300길이에서 중앙 정렬, ljust 왼쪽 정렬,  rjust 오른쪽 정렬
