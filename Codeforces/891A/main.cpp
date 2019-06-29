#include<iostream>
#include<algorithm>
using namespace std;
int n,arr[2010],one;

int func(){
	if(one)
		return n-one;
	for(int i = 1; i < n; i++){
		for(int j = 0; j+i<n; j++){
            arr[j]=__gcd(arr[j],arr[j+1]);
			if(arr[j]==1)
				return i+n-1;
		}
	}
	return -1;
}

int main(){
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>arr[i];
		if(arr[i]==1) one++;
	}
	cout<<func();
}