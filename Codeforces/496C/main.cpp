#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

void remove( vector<string> &input, int c) {
  for (int i = 0; i < input.size(); ++i)
    input[i].erase(input[i].begin()+c);
}

int main(){

  int n, m, cols;

  cin>>n>>m;

  vector<string> input(n);

  for (int i = 0; i < n; ++i) cin>>input[i];

  cols = input[0].size();
\
  bool anyChange = true;

  while(anyChange) {
    anyChange = false;
    for (int i = 0; !anyChange && i < n-1; ++i) {
      for (int j = 0; !anyChange && j < input[i].size(); ++j) {
        if(input[i][j] > input[i+1][j]) {
              anyChange = true;
              remove(input, j);
        } else if(input[i][j] < input[i+1][j]) break;
      }
    }
  }

  cout<<cols - (int)input[0].size();

  return 0;
}
