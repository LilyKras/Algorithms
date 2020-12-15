#include <iostream>
#include <ctime>
#include <algorithm>
#include <random>
#include <fstream>
using namespace std;
void quick_sort(int *a, int left, int right)
{
    int r = right, l = left;
    int elem = a[ l + rand() % (r - l + 1)];;
    do
    {
        while (a[l]<elem) l++;
        while (a[r]>elem) r--;
        if (l <= r) 
        {
            swap(a[l], a[r]);
            l++;
            r--;
        }
    } while (l<r);
    if (left<r) quick_sort(a, left, r);
    if (l<right) quick_sort(a, l, right);
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
    quick_sort(a, 0, n-1);
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;

    for (int i = 0; i < n; i++) {
        fout << a[i] << " ";
    }
    fout << endl;
    fout << search_time << endl;

    return 0;
}
