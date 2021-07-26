#include <iostream>
#include <cmath>

using namespace std;

int ns[100000+9];

int answer(int a, int n){

    int start=0, end=n, ans;
    int mid;
    while(start <= end){
        mid = (start+end)/2;
        if(a <= ns[mid]) ans=mid, end=mid-1;
        else start=mid+1;

    }
    return ans;
}

int main()
{

	int tcases, I, J, K, N, n, m, cnt = 0, len, q;

    scanf("%d", &n);
	for(I = 1; I <= n; I++)
		scanf("%d", &ns[I]);

	for(I = 2; I <= n; I++)
		ns[I] += ns[I - 1];


	scanf("%d", &m);
	for(I = 0; I < m; I++)
	{
		scanf("%d", &q);
		printf("%d\n",answer(q, n));
	}

	return 0;
}
