from django.shortcuts import render, redirect
import cgi, cgitb

# Create your views here. 함수 넣는 곳
def home(request):
    return render(request, 'home.html')    

def japan(request):
    return render(request, 'japan.html')

def result(request):
    form = cgi.FieldStorage()
    full_text1 = request.GET.get("fulltext1")
    exchanged_money = float(0)    

    value = request.GET.get("money")
    if full_text1 == None or value == "" :
        return redirect('japan')
    if value == "dollar" :
        exchanged_money = int(full_text1) * 0.00088
    elif value == "yen" :
        exchanged_money = int(full_text1) * 0.098

    return render(request, 'result.html', {'fulltext1' : full_text1, 'exchange' : exchanged_money, 'name' : value})
