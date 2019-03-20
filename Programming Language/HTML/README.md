## HTML (Hyper Text Markup Language) - 구조
* Hyper Text
  * 내가 원하는 곳으로 한 번에 접근이 가능하다. 서로 연결되어 있어서 Text보다 유동적이다.
* Markup Language
  * 표시를 해두는 언어
* 웹 페이지의 구조 혹은 데이터 작성을 위한 언어
  * 웹 사이트의 구조를 Markup으로 표시를 해두어 구분을 해준다.
* Elements(요소)
  * markup으로 둘러쌓인 덩어리
    * <h>웹 개발</h>
  * <Start tag>Contents<End tag>
* Tag: 내용을 나누고 어떤 역할을 하는지 구조를 정의
  * Start tag: contents의 시작을 표시
  * End tag: contents의 끝을 표시
* 왜 구분을 해주어야 하는가 ?
  * 컴퓨터가 알아듣게 하기 위해
  * 검색엔진 최적화  
내가 만든 contents를 남들에게 잘 보이도록 최적화 이를 위해 구조적으로 세분화를 해놓아야 검색 대상이 되기 쉽다.  
  * 접근성  
남들이 접근하기 쉽게 하기 위하여
### HTML 문서 구조
#### Layout
* 실질적인 layout이 아닌 구조적인 layout을 담고 있다.
#### Semantic Tag
* 태그만 봐도 어떤 내용(의미)이 담겨있는지 알 수 있다.
* header, nav(메뉴), section(구획), article(내용), aside(부가적), footer(정책 및 지침)
#### 제목 태그
* h1 ~ h6
* 중요하다고 생각되는 
```html
<h1>heading 1</h1>
<h2>heading 2</h2>
<h3>heading 3</h3>
<h4>heading 4</h4>
<h5>heading 5</h5>
<h6>heading 6</h6>
이것은 내용입니다.
```
* 태그를 구분하지 않으면 text를 하나의 덩어리로 보고 contents를 보여준다.  
하지만 태그를 구분하지 않았기에 권하지는 않는다.
#### 본문 태그
* paragraphs (단락, 문단)
* '\n' (엔터)를 인식하지 않기 때문에 한 문장으로 출력된다.
* 공백이 여러 개라면 하나만 인식한다.
```html
<!--same-->
<p>하나의 내용입니다.</p>
<p>하나의          내용입니다.</p>
<p>하나의
  내용입니다. </p>
```
* br tag를 이용하여 문장을 나눌 수 있다. (엔터 역할)
  * br 태그는 빈 요소(컨텐츠를 담고 있지 않는다.)로서 기능을 수행한다.
* pre tag를 이용하여 사용자가 원하는 형태로 컨텐츠를 만들 수 있다.
  * 사용자가 작성한 그대로를 나타내준다.
#### 글자와 관련된 태그
* **strong** tag를 이용하여 bold체, **em**phasized tag를 이용하여 italic체로 사용할 수 있다.
* **sub**scripted (아래에 기입한)
* **sup**erscripted (위에 기입한)
* **ins**erted (끼워 넣은)
* **del**eted
#### Link 태그
* Hyper Link
* **<a></a>**
* <a 키="값"> 형태로 attributes(속성=키)가 필요하다.
* 값에는 "" or '' 안에 써주어 키와 값을 구분해줘야 한다. 
* <a 이름="Doyuni" 성별='남'>Doyuni</a>
```html
<a href="https:/www.google.com">구글</a>
```
* **href**: hypertext reference
* 웹사이트 주소가 경로는 아니다.
**path**: 지나는 길
* 웹사이트 주소 = "경기도 xx 아파트"
* 경로 = "경기도 xx 아파트/A의 방/A"
* Absolute path: 시작점부터 목표지점까지의 고유한 경로 
  * "경기도 xx 아파트/A의 방/A"
  * "경기도 xx 아파트/A의 방/나"
* Relative path: 비교할 대상이 있는 경로, 현재 위치한 곳을 기준으로 목표지점까지의 경로
  * "A"
  * "(경기도 xx 아파트/A의 방/)나"
#### 주소 표기법
**/**   루트(최상위 디렉토리)  
**../**  상위 디렉토리  
**./**   현재 디렉터리  
#### target 속성
* target="_self"
  * 현재 탭에서 링크를 여는 속성으로 default로 지정되어있다.
* target="_blank"
  * 새 탭에서 링크를 여는 속성.
* href 속성 뒤에 써주어야 한다.
```html
<a href="https:/www.google.com" target="_blank" >구글</a>
```
#### 이미지 속성
* src에는 이미지 링크 주소 또는 경로(파일로 저장되어 있는 경우)를 써준다.
* alt 속성은 반드시 써주어야 한다. 
  * 이미지가 깨졌을 때를 방지하기 위해서
  * 이미지의 접근성을 위해서
* width나 height 하나만 지정해주면 나머지는 auto로 크기가 변경된다.
  * 둘다 쓴다면 비율을 잘 알고 지정해주는게 좋다.
  * width와 height는 CSS에서 사용하는 것을 권장한다.
```html
<img src="이미지 주소" alt="이미지 표시" width="100px"/>
<img src="https://cdn.pixabay.com/photo/2017/09/10/18/11/apple-2736410_1280.png" alt="apple" width="100px"/>
```
#### List 태그
* browser에서 기본적으로 정해진 모양이 있기에 자동으로 들여쓰기가 된다.  

**ol**  
* order list   
* type="I"으로 로마자 표기로 나타낼 수 있다.
* reversed로 역순으로 나타낼 수 있다.
* start="7"을 통해 숫자를 7부터 시작할 수 있다.
```html
<ol>
  <li>첫 번째</li>
  <li>두 번째</li>
</ol>
```
_output_
```
1. 첫 번째
2. 두 번째
```
**ul**  
* unorder list
```html
<ol>
  <li>하나</li>
  <li>둘</li>
</ol>
```
_output_
```
● 하나
● 둘
```
#### Table 태그
* **t**able **r**ow: 테이블 한 줄
* **t**able **h**ead: 제목
* **t**able **d**ata: 내용
* border="1", 1px의 테이블 경계
* colspan="2", 행으로 2칸을 갖는다
```html
<table>
    <tr>
        <th>과일</th>
        <td>바나나</td>
        <td>딸기</td>
    </tr>
    <tr>
        <th>웹브라우저</th>
        <td>크롬</td>
        <td>파이어폭스</td>
    </tr>
</table>

<table border="1">
    <tr>
        <th>제목1</th>
        <th>제목2</th>
        <th colspan="3">제목3</th>
    </tr>
    <tr>
        <td>내용1</td>
        <td>내용2</td>
        <td>내용3</td>
        <td>내용3</td>
        <td>내용3</td>
    </tr>
    <tr>
        <td>내용4</td>
        <td>내용5</td>
        <td>내용6</td>
    </tr>
</table>
```
