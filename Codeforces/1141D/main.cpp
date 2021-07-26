#include <bits/stdc++.h>
using namespace std;

int n,i;

string s,t;

stack<int> l[256],r[256],a,b;

#define c(x,y) for(;!x.empty()&&!y.empty();)a.push(x.top()),b.push(y.top()),x.pop(),y.pop();

int main(){

	for(cin>>n>>s>>t;i<n;i++)l[s[i]].push(i),r[t[i]].push(i);

	for(i='a';i<='z';i++){c(l[i],r[i])c(l[i],r['?'])c(l['?'],r[i])}

	c(l['?'],r['?'])

	cout<<a.size()<<endl;

	for(;!a.empty();)cout<<a.top()+1<<" "<<b.top()+1<<"\n",	a.pop(),b.pop();
}
