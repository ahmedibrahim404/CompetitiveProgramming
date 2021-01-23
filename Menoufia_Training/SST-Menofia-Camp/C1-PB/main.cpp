#include<bits/stdc++.h>
using namespace std;
const int MAX=1e3+3;
struct group {
    int x, y, z;
} gs[MAX];

bool cpr(group g2, group g1){
    if(g2.y > g1.y) return 1;
    if(g2.y == g1.y && g2.x < g1.x) return 1;
    return 0;
}


int n, m;
vector<pair<int, int>> no;
bool took[MAX];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&gs[i].x, &gs[i].y);
        gs[i].z=i+1;
    }
    scanf("%d",&m);
    no=vector<pair<int, int>>(m);
    for(int i=0;i<m;i++){
        scanf("%d",&no[i].first);
        no[i].second=i+1;
        took[i]=0;
    }
    sort(no.begin(), no.end());
    sort(gs, gs+n, cpr);

    int total=0, non=0;
    string str="";
    for(int i=0;i<n;i++){
        int nx=gs[i].x, ny=gs[i].y, nz=gs[i].z;
        int need=lower_bound(no.begin(), no.end(), pair<int, int>(nx, -1e9))-no.begin();
        if(need==no.size()) continue;
        total += ny;
        str += to_string(nz) + " " + to_string(no[need].second) + "\n";
        non++;
        no.erase(no.begin()+need);
    }

    cout << non << " " << total << endl;
    cout << str << endl;


    return 0;
}
