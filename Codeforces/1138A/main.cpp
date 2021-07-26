#include<bits/stdc++.h>
using namespace std;
int n,A[100010];
int main(){
	int i;
	scanf("%d",&n);
	int Las=0,Ans=0,sum=0;
	for (i=1;i<=n;i++){
		scanf("%d",&A[i]);
		if (A[i]!=A[i-1]){
			Las=sum;
			sum=1;
		}else{
			sum++;
		}
		Ans=max(Ans,min(Las,sum));
	}
	printf("%d\n",Ans*2);
	return 0;
}
