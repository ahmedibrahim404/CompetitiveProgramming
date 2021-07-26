#pragma GCC optimize ("O3")
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <deque>
#include <math.h>
#include <cstring>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
#include <queue>
#include <stack>
#include<cassert>
#include <cfloat>
#include <list>
using namespace std ;
#define ll long long
void FastInputOutput(){
    ios_base :: sync_with_stdio( 0 ) ;
    cin.tie( 0 ) ;
    cout.tie( 0 ) ;
}

inline int D(){
    int t ;
    scanf( "%d" , &t ) ;
    return t ;
}
inline ll LLD(){
    ll t ;
    scanf( "%lld" , &t ) ;
    return t ;
}
inline ll power(ll x, ll p, ll m){
    ll res = 1;
    while(p){
        if(p & 1)
            res = ((res % m) * (x % m)) % m;
        x = ((x % m) * (x % m)) % m;
        p >>= 1;
    }
    return res % m;
}
long double ModLog(long double base, long double x) {
    return (logl(x) / logl(base));
}
ll gcd(ll a, ll b){
    if(!b)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}
const ll P = 1e9 + 9;
const int N = 1e6 + 1;

char a[N];

struct lyric{
    int l11,l12,l21,l22;
};

struct word{
    int idx, cntVo;
    char lastVo;
};
bool isV(char c){
    return c == 'a' || c == 'e' || c == 'o' || c == 'u' || c == 'i';
}


int main(){

    int n = D();
    vector<string> allWords;
    map<char, int> mp = {{'a', 0}, {'e', 1},{'o', 2},{'u', 3},{'i', 4}};
    map<int, set<pair<int, char>>> SameLen;
    map<pair<int, char>, set<int>> sameLenAndLast;
    for(int w = 0; w < n; ++w){
        scanf("%s", a);
        allWords.push_back(a);
        int cnt = 0;
        char last = 'z';
        for(int i = 0; a[i]; ++i)
            if(isV(a[i]))
                ++cnt, last = a[i];

        SameLen[cnt].insert({w, last});
        sameLenAndLast[{cnt, last}].insert(w);
    }

    vector<int> allSmSm;
    for(auto ele : sameLenAndLast){
        if(ele.second.size() & 1)
            ele.second.erase(ele.second.begin());
        if(ele.second.size() <= 1)
            continue;

        for(auto s : ele.second){
            allSmSm.push_back(s);
            if(SameLen[ele.first.first].count({s, ele.first.second}))
                SameLen[ele.first.first].erase({s, ele.first.second});
        }
    }

    vector<lyric> ans;
    for(auto s : SameLen){
        vector<pair<int, int>> v(s.second.begin(), s.second.end());
        while (v.size() >= 2 && allSmSm.size() >= 2) {
            lyric t;
            t.l11 = v.back().first;
            v.pop_back();
            t.l21 = v.back().first;
            v.pop_back();
            t.l12 = allSmSm.back();
            allSmSm.pop_back();
            t.l22 = allSmSm.back();
            allSmSm.pop_back();
            ans.push_back(t);
        }
    }

    while (allSmSm.size() >= 4) {
        lyric t;
        t.l11 = allSmSm.back();
        allSmSm.pop_back();
        t.l21 = allSmSm.back();
        allSmSm.pop_back();
        t.l12 = allSmSm.back();
        allSmSm.pop_back();
        t.l22 = allSmSm.back();
        allSmSm.pop_back();
        ans.push_back(t);
    }
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); ++i){
        printf("%s %s\n", allWords[ans[i].l11].c_str(), allWords[ans[i].l12].c_str());
        printf("%s %s\n", allWords[ans[i].l21].c_str(), allWords[ans[i].l22].c_str());
    }

}
