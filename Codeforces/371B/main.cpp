#include <iostream>

using namespace std;

int ans=0;
int a, b;
int f(int p){
	int c = 0, t = 0;
	while(a % p == 0){
		a /= p;
		c ++;
	}
	while(b % p == 0){
		b /= p;
		t ++;
	}
	ans += abs(t - c);
}

int main(){

	cin >> a >> b;

	f(3);
	f(2);
	f(5);

	if(a != b)cout<<-1;
	else cout<<ans;

    return 0;
}
