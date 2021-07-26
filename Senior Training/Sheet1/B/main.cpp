#include<bits/stdc++.h>
using namespace std;

int n;
unordered_set<string> st;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    string str[n];
    for(int i=0;i<n;i++){
        cin >> str[i];
    }

    set<string> st;
    for(int i=n-1;i>=0;i--){
        if(st.find(str[i]) == st.end()){
            cout << str[i] << "\n";
            st.insert(str[i]);
        }
    }



    return 0;
}
