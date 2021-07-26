#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

char s[100100],a,b;
int i,j,l,x,y,n,k,ans;

int main()
{
	cin >> s >> n;
	l=strlen(s);
    int ans=0;

    while(n--){
        cin >> a >> b;

        for(int i=0;i<l;i++){

            int ra=0, rb=0;
            if( s[i] == a || s[i] == b ){

                while( s[i] == a || s[i] == b ){
                    if(s[i] == a) ra++; else rb++;
                    i++;
                }

                i-=1;

                ans += min(ra, rb);

            }

        }

    }

    cout << ans << endl;

	return 0;
}
