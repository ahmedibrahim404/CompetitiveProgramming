#include <iostream>
#include <map>
#include <sstream>
using namespace std;

string str[209];

int ns[209][209];

char st[11];
int N;

map<string, int> mp;
int main(){

    scanf("%d", &N);

    while(N--){

        mp.clear();
        for(int i=0;i<209;i++) for(int j=0;j<209;j++)
            ns[i][j]=1e8;

        int idx=0;
        while(scanf("%s", st) == 1){

            if(!string(st).compare("*")){
                break;
            }

            mp[string(st)]=idx;
            str[idx++]=string(st);
        }

        for(int i=0;i<idx;i++){
            for(int j=i+1;j<idx;j++){

                int cnt=0;
                string s1=str[i], s2=str[j];
                if(s1.length() != s2.length()) continue;
                for(int i=0;i<s1.length();i++){
                    if(s1[i] != s2[i]){
                        cnt++;
                    }
                }

                if(cnt == 1){
                    ns[ mp[s1] ][ mp[s2] ]=1;
                    ns[ mp[s2] ][ mp[s1] ]=1;
                }

            }
        }


        for(int k=0;k<idx;k++) for(int i=0;i<idx;i++) for(int j=0;j<idx;j++){

            if( ns[i][k] < 1e8 && ns[k][j] < 1e8 ){
                ns[i][j] = min( ns[i][j], ns[i][k]+ns[k][j] );
            }

        }



        cin.ignore();

        string line, s, t;
        while (getline(cin, line) && line != ""){
            stringstream ss(line);
            ss >> s >> t;
            cout << s << " " << t << " " << ns[  mp[s]  ][ mp[t] ] << endl;
        }

        if(N>1) cout << endl;


    }

    return 0;
}
