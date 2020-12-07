#include <iostream>
#include <ctime>
#include <algorithm>
#include <random>
using namespace std;

void sort(int* arr, int n){
    sort(arr, arr+n);
    
}

void shell_sort(int* a, int n){
    for (int step = n / 2; step > 0; step /= 2) {
     for (int i = step; i < n; i++) {
       int j = i - step;
       while (j>=0 && a[j] > a[j + step]) {
         swap(a[j], a[j + step]);
         j -= step;
       }
     }
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
    shell_sort(a, n); 
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
