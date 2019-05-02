from django.contrib import admin
from django.urls import path
import movie.views
urlpatterns = [
    path('admin/', admin.site.urls),
    path('',movie.views.MovieList.as_view(),name="home"),
    path('parse',movie.views.parse,name="parse"),
    # 아래 부터 CRUD 4가지 
    # 영화를 생성할 url (Create)
    path('create/',movie.views.MovieCreate.as_view(),name="create"),
    # 각 영화 detail url(Read)
    path('detail/<int:pk>',movie.views.MovieDetail.as_view(),name="detail"),
    # 영화를 수정할 url (Update)
    path('update/<int:pk>',movie.views.MovieUpdate.as_view(),name="update"),
    # 영화를 제거할 url (Delete)
    path('delete/<int:pk>',movie.views.MovieDelete.as_view(),name="delete"),
]