#include<bits/stdc++.h>
using namespace std;

string a, b, c;
map< string, int > mp2;
int ns[28][19];
int main(){
    for(int i=0;i<28;i++) for(int j=0;j<19;j++) ns[i][j]=0;
    cin >> a >> b >> c;
    mp2[a]++, mp2[b]++, mp2[c]++;

    int mx=0;
    mx=max(mp2[a], max(mp2[b], mp2[c]));

    int f1=a[0]-'0',f2=b[0]-'0', f3=c[0]-'0';
    ns[a[1]-'a'][f1]++;
    ns[b[1]-'a'][f2]++;
    ns[c[1]-'a'][f3]++;

    for(int i=0;i<=26;i++){
        for(int j=0;j<=9;j++){
            mx=max(mx, (ns[i][j]?1:0)+(ns[i][j+1]?1:0)+(ns[i][j+2]?1:0) );
        }
    }

    cout << max(3-mx,0) << endl;

    return 0;
}
