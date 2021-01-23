#include <bits/stdc++.h>

using namespace std ;

const int MAX = 1e6 + 5 ;

int n , m ;

char arr[5][MAX] ;
int dp[MAX][1 << 5] ;

int solve(int idx , int prvmask)
{
	if(idx == m)
		return 0 ;
	int &ret = dp[idx][prvmask] ;
	if(ret != -1)
		return ret ;
	ret = 1e9 ;
	for(int mask = 0 ; mask < (1 << n) ; ++mask)
	{
		int cost = 0 , sum = 0 ;
		bool flag = true ;
		for(int bit = 0 ; bit < n ; ++bit)
		{
			if((mask & (1 << bit)))
			{
				if(arr[bit][idx] == '0')
					cost++ ;
			}
			else if(arr[bit][idx] == '1')
				cost++ ;
		}
		for(int bit = 0 ; bit < n ; ++bit)
		{
			if((mask & (1 << bit)))
				sum++ ;
			if((prvmask & (1 << bit)))
				sum++ ;
			if(bit == 0)
				continue ;
			if(bit == 2)
			{
				if((mask & 1))
					sum-- ;
				if((prvmask & 1))
					sum-- ;
			}
			if((sum & 1))
				continue ;
			flag = false ;
			break ;
		}
		if(idx == 0)
			flag = true ;
		if(flag)
			ret = min(ret , solve(idx+1 , mask) + cost) ;
	}
	return ret ;
}

int main()
{
	memset(dp , -1 , sizeof(dp)) ;
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	cin>>n>>m ;
	if(n >= 4)
		return cout<<-1<<"\n" , 0 ;
	for(int i = 0 ; i < n ; ++i)
	{
		for(int j = 0 ; j < m ; ++j)
			cin>>arr[i][j] ;
	}
	int ans = solve(0 , 0) ;
	if(ans > n*m)
		ans = -1 ;
	return cout<<ans<<"\n" , 0 ;
}
