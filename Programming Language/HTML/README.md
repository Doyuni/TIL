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
