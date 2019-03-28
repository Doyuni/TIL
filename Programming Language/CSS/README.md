## CSS (Cascading Style Sheets) - 스타일
* **Style Sheets**
  * 문서의 스타일을 정의해 놓은 것
* **Cascading** (폭포가 되어 내리다)
  * 폭포처럼 내려가는(상속되는) 것이 있다.
* 웹 페이지에 대한 다양한 스타일을 정의한다.
-----------------
* 선택자, 속성, 값
* Ex.  
이 문단에서 폰트는 맑은 고딕, 크기는 18px 그리고 색깔은 파란색으로 해주세요.
```css
p {
    font-family: '맑은 고딕';
    font-size: 18px;
    color: blue;
}
```
* p는 선택자(selector) : '이 문단에는'에 해당한다.
* 속성(property) : 지정할 스타일의 속성명에 해당하며 미리 정해져 있다.  
세미콜론 ;까지를 한 단위로 구분합니다. '크기는'
* 값(value) : 속성에 맞는 값을 준다. '18px', '파란색'
* 맑은고딕이라면 인용부호 없이 그냥 써준다. 하지만 맑은 고딕이라면 인용부호를 써주어야 한다.
* 중괄호 { }를 선언 블록(Declaration block)이라 하고 이 블록 안에 선언을 해준다. 
### HTML에 CSS 적용시키기
1. link style
    HTML 내부에 있는 링크를
```css
<link rel="stylesheet" type="text/css" media="screen" href="basic.css">
```
2. Embedding style
    HTML head 부분에 
```css
<style>
    h1 {
        font-family: D2coding;
        font-size: 18px;
        color: blue;
    }
</style>
```
1. inline style

```css
<p style="font-family: D2coding; font-size: 24px;">이것은 코딩용 폰트입니다. | ㅣ I</p>
```
* link style을 사용하는 것이 좋다.

### 선택자
* 스타일을 적용하고자 하는 HTML 요소를 선택하는 역할
* 일반적인 태그: h1, p, span 등
```css
h1 {
    color: red;
}
p {
    color: red;
}
```
* 여러 개의 선택자를 콤마 , 를 이용하여 스타일을 한번에 지정 가능하다.
```css
h1, p {
    color: red;
}
```
#### 단순 선택자
* Type selector
```css
<style>
    h1 {
        font-family: D2coding;
        font-size: 18px;
        color: blue;
    }
</style>
```
모든 h1 태그에 style이 적용된다.
* Class selector
```css
<style>
        #title{
            font-family: D2coding;
            font-size: 18px;
            color: blue;
        }
        .contents {
            color:blueviolet;
            font-size: 15px;
        }
</style>

<h1 id="title"> </h1>
<p class="contents"></p>
```
* id와 class는 attribute이다.
  * id의 경우 중복되지 않도록 하는 것이 좋다.
  * class의 경우 여러 부분을 하나로 묶어서 같은 스타일을 적용시키고자 할 때 쓰인다.  
  
**전체 선택자**    
* 모든 요소에 스타일을 적용하기에 속도 저하 가능성이 있다.
```css
* {
    font-size: 30px;
}
```
단, 다른 요소에 다른 스타일을 적용하고 있으면 영향을 끼치지 않는다. 

**속성 선택자**    
```css
a[target="blank"] {
    color: red;
    font-size: 40px;
}
<a href="https://www.google.com" target='_blank'>구글</a>
<a href="https://www.naver.com">네이버</a>
```
속성을 지정하여 이 속성을 지닌 태그에만 스타일을 적용시킨다.

#### 복합 선택자
* 부모-나-자식의 계층 구조를 생각하며 html 구조를 생각해본다.
* article -div(나) - h1, h3, p (자식) - span (후손: 자식부터 span까지)  

**자식 선택자**  
```css
<style>
    div > p {
        color :cadetblue;
        font-size: 33px;
    }
</style>
<section>
        <div>
            <h1>제목입니다.</h1>
            <h3>부제목입니다.</h3>
            <p>내용1</p>
            <p>내용2</p>
        </div>
        <article>
            <p>내용3</p>
        </article>
</section>
<div>
    <p>이건 될까요 ?</p>
</div>
```
**후손 선택자**  
```css
div p {
    color:chartreuse;
    font-size: 40px;
}
```
div 내에 모든 p 태그에 style이 적용된다.  

**일반 형제 선택자**  
div ~ p라면 div를 기준으로 p까지 style을 적용한다.

#### Pseudo 클래스
```css
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <title>Page Title</title>
    <style>
        a:link{
            color: blue;
        }
        a:visited{
            color:red;
        }
    </style>
</head>
<body>
    <a href="https://google.com">구글</a>
</body>
</html>
```
* link는 방문하지 않았을 떄, visited는 방문했을 때 style을 지정해준다.
```css
p{
    background-color: cadetblue;
}
p:hover {
    background-color: aqua;
}
```
* hover는 마우스를 가져다 댔을 때 style를 지정해준다.
```css
input:focus {
    background-color: yellow;
}
<input type="text">
```
* 입력 칸이 있으며, 입력 칸에 입력을 할 때의 style을 지정해준다.
### 박스 모델
* margin border padding content로 이루어져 있다.
* margin은 border 밖에, padding은 border 안에 있다.
* padding을 통해 contents의 영향 범위를 늘릴 수 있다.
* margin은 contents와 상관이 없고 margin은 남는 부분과 결합하는 특징을 지녔다.
* padding, border, margin은 top right bottom left순인 시계방향으로 적용된다.
* border-radius는 모서리에 원을 놓고 자른 것과 같다.
* margin은 서로 중복이되면 높은 쪽으로 상쇄가 된다. (합쳐지지 않음)
