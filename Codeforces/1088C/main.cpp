#include<bits/stdc++.h>
using namespace std;
int to=1e5;
int main(){
	int n,a;
	cin>>n;
	printf("%d\n",n);
	printf("1 %d %d\n",n,to);
	for(int i=1;i<n;++i){
		cin>>a;
		printf("2 %d %d\n",i,a+to-i);
	}
}
