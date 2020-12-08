#include <iostream>
#include <ctime>
#include <algorithm>
#include <random>
using namespace std;

void sort(int* arr, int n){
    sort(arr, arr+n);
    
}

void up(int *a, int s, int m)
{
    int tmp, b, e;

    while(s < m)
    {
        tmp = s;
        b = 2*s + 1;
        e = b + 1;

        if (b < m && a[b] > a[tmp])
            tmp = b;
        if (e < m && a[e] > a[tmp])
            tmp = e;
        if (tmp == s) return;
        swap(a[s], a[tmp]);
        s = tmp;
    }
}

void heap_sort(int *a, int n)
{
    int tmp = n/2 - 1;
    
    for(int i = n/2 - 1; i >= 0; i--)
    {
        up(a, i, n);
    }
    
    for(int i = n - 1; i >= 0; i--)
    {
        swap(a[0], a[i]);
        up(a, 0, i);
    }
}

int main(){
    int n;
    int tmp;
    cin>>n;
    int a[n];
    int a1[n];
    for(int q = 0; q < 100; q++){
    for(int i = 0; i < n; i++){
        tmp = rand()%1000;
        a[i] = tmp;
        a1[i] = tmp;
    }


    unsigned int start_time =  clock();
    heap_sort(a, n); 
    unsigned int end_time = clock(); 
    unsigned int search_time = end_time - start_time;
    cout << search_time << " ms" << endl;
    sort(a1, n);
    bool flag = true;
    for(int i = 0; i < n; i++){
       if(a[i]!=a1[i]){
           flag = false;
       }
    }
      
    if(flag){
       cout << "OK" << endl;
    }
      
    else{
       cout << "NO" << endl;
    }
    }
    return 0;

}
