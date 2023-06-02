#include <bits/stdc++.h>

using namespace std;

ifstream fin("alee.in");
ofstream fout("alee.out");

bool mat[1010][1010];
int L[1010][1010], n, m,
    start_x, start_y,
    end_x, end_y;

int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

int check(int i, int j) {
  return i >= 1 && i <= n && j >= 1 && j <= n;
}

void Lee(int a, int b) {

     queue<pair<int,int>> Queue;

     Queue.push(make_pair(a,b));

     L[a][b] = 1;

     while(!Queue.empty()) {

           int x = Queue.front().first;
           int y = Queue.front().second;
           Queue.pop();

           for (size_t i = 0; i < 4; i++) {
                int new_i = dx[i] + x;
                int new_j = dy[i] + y;
                if(check(new_i, new_j) && !mat[new_i][new_j] && !L[new_i][new_j]) {
                  L[new_i][new_j] = L[x][y] + 1;
                  Queue.push(make_pair(new_i,new_j));
                }
           }
     }
}

int main(int argc, char const *argv[]) {
  int x, y;
  fin>>n>>m;
  for(int i = 0; i < m; ++i) {
    fin>>x>>y;
    mat[x][y] = 1;
  }
  fin>>start_x>>start_y>>end_x>>end_y;

  Lee(start_x,start_y);

  fout<<L[end_x][end_y];
  return 0;
}
