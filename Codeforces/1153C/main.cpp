#include<bits/stdc++.h>
#define maxn 600003
using namespace std;
char s[maxn];
int n,le;
void FAIL(){puts(":(");exit(0);}
int main(){
	scanf("%d%s",&n,s+1);
	if((n&1)||s[1]==')'||s[n]=='(')FAIL();
	s[1]='(',s[n]=')';
	for(int i=2;i<n;i++)if(s[i]=='(')le++;
	int top=0;
	for(int i=2;i<n;i++){
		if(s[i]=='(')top++;
		if(s[i]==')')top--;
		if(s[i]=='?'){
			if(le<((n-2)>>1))le++,top++,s[i]='(';
			else top--,s[i]=')';
		}
		if(top<0)FAIL();
	}
	if(top)FAIL();
	puts(s+1);
	return 0;
}
