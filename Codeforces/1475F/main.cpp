#include <bits/stdc++.h>

using namespace std ;

const int MAX = 1000 + 10 ;

bool a[MAX][MAX] , b[MAX][MAX] ;
bool flip[MAX], flip2[MAX];
int n ;

bool solve()
{
	for(int j = 0 ; j < n ; ++j)
	{
	    flip2[j]=0;
		flip[j] = 0 ;
		if(a[0][j] != b[0][j])
			flip[j] = 1;
	}
	for(int j = 0 ; j < n ; ++j)
	{
		for(int i = 0 ; i < n ; ++i)
		{
		    if(flip[j]) a[i][j] ^= 1;
			if(a[i][j] != b[i][j]){
                flip2[i]=1;
			}
		}
	}
    for(int i = 0 ; i < n ; ++i)
	{
		for(int j = 0 ; j < n ; ++j)
		{
		    if(flip2[i]) a[i][j] ^= 1;
			if(a[i][j] != b[i][j]){
                return false;
			}
		}
	}
	return true ;
}

int main()
{
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin>>t ;
	while(t--)
	{
		cin>>n ;
		for(int i = 0 ; i < n ; ++i)
		{
			for(int j = 0 ; j < n ; ++j)
			{
				char c ;
				cin>>c ;
				a[i][j] = (c - '0') ;
			}
		}
		for(int i = 0 ; i < n ; ++i)
		{
			for(int j = 0 ; j < n ; ++j)
			{
				char c ;
				cin>>c ;
				b[i][j] = (c - '0') ;
			}
		}
//		for(int i = 0 ; i < n ; ++i)
//		{
//			for(int j = 0 ; j < n ; ++j)
//				a[i][j] ^= b[i][j] ;
//		}
		if(solve())
			cout<<"YES\n" ;
		else
			cout<<"NO\n" ;
	}
	return 0 ;
}
