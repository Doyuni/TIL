from django.db import models

class Movie(models.Model):
    title = models.CharField(max_length=1000)
    director= models.CharField(max_length=1000)
    actors= models.CharField(max_length=1000)
    date= models.CharField(max_length=1000)
    length= models.IntegerField()
    score = models.FloatField()
    genre = models.CharField(max_length=1000)
    img_url = models.CharField(max_length=1000)