#include <iostream>

using namespace std;

typedef long long ll;

int n;
int arr1[100000+9], arr2[100000+9];
char str[100000];
int main(){

    scanf("%d", &n);

    scanf("%d", &arr1[0]);
    for(int i=1;i<n;i++){
        scanf("%d", &arr1[i]);
        arr1[i] += arr1[i-1];
    }

    scanf("%s", str);

    for(int i=0;i<n;i++){
        if(str[i] == '1'){
            if(i) arr2[i]=arr2[i-1] + (arr1[i]-arr1[i-1]);
            else arr2[i]=arr1[i];
        } else {
            arr2[i] = arr2[i-1];
        }

    }

    ll mx=0;

    for(int i=0;i<n;i++){
        if(str[i] == '1'){
            if(i) mx=max(mx, (ll) arr1[i-1] + arr2[n-1]-arr2[i]);
            else mx=max(mx, (ll) arr1[0] + arr2[n-1]-arr2[0]);
        }
    }

    printf("%lld", mx);





    return 0;
}
