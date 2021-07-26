#include <bits/stdc++.h>

char s[10000001];
int n, t, cur[10000001], left[10000001];
int mx=0, no=1;
int main(){
	gets(s), n=strlen(s);

	for (int i=0; i<n; i++){

        if(s[i] == '(') cur[++t]=i;
        else if(t){
            left[i]=i-cur[t]+1+left[cur[t]-1];
            t--;
            if(left[i] > mx) mx=left[i], no=1;
            else if(left[i] == mx) no++;
        }

	}

	printf("%d %d\n",mx,no);

}
