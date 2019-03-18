## Array(배열)

### 배열 선언 및 초기화
```c++
int arr[] = {1, 2, 3};
arr[4] = 4; // runtime error
```
* 배열의 크기를 넘는 접근을 하게 되면 에러가 발생한다.

**Using structure**
```c++
struct Rectangle
{
    int length;
    int width;
};
sizeof(Rectangle); // 8 bytes
Rectangle rect_arr[10];
```
**Using enum**
```c++
enum PeopleName {
    BRIAN,      // 0
    LENA,       // 1
    DANTE,      // 2
    NUM_PEOPLE, // 3
};
int people[NUM_PEOPLE]; // 딱 enum 요소만큼 할당된다.
people[LENA]; // people의 1번째 요소에 접근한다.
```
_**주의**_
```c++
int num;
cin >> num;       // num은 런타임에 의해 결정된다.
int scores[num]; // 컴파일 타임에 사이즈가 결정된다.
```
* compile time에 사이즈가 결정되어야 하는데 위의 입력은 compile time 이후인 runtime 때 발생하기 때문에 error가 발생한다.
(runtime: 프로그램이 실행되고 있을 때를 말한다.)  
* const를 이용한다.
```c++
const int num_scores = 20; // 컴파일 하기 전에 이미 사이즈가 결정된다.
int student_scores[num_scores]; // 사이즈는 정수형이면 넣을 수 있다. (ex. short, char 등)
```
### 배열의 크기
* 배열의 자료형 크기 * 요소의 개수  
```c++
Rectangle rect_arr[10]; 
PeopleName pe_arr[2]; 
sizeof(rect_arr); // 80 = 8 * 10
sizeof(pe_arr); // 8 = 4 * 2
```
### 배열이 인자로 들어가 있는 경우, 전달방식
* 배열의 주소는 그 배열의 첫 번째 주소와 같다. 
* 배열의 바로 다음 인덱스 주소는 이전 주소값 + 배열의 자료형 크기이다.
```c++
// 16진수로 표현되는 주소값 int로 캐스팅
cout << (int)&student_scores << endl;    // 19921952
cout << int(&student_scores[0]) << endl; // 19921952
cout << int(&student_scores[1]) << endl; // 19921956
```
* 배열을 인자로 하는 함수를 호출하는 경우, 배열을 복사하여 사용한다.   
  (주소값이 다른 것을 통해 확인할 수 있다.)  
* 배열 자체로 넘어온게 아닌 포인터로 넘어왔기에 인자의 사이즈는 포인터 사이즈가 출력된다.  
  (PC가 32bit이면 4bytes, 64bit이면 8bytes이다.)  
```c++
// 새로 선언하여 20개를 할당 받고 들어온 인자(배열)을 복사한다.
void doSomething(int student_scores[20]) { 
    cout << (int)&student_scores << endl;   // 19921740
    cout << sizeof(student_scores) << endl; // 4
}
doSomething(student_scores); // array 복사
```
### Multi dimension
* 2차원 배열 선언
```c++
const int rows = 3;
const int columns = 5;

int multi_array[rows][columns] =
{
        // 주소를 보면 사실 1차원으로 보임
        {1, 2, 3, 4, 5},     //  1, 4, 8, 16, 20
        {6, 7, 8, 9, 10},    // 24, 28, 32, 36, 40
        {11, 12, 13, 14, 15} // ...
};

int array[][4] = {
    {1, 2},
    {1, 2, 3, 4},
    {1, 2, 3}};
    
cout << sizeof(multi_array) << endl; // 60 ( 3 * 5 * 4 )
```
* 배열 선언시 rows는 비어있어도 되지만 columns은 꼭 넣어줘야 한다.
#### 몇 행인지, 몇 열인지 구하기
```c++
int num_row = sizeof(array) / sizeof(array[0]);            // 60 / (5 * 4) = 3
int num_column = sizeof(array[0]) / sizeof(array[0][0]);
```
