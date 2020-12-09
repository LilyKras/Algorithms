#include <iostream>
#include <ctime>
#include <algorithm>
#include <random>
#include <fstream>
#include <time.h>

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
    heap_sort(a, n);
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;

    for (int i = 0; i < n; i++) {
        fout << a[i] << " ";
    }
    fout << endl;
    fout << search_time << endl;

    return 0;

}
