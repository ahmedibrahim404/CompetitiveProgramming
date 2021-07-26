#include <iostream>

using namespace std;
typedef long long ll;
const int N = 1 << 17;

struct bitRange {

    ll m[N], c[N];

    void init(){
        // memset
    }

    void add(int pos, ll mVal, ll cVal){
        for(++pos; pos <= N; pos += (pos & (-pos))){
            m[pos-1] += mVal;
            c[pos-1] += cVal;
        }
    }

    ll get(int pos){
        ll ret=0;
        int x=pos;
        for(++pos; pos; pos -= (pos & (-pos))){
            ret += m[pos-1] * x + c[pos-1];
        }
        return ret;
    }

    void addRange(int st, int en, ll val){
        add(st, val, -val*(st-1));
        add(en+1, -val, val*en);
    }

};


int main(){

    bitRange bit;
    bit.addRange(7, 10, 3);
    for(int i=0;i<12;i++){
        printf("%d %lld\n", i, bit.get(i));
    }

    return 0;
}
