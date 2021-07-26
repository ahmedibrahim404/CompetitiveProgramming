#include<bits/stdc++.h>
using namespace std;
int n,t=1;
char s[300001];
int main(){
	scanf("%d%s",&n,s+1);
	for(int i=2;i<=n;++i){
		if(s[i]<s[i-1]){
			printf("YES\n%d %d",i-1,i);
			return 0;
		}
	}
	printf("NO");
}
