#include <iostream>

using namespace std;
const int MAX=1e5 + 3;
int n, q;
char str[MAX];
int main(){
    scanf("%d%d",&n,&q);
    scanf("%s", str);
    int freq[n];
    for(int i=0;i<n;i++){
        freq[i] = str[i]-'a'+1;
        if(i) freq[i] += freq[i-1];
    }
    while(q--){
        int l, r;
        scanf("%d%d",&l,&r);r--;l--;
        printf("%d\n", freq[r] - (l ? freq[l-1] : 0));
    }
    return 0;
}
