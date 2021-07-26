#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int T;
int n, m;
char str1[100], str2[100];

int ns[1000][1000], pp[1000][1000];

map< string, int > mp;
map< int, string > mp2;


void printPath(int i, int j){
    if(i != j) printPath(i, pp[i][j]);
    cout << mp2[j][0];
}


int main(){

    scanf("%d", &T);

    while(T--){

        scanf("%d %d", &m, &n);

        mp.clear();
        mp2.clear();


        for(int i=0;i<1000;i++) for(int j=0;j<1000;j++) ns[i][j]=1e8, pp[i][j] = i;

        mp["Rome"] = 0;
        mp2[0] = "Rome";
        int idx=1;

        for(int i=0;i<m;i++){
            scanf("%s %s", str1, str2);

            string s1=string(str1), s2=string(str2);

            if(!mp.count( s1 )) mp[s1] = idx, mp2[ idx ] = s1, idx++;;
            if(!mp.count( s2 )) mp[s2] = idx, mp2[ idx ] = s2, idx++;;

            ns[ mp[s2] ][ mp[s1] ] = 1;
            ns[ mp[s1] ][ mp[s2] ] = 1;

        }


        for(int k=0;k<idx;k++) for(int i=0;i<idx;i++) for(int j=0;j<idx;j++) {

            if( ns[i][k] < 1e8 && ns[k][j] < 1e8 ){

                if( ns[i][k] + ns[k][j] < ns[i][j] ){

                    ns[i][j] = ns[i][k] + ns[k][j], pp[i][j] = pp[k][j];;

                }

            }

        }

        for(int i=0;i<n;i++){

            scanf("%s %s", str1, str2);

            string s1=string(str1), s2=string(str2);
            printPath(mp[s1], mp[s2]);
            cout << endl;

        }

        if(T) cout << endl;

    }



    return 0;
}
