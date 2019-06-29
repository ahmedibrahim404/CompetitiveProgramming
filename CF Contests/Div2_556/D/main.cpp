#include <iostream>

using namespace std;
int n, q;
string s;
int ns[26], gr, rs[3][26];
char t, ch;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> q >> s;
    for(int i=0;i<n;i++) ns[s[i]-'a']++;

    for(int i=0;i<q;i++){
        cin >> t >> gr;

        if(t == '+'){
            cin >> ch;
            rs[gr-1][ch-'a']++;
            for(int j=0;j<26;j++){
                if(rs[0][j]+rs[1][j]+rs[2][j] > ns[j]) cout << "NO" << endl;
            }
        } else {



        }

    }

    return 0;
}
