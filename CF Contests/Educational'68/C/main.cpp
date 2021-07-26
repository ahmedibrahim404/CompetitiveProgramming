#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
int q;
string s, t, p;
vvi ns;
vi fo;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> q;
    while(q--){
        cin >> s >> t >> p;
        ns=vvi(26);
        fo=vi(26);
        int l1=t.length(), l2=s.length(), l3=p.length();
        for(int i=0;i<l1;i++) ns[t[i]-'a'].push_back(i);
        int pre=0, re=0;
        bool c=0;
        for(int i=0;i<l2;i++){
            int ch=s[i]-'a';
            int idx=lower_bound(ns[ch].begin(), ns[ch].end(), pre)-ns[ch].begin();
            if(ns[ch].size() > idx){
                pre=ns[ch][idx];
                t.erase(t.begin()+pre-re);
                re++;
                pre++;
            }
            else{
                c=1;
                break;
            }
        }

        if(c==0){

        for(int i=0;i<l3;i++){
            fo[ p[i]-'a' ]++;
        }

        int nl=t.length();
        for(int i=0;i<nl;i++){
            if(fo[ t[i]-'a' ]) fo[ t[i]-'a' ]--;
            else {
                c=1;
                break;
            }
        }


        }

        if(!c) cout << "YES" << endl;
        else cout << "NO" << endl;


    }
    return 0;
}
