#include <iostream>

using namespace std;

string s1, s2;
int ns[1009][1009];

int main(){

    while(true){

        getline(cin, s1);
        if(s1 == "") break;
        getline(cin, s2);


        int n=s1.length(), m=s2.length();

        for(int i=0;i<=n;i++) for(int j=0;j<=m;j+=1) ns[i][j]=0;

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s2[j-1]) ns[i][j] = ns[i-1][j-1] + 1;
                else ns[i][j] = max(ns[i-1][j], ns[i][j-1]);
            }
        }

        cout << ns[n][m] << endl;

    }

    return 0;
}
