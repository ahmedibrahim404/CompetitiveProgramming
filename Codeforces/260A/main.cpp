#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a, b, n;
vector<ll> ns;
int main(){

    scanf("%d %d %d", &a, &b, &n);

	for(int i=0;i<10;i++){

		if((a*10+i)%b==0){
			//cout<<a*10+i<<" "<<c<<endl;
			cout<<a<<i;
			for(int j=0;j<n-1;j++)cout<<'0';
			return 0;
		}

	}

	cout<<-1;

    return 0;
}
