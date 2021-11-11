#include<bits/stdc++.h>
using namespace std;

const int MAX = 100000 + 3;

const int N = 1 << 17 + 1;
int lg[N];
int sp[18][N];
vector<int> v;
vector<int> q;

void init(){
    lg[0]=-1;
    for(int i=0;i<v.size();i++){
        lg[i+1] = lg[i] + !(i & (i+1));
        sp[0][i] = v[i];
    }
}

void buildSP(){
    for(int j=1;(1<<j) <= v.size();j++){
        for(int i=0;i+(1<<(j-1)) <= v.size();i++){
            int a = sp[j-1][i];
            int b = sp[j-1][i+(1<<(j-1))];
            sp[j][i] = __gcd(a, b);
        }
    }
}
int getGCD(int st, int en){
    int sz=en-st+1;
    int l = lg[sz];
    int a = sp[l][st];
    int b = sp[l][en - (1<<l) + 1 ];
    return __gcd(a, b);
}
int main(){
    int n;cin >> n;

    for(int i=0;i<n;i++){
        char c;cin >> c;
        if(c == '+'){
            int num;cin >> num;
            q.push_back(0);
            v.push_back(num);
        } else if(c == '?'){
            q.push_back(1);
        } else {
            q.push_back(2);
        }
    }

    init();
    buildSP();


    multiset<int> st;
    int start=0, idx=0;
    for(int i=0;i<n;i++){
        if(q[i] == 0) {
            st.insert(v[idx]);
            idx++;
        } else if(q[i] == 1){
            int gc = getGCD(start, idx-1);
            if(st.find(gc) != st.end()) cout << "Y" << gc << "\n";
            else cout << "N\n";
        } else {
            st.erase(st.find(v[start++]));
        }
    }


    return 0;
}
