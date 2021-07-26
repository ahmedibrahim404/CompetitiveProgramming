#include <iostream>

using namespace std;
typedef long long ll;
ll n, k;

ll sum(ll n)
{
	return (n * (n+1)) / 2;
}

// sum: s s+1 s+2 ... e
ll sum(ll s, ll e)
{
	if(s <= 1)
		return sum(e);

	return sum(e) - sum(s-1);
}

ll BS(){

    ll start=1, end=k;
    ll mid, sol;

    //

    while(end > start){

        mid = (start+end)/2;

        ll s = sum(mid, k);

		if(s == n)
			return k - mid + 1;


        if(s > n)
			start = mid+1;
		else
			end = mid;


    }

    return k - start + 2;

}

int main(){
    cin >> n >> k;

    if( n == 1 ) {
        cout << 0 << endl;
        return 0;
    }

    if(k >= n) {
        cout << "1" << endl;
        return 0;
    }





    k--;
    n--;

    if(sum(k) < n) {
        cout << "-1" << endl;
        return 0;
    }


    cout << BS() << endl;

    return 0;
}
