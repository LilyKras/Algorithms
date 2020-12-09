#include <iostream>
#include <ctime>
#include <algorithm>
#include <random>
#include <fstream>
using namespace std;

void quick_sort(int* A, int L, int R) {
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
  quick_sort(A, L, x);
  quick_sort(A, y, R);
}

int main(){
    int n;
    int tmp;
    ifstream fin;
    fin.open("input.txt");
    fin >> n;
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
    quick_sort(a, 0, n);
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;

    for (int i = 0; i < n; i++) {
        fout << a[i] << " ";
    }
    fout << endl;
    fout << search_time << endl;

    return 0;

}
