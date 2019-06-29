#include <iostream>

using namespace std;

int n, ns[27];
string s;
int main(){
    cin >> n;

    while(n--){
        cin >> s;
        ns[s[0]-'a']++;
    }

    int total=0;
    for(int i=0;i<26;i++){

        int left=ns[i]/2;
        int right=ns[i]/2+(ns[i]%2);

        total+=(left*(left-1)/2)+(right*(right-1)/2);

    }

    cout << total << endl;

    return 0;
}
