#include <bits/stdc++.h>
using namespace std;

string ans[10000001];
string s[51];

int main(){
	int t,n,m;
	cin>>t;
	for(int i=0; i<t; i++){
		cin>>n>>m;
		for(int i=0; i<n; i++){
			cin>>s[i];
		}
		string ans="";
		for(int i=0; i<m; i++){
			for(int c='a'; c<='z'; c++){
				string t=s[0];
				t[i]=c;
				int e=1;
				for(int j=0; j<n; j++){
					int c=0;
					for(int k=0; k<m; k++){
						if(t[k]!=s[j][k])c++;
					}
					if(c>1)e=0;
				}
				if(e)
					ans=t;
			}
		}
		if(ans=="")
			cout<<-1<<endl;
		else cout<<ans<<endl;
	}
}
