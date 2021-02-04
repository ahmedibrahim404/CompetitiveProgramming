#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 2e5 + 5;
vector<int> colors[4];
set<int> cant;

int p[MAX];
int a[MAX];
int b[MAX];

int main(){

  int n;cin >> n;

  for (int i = 0;i<n;i++) cin >> p[i];
  for (int i = 0;i<n;i++) cin >> a[i];
  for (int i = 0;i<n;i++) cin >> b[i];

  for (int i = 0; i < n; ++i) {
    colors[a[i]].push_back(p[i]);
    colors[b[i]].push_back(p[i]);
  }

  for (int i = 1; i <= 3; ++i) {
    sort(colors[i].begin(), colors[i].end(), greater<int>());
  }

  int m;
  cin >> m;

  while (m--){
    int col;
    cin >> col;

    while (!colors[col].empty() && cant.find(colors[col].back()) != cant.end()) {
      colors[col].pop_back();
    }

    if (colors[col].empty()){
      cout << "-1 ";
      continue;
    }

    cout << colors[col].back() << ' ';
    cant.insert(colors[col].back());
    colors[col].pop_back();
  }

}
