/*---------------------------*\
____________Mari000____________
________Mostafa  Shehab________
\*---------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define PI  3.14159265
#define EPS (1e-10)
#define endl "\n"
typedef long long ll;
typedef long double ld;

ll power(ll x,ll y,ll p);
int Bit(ll x);
ll sum(ll x);


void Fast(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
inline int D(){
	int t;
	scanf("%d",&t);
	return t;
}
inline ll llD(){
	ll t;
	scanf("%lld",&t);
	return t;
}

const int N=1e6 + 10;

ll arr[N],gc;
int n,m,z;

ll gcd(ll x,ll y){
	if(!y)
		return x;
	return gcd(y,x%y);
}
vector<bool> vec;
int ev,od,ev2,od2;
void BBit(ll x){
	if(!x)
		return;
	BBit(x>>1);
	vec.push_back((x&1));
}
vector<int> vee;

int main(){
	int n=D(),r=Bit(n),count=0,x=(1<<r)-1;

//    cout << r << endl;

	for(int i=r-1;i>=0;--i)
		if(!((1<<i) & n)){
			vee.push_back(i+1),n^=((1<<(i+1)) - 1),++count;
			if(n<x)
				++n,++count;
		}



	printf("%d\n",count);
	for(int i=0;i<vee.size();++i)
		printf("%d ",vee[i]);



}










ll power(ll x,ll y,ll p){
    ll res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p
    while (y > 0){
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

int Bit(ll x){
	if(!x)
		return 0;
	return 1+Bit(x>>1);
}

ll sum(ll x){
	return x*(x+1)/2;
}












