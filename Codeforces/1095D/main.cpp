#include<bits/stdc++.h>
using namespace std;
const int MAX=200000+3;
typedef pair<int, int> pi;
int n;
pi ns[MAX];
vector<int> vi;
int main(){
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d%d",&ns[i].first,&ns[i].second);
        ns[i].first--, ns[i].second--;
    }

    int i=0;

    vi.push_back(0);

    while(vi.size() < n){

        int fir=ns[i].first, sec=ns[i].second;

        if(ns[ fir ].first==sec || ns[ fir ].second == sec){

            vi.push_back(fir);
            vi.push_back(sec);
            i=sec;
        } else {

            vi.push_back(sec);
            vi.push_back(fir);
            i=fir;
        }

    }

    for(int i=0;i<n;i++){
        printf("%d ", vi[i]+1);
    }


    return 0;
}
