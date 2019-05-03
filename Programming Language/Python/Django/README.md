
## Django Project 작동원리

#### Django Project 생성
- django-admin startproject <project 이름>
#### 서버 작동
- python manage.py runserver
#### App(프로젝트의 작은 부분)
- python manage.py startapp <app 이름>
- Project 폴더의 파일들과 App 폴더의 파일들이 서로 data를 주고받는다.
- Project 폴더의 settings.py에서 project와 app을 연결시켜준다.
  - '**<app 이름>**.apps.<**첫글자가 대문자인 app 이름**>Config', or '**<app이름>**,'
  - app이름이 **doapp**이면 다음과 같다.
```python
INSTALLED_APPS = [
  ...
  ...
  'doapp.apps.DoappConfig',
]
```
#### App 폴더 내에 "templates" 폴더 만들기
- templates 폴더에는 html file들이 담기게 된다. (실제로 화면에 보여지는 부분)

- App 폴더 내에 views.py는 html file들이 언제 어떻게 처리될지 정의하는 함수를 작성하는 부분이다.
- Project 폴더 내에 url.py는 위의 html file들이 어떤 url을 입력했을 때 화면으로 보이게 할지 정의하는 부분이다.
  - "**import app이름.views**"를 해주어 views.py에 있는 함수를 사용할 수 있게 import한다.
```python
from ...
from ...
import doapp.views

urlpatterns = [
  path('admin/', admin.site.urls),          # 1
  path('', doapp.views.home, name="home"),  # 2
]
```
- 1번 line: 서버를 구동하고 주소창 끝에 "admin/"을 붙여 엔터를 입력하면 admin.site.urls 화면으로 이동한다.  
admin/ 대신 home/이라고 할 경우 home/을 붙여야 이동가능하다.
- 2번 line: 아무것도 안쓰였을 때 doapp.views.home 즉 home.html 화면으로 이동한다.
### 요약
1. app을 settings.py를 통해 project에 연결한다.

2. app의 templates에 html 파일을 생성한다.

3. 만든 html 파일이 어떻게 처리될지를 알려주는 함수를 정의한다.

4. project의 url.py를 통해 만든 html파일을 url로 연결해준다.
