#include <iostream>

using namespace std;
const int N=100000+3;
typedef pair<int, int> pi;
pi tree[262144 + 3];
string str;
pi build(int st, int en, int p=1){

    if(st==en){
        if(str[st]=='(') return tree[p]=pi(1, 0);
        return tree[p]=pi(0, 1);
    }

    int mid=(st+en)/2;
    pi p1 = build(st, mid, 2*p);
    pi p2 = build(mid+1, en, 2*p+1);

    int re;
    re=min(p1.first, p2.second);
    p1.first -= re;p2.second-=re;
    pi p3=pi(p1.first+p2.first, p1.second+p2.second);
    return tree[p] = p3;

}

int l, r;
pi check(int st, int en, int p){

    if(st >= l && en <= r) return tree[p];

    int mid=(st+en)/2;
    if(r <= mid) return check(st, mid, 2*p);
    if(l > mid) return check(mid+1, en, 2*p+1);

    pi p1=check(st,mid,2*p);
    pi p2=check(mid+1,en,2*p+1);

    int re;
    re=min(p1.first, p2.second);
    p1.first -= re;p2.second-=re;
    pi p3=pi(p1.first+p2.first, p1.second+p2.second);
    return p3;


}

int n;
int main(){
    cin >> str;
    n=str.length();
    build(0, n-1, 1);

    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        l=a-1;r=b-1;
        pi c=check(0, n-1, 1);
        cout << c.first << " " << c.second << "\n";
    }

    return 0;
}
