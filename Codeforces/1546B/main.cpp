#include<bits/stdc++.h>

using namespace std;

int t, n, m;



int main(){
    cin >> t;
    while(t--){
        cin >> n >> m;
        string str[n], str2;
        set<string> s1, s2;
        int c1[m][26], c2[m][26];

        memset(c1, 0, sizeof c1);
        memset(c2, 0, sizeof c2);

        for(int i=0;i<n;i++){
            cin >> str[i];
            for(int j=0;j<m;j++) c1[j][ str[i][j]-'a' ]++;
        }


        for(int i=0;i<n-1;i++){
            cin >> str2;
            for(int j=0;j<m;j++) c2[j][ str2[j]-'a' ]++;
        }

        for(int i=0;i<n;i++){
            int c3[m][26];
            for(int i=0;i<m;i++) for(int j=0;j<26;j++ ) c3[i][j] = c1[i][j];
            for(int j=0;j<m;j++) c3[j][ str[i][j]-'a' ]--;

            bool is=1;
            for(int i=0;i<m;i++) for(int j=0;j<26;j++ ) if(c3[i][j] != c2[i][j]){is=0;break;}
            if(is){
                cout << str[i] << endl;;
                break;
            }

        }


    }
    return 0;
}
