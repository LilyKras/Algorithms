#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

vector<vector<int> > G;
queue <int> q;
vector <int> visited;




void bfs (int s) {
    q.push(s);

    visited[s] = 1;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
    for (size_t i=0; i<G[v].size(); ++i) {
        int to = G[v][i];
        if (!visited[to]) {
            q.push(to);
            visited[to] = 1;
      
           
        }

    }
}
}
int main() {
    //вводится матрица смежности 

    int n;
    cin >> n;
    G.resize(n);
    visited.resize(n);
    for(int i = 0; i < n; i ++){
         for(int j = 0; j < n; j ++){
            int a;
            cin >> a;
            if(a == 1){
                G[i].push_back(j);}
         }
    }
    int x;
    cin >> x;
    bfs(x-1);
}
