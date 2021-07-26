#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
	int n,m=0;
	cin>>n;
	string s[n];
	for(int i=0;i<n;i++)cin>>s[i];
	char t;
	cin>>t;
	for(int i=0;i<n;i++)s[i]+=t,m+=s[i].size();
	m/=(n/2);
	sort(s,s+n);

	for(int i=0;i<n;i++)for(int j=i+1;j<n;j++){
		if(s[i].size()+s[j].size()==m){
			cout<<s[i];s[j]=s[j].substr(0, s[j].length()-1);cout << s[j] << endl;
			s[i]="";s[j]="";
			break;
		}
	}

	return 0;
}
