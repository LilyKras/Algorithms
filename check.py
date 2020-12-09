import random
import subprocess

print("1 shellsort\n2 quicksort\n3 heapsort\n")
ans = int(input())
sort_name=""
if (ans==1):
    sort_name="shell_sort"
elif(ans==2):
    sort_name="qsort"
elif(ans==3):
    sort_name="heap_sort"
count=0
time_arr = []
tests=100
n = random.randint(1, 20000)

for i in range(tests):
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
        
print("Correct:", count, "/", tests,"\n")
print(*time_arr)
