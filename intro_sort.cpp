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

void heap_sort(int *a, int n, int left)
{
    int tmp = n/2 - 1;

    for(int i = n/2 - 1 + left; i >= left; i--)
    {
        up(a, i, n);
    }

    for(int i = n - 1 + left; i >= left; i--)
    {
        swap(a[0], a[i]);
        up(a, left, i);
    }
}

void quick_sort(int *a, int left, int right, int count)
{
    if(count != 0){
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
        if (left<r) quick_sort(a, left, r, count-1);
        if (l<right) quick_sort(a, l, right, count-1);
    }
    else{
        if (left<r) heap_sort(a, r - left + 1, left);
        if (l<right) heap_sort(a, right - l +1, l);
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
