#include <iostream>
#include <ctime>
#include <algorithm>
#include <random>
#include <fstream>
#include <cmath>


using namespace std;

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

void heap_sort(int *a, int s, int e)
{
    int tmp = (s-e+1)/2 - 1;

    for(int i = (s-e+1)/2 - 1; i >= s; i--)
    {
        up(a, i+s, (s-e+1));
    }

    for(int i = (s-e+1) - 1; i >= s; i--)
    {
        swap(a[s], a[i]);
        up(a, s, i);
    }
}

void quick_sort(int* A, int L, int R, int count) {
  if(count != 0){
      cout << count << " ";
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
      quick_sort(A, L, x, count-1);
      quick_sort(A, y, R, count-1);
  }
  else{
      heap_sort(A, L, R);
  }
}

int main(){
    int n;
    int tmp;
    ifstream fin;
    fin.open("input.txt");
    fin >> n;
    int count = 2*log(n);
    int a[n];
    for (int i = 0; i < n; i++) {
        fin >> a[i];
    }
    fin.close();

    ofstream fout;
    fout.open("output.txt");

    for (int i = 0; i < n; i++) {
        fout << a[i] << " ";
    }
    fout << endl;

    unsigned int start_time =  clock();
    quick_sort(a, 0, n, count);
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;

    for (int i = 0; i < n; i++) {
        fout << a[i] << " ";
    }
    fout << endl;
    fout << search_time << endl;

    return 0;

}
