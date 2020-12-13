import random
import subprocess
#import numpy as np
#import pandas as pd
#import matplotlib.pyplot as plt

print("1 shellsort\n2 quicksort\n3 heapsort\n4 introsort")
ans = int(input())
sort_name=""
if (ans==1):
    sort_name="shell_sort"
elif(ans==2):
    sort_name="qsort"
elif(ans==3):
    sort_name="heap_sort"
elif(ans==4):
    sort_name="intro_sort"
count=0
time_arr = []
counte_arr = []
tests = 100
n = 1000

for i in range(tests):
    counte_arr.append(n)
    file = open("input.txt", 'w')
    file.write(str(n)+"\n")
    for j in range(n):
        file.write(str(random.randint(-2000000000, 2000000000))+" ")
    file.write("\n")
    file.close()
    subprocess.run([sort_name + '.exe', '-o', sort_name + '.o'])
    file = open("output.txt", 'r')
    start_values  = list(map(int, file.readline().split()))
    result_values = list(map(int, file.readline().split()))
    time = int(file.readline())
    file.close()
    
    sort_arr = sorted(list(map(int, start_values)))
    if(sort_arr == result_values):
        count +=1
        time_arr.append(time)
    n += 1000
        
print("Correct:", count, "/", tests,"\n")
#plt.plot(counte_arr, time_arr)
#plt.legend("Зависимость времени в мс от колва элементов")
#plt.show()
