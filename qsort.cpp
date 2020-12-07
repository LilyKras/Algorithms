#include <iostream>
#include <ctime>
#include <algorithm>
#include <random>
using namespace std;

void sort(int* A, int n){
    sort(A, A+n);
    
}

void qsort(int* A, int L, int R) {
  if (R - L <= 1) {
    return;
  }
  int mid = A[L + rand() % (R - L)];
  int x = L, y = L;
  for (int i = L; i < R; i++) {
    if (A[i] < mid) {
      swap(A[i], A[x]);
      if (x != y) swap(A[i], A[y]);
      x++, y++;
    } else if (A[i] == mid) {
      swap(A[y], A[i]);
      y++;
    }
  }
  qsort(A, L, x);
  qsort(A, y, R);
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
			qsort(a, 0, n); 
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
