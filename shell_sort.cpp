#include <iostream>
#include <ctime>
#include <algorithm>
#include <random>
#include <fstream>
using namespace std;

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
    shell_sort(a, n);
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;

    for (int i = 0; i < n; i++) {
        fout << a[i] << " ";
    }
    fout << endl;
    fout << search_time << endl;

    return 0;

}
