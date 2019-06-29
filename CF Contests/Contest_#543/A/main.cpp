#include <iostream>

using namespace std;
int a[110],b[110];
int main(){
	int i,j,n,m,k,ans = 0;
	cin >> n >> m >> k;
	for(i=0;i<n;i++) cin >> a[i];
	for(i=0;i<n;i++){
		cin >> b[i];
	}
	for(i=0;i<k;i++){
		int x; cin >> x; x--;
		for(j=0;j<n;j++){
			if(b[j]==b[x] && a[j]>a[x]){
				ans++;
				break;
			}
		}
	}
	cout << ans << endl;
}
