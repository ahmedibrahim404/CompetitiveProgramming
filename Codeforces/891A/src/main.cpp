#include <iostream>
using namespace std;

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

int n, ns[2000];
int main() {

	scanf("%d", &n);
	for(int i=0;i<n;i++) scanf("%d",&ns[i]);

	int mn=2e9, tot=0;
	for(int i=0;i<n-1;i++){
		tot=0;
		bool is=0;
		int a=ns[i], b=ns[i+1];
		if(a > b) swap(a, b);
		while(a != 1){
			a=gcd(a, b);
			if(a == b) is=1;
			tot++;			
		}
		if(tot < mn && is==0) mn=tot;
	}

	printf("%d", mn+n-1);

}