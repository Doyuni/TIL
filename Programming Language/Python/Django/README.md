
## Django Project 작동원리

#### Django Project 생성
- django-admin startproject <project 이름>
#### 서버 작동
- python manage.py runserver
#### App(프로젝트의 작은 부분)
- python manage.py startapp <app 이름>
- Project 폴더의 파일들과 App 폴더의 파일들이 서로 data를 주고받는다.
- Project 폴더의 settings.py에서 project와 app을 연결시켜준다.
#### App 폴더 내에 "templates" 폴더 만들기
- templates 폴더에는 html file들이 담기게 된다. (실제로 화면에 보여지는 부분)

- App 폴더 내에 views.py는 html file들이 언제 어떻게 처리될지 정의하는 함수를 작성하는 부분이다.
- Project 폴더 내에 url.py는 위의 html file들이 어떤 url을 입력했을 때 화면으로 보이게 할지 정의하는 부분이다.

### 요약
1. app을 settings.py를 통해 project에 연결한다.
2. app의 templates에 html 파일을 생성한다.
3. 만든 html 파일이 어떻게 처리될지를 알려주는 함수를 정의한다.
4. project의 url.py를 통해 만든 html파일을 url로 연결해준다.
