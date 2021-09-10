#include <iostream>

using namespace std;

string s;

int main(){
    cin >> s;
    int n=s.length();
    int sum=0;
    int mx=0;
    for(int i=0;i<n;i++){
        int num=s[i]-'0';
        if(num != 0) mx=max(mx, num - 1 + 9 * (n-i-1));
        sum += s[i]-'0';
    }
    mx=max(mx, sum);
    printf("%d\n", mx);
    return 0;
}
