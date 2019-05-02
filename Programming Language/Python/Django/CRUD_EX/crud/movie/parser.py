# https://beomi.github.io/gb-crawling/posts/2017-03-01-HowToMakeWebCrawler-Save-with-Django.html
from bs4 import BeautifulSoup
import urllib.request
import os
from django.core.files import File
from django.conf import settings

from .models import Movie

def parse_movie():
    movies = []
    ##### 크롤링 시작
    url = urllib.request.urlopen("https://movie.naver.com/movie/running/current.nhn")
    bs = BeautifulSoup(url, 'html.parser')
    body = bs.body
    target = body.find(class_="lst_detail_t1")
    list = target.find_all('li')
    no = 1
    iteration = min(100,len(list))
    for n in range(0, iteration) :
        movie = {}
        no += 1
        # 영화 제목
        title = list[n].find(class_="tit").find("a").text.strip()
        movie['title']=title
        score = list[n].find(class_="star").find(class_="star_t1").find("a").find(class_='num').text.strip()
        movie['score']=score 
        

        # https://vinta.ws/code/read-and-save-file-in-django-python.html 이거만 보면 된다.
        # 포스터
        try:
            img_url = list[n].find(class_="thumb").find("a").find("img").get("src")
            # file_name = title+'.jpg'
            # img = Image.open(StringIO(img_url.content))
            # img_io = StringIO()
            # img.save(img_io, 'JPG', quality=100)
            # file_dir = settings.MEDIA_ROOT + file_name
            # resp = urllib.request.urlretrieve(img_url,file_dir)
            # Movie.image.save(file_name, ContentFile(img_io.getvalue()), save=False)
            # 참고 https://docs.djangoproject.com/en/2.2/ref/files/file/
            # Movie.image.save(file_name, img_url.content, save=False)
            # Movie.image.save(file_name, ContentFile(img_url.content), save=False)
            # with open(file_dir, 'rb') as f:
            #     Movie.image = File(f)
            
            
            movie['img_url'] = img_url
        except:
            pass

        
        # 개봉일/ 장르/ runtime
        try:
            # ['액션, SF', '181분', '2019.04.24 개봉']
            value = list[n].find(class_="info_txt1").find_all("dd")[0].text.replace("\n",'').replace("\t", "").replace('\r','').split('|')
            genre = [i.strip() for i in value[0].split(',')]
            movie['genre']=','.join(genre)
            length = int(value[1][:-1])
            movie['length']=length
            date = value[2].split()[0]
            movie['date']=date
        except IndexError:
            movie['genre']="데이터없음"
            movie['length']="데이터없음"
            movie['date']="데이터없음"
        # 감독
        try:
            director = list[n].find(class_="info_txt1").find_all("dd")[1].find("span").find_all("a")
            directorList = [director.text.strip() for director in director]
            movie['director']=','.join(directorList)
        except IndexError:
            movie['director']="데이터없음"
        # 출연 배우
        try:
            cast = list[n].find(class_="lst_dsc").find("dl", class_="info_txt1").find_all("dd")[2].find(class_="link_txt").find_all("a")
            castList = [cast.text.strip() for cast in cast]
            movie['actors']=','.join(castList)
        except IndexError:
            movie['actors'] = "데이터없음"
        
        
        movies.append(movie)
    
    for m in movies:
        Movie(title=m['title'],
        score=m['score'],
        genre=m['genre'],
        date = m['date'],
        length=m['length'],
        director=m['director'],
        actors = m['actors'],
        img_url = m['img_url'],
        ).save()
