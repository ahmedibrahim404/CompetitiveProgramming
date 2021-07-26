#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int T, n, m, a1, a2;
int xs[750+9];
int ys[750+9];

struct road {
    int t1, t2, len;
};

road E[751*751];

int srt(road r1, road r2){
    return r1.len < r2.len;
}

struct disjoint_set {

    vector<int> parent;
    disjoint_set(int n){
        parent = vector<int>(n+1);
        for(int i=1;i<=n;i++) parent[i]=i;
    }


    int gparent(int n){
        if(parent[n] == n)
            return n;

        return parent[n] = gparent( parent[n] );
    }

    bool link(int a, int b){

        a = gparent(a), b=gparent(b);

        if(a != b){
            if(b > a) swap(a, b);
            parent[b] = a;
        }

        return a != b;

    }

};

int main(){
    cin >> T;

    while(T--){

        cin >> n;
        for(int i=0;i<n;i++) cin >> xs[i] >> ys[i];

        disjoint_set dis(n);
        cin >> m;
        int ad=0;
        while(m--){
            cin >> a1 >> a2;
            ad+=dis.link(a1, a2);
        }

        if(ad == n-1){
            cout << "No new highways need" << endl;
        } else {

        int len=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){

                E[len].t1 = i+1;
                E[len].t2 = j+1;
                E[len].len = (xs[i]-xs[j])*(xs[i]-xs[j]) + (ys[i]-ys[j])*(ys[i]-ys[j]);
                len++;
            }
        }

        sort(E, E+len, srt);
        for(int i=0;i<len;i++)
            if(dis.link(E[i].t1, E[i].t2)){
                cout << E[i].t1 << " " << E[i].t2 << endl;
            }

        }


        if(T>0)
            cout << "" << endl;

    }

    return 0;
}
