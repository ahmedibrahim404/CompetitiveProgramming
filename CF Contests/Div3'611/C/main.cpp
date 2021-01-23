#include <iostream>

using namespace std;

int n, ns[200000+3], v[200000+3];
bool is[200000+3];
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> ns[i];
        is[ ns[i] ]=1;
    }

    int idx=0;
    for(int i=1;i<=n;i++){
        if(!is[i]) v[idx++]=i;
    }

    int cur=0;
    for(int i=0;i<n;i++){
        if(ns[i]==0){
            if((i+1)==v[cur]){
                if(cur==idx-1) swap(v[cur], v[cur-1]);
                else swap(v[cur], v[cur+1]);
            }
            cur++;
        }
    }

    cur=0;
    for(int i=0;i<n;i++){
        if(!ns[i]) {ns[i]=v[cur];cur++;}
        cout << ns[i] << " ";
    }



    return 0;
}
