from django.shortcuts import render,redirect
from django.views.generic import ListView, DetailView
from django.views.generic.edit import CreateView, UpdateView, DeleteView
# Create your views here.
from .models import Movie
from django.urls import reverse_lazy
from .parser import parse_movie

def parse(request):
    parse_movie()
    return redirect('home')

class MovieList(ListView):
    model = Movie
    template_name = 'home.html'
class MovieCreate(CreateView):
    model = Movie
    fields =  '__all__'
    template_name = 'movie_form.html'
    success_url = reverse_lazy('home')
class MovieDetail(DetailView):
    model = Movie
    template_name = 'movie_detail.html'
class MovieUpdate(UpdateView):
    model = Movie
    fields =  '__all__'
    template_name = 'movie_form.html'
    success_url = reverse_lazy('home')
class MovieDelete(DeleteView):
    model = Movie
    template_name = 'movie_delete.html'
    success_url = reverse_lazy('home')