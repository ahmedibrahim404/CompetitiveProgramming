#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int>pi;
int T, N;
int main(){
    cin >> T;
    while(T--){
        cin >> N;
        pi ns[N];
        string str;
        for(int i=0;i<N+1;i++){
            getline(cin, str);
//            cout << "STR IS " << str << endl;
            istringstream is(str);
            int no, cnt=0;
            while(is>>no){
                cnt++;
            }
            ns[i].first=cnt, ns[i].second=i;
        }
        sort(ns+1, ns+N+1);
        int idx=2;
        cout << ns[1].second;
        while(ns[idx].first==ns[idx-1].first){
            cout << " " << ns[idx].second;
            idx++;
        }
        cout << endl;
    }
    return 0;
}
