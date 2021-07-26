#include<bits/stdc++.h>

using namespace std;

const int N = 1 << 12;

struct BIT {

    int tree[N];

    void init(){
        memset(tree, 0, sizeof tree);
    }

    void add(int pos, int val){
         for(++pos; pos <= N; pos += (pos & (-pos))){
            tree[pos-1] += val;
         }
    }

    int get(int pos){ // log(n)
        int ret=0;
        for(++pos; pos; pos -= (pos & (-pos))){
            ret += tree[pos-1] ;
        }
        return ret;
    }

    int find(int t){ // log(N)
        int st=0;
        for(int sz = N >> 1;sz ; sz >>= 1){
            if(tree[st+sz-1] < t){
                t-=tree[st+sz-1];
                st += sz;
            }
        }
        return st;
    }

};

struct multiSet {

    BIT bit;
    multiSet(){
        bit.init();
        bit.add(0, -1);
    }

    void insert(int val){
        bit.add(val, 1);
    }

    void erase(int val){
        bit.add(val, -1) ;
    }

    int count(int val){
        return bit.get(val) - bit.get(val-1);
    }

    int size(){
        return bit.get(N-1) + 1;
    }

    int at(int idx){
        return bit.find(idx);
    }

};




int main(){

    multiSet ms;

    while(true){
        int x, y;
        cin >> x >> y;
        if(x==1){
            ms.insert(y);
        } else if(x==2) {
            if(ms.count(y))ms.erase(y);
        } else {
            cout << ms.at(y) << "\n";
        }
    }
    return 0;
}
