#include <iostream>

using namespace std;
int n;


int solve(int a1, int a2, int a3, int b1, int b2, int b3, bool arr[]){
    int cnt=0;
    for(int i=0;i<6;i++) if(arr[i]) cnt++;
    if(cnt==6) return 0;

    int mx=0;

    if(!arr[0]){
        arr[0]=1;
        mx=max(mx, min(a1, b1)+solve(a1-min(a1, b1), a2, a3, b1-min(a1, b2), b2, b3, arr));
        arr[0]=0;
    }
    if(!arr[1]){
        arr[1]=1;
        mx=max(mx, min(a2, b2)+solve(a1, a2-min(a2, b2), a3, b1, b2-min(a2, b2), b3, arr));
        arr[1]=0;
    }

    if(!arr[2]){
        arr[2]=1;
        mx=max(mx, min(a3, b3)+solve(a1, a2, a3-min(a3, b3), b1, b2, b3-min(a3, b3), arr));
        arr[2]=0;
    }

    if(!arr[3]){
        arr[3]=1;
        mx=max(mx, min(b1, a2)+solve(a1, a2-min(b1, a2), a3, b1-min(b1, a2), b2, b3, arr));
        arr[3]=0;
    }

    if(!arr[4]){
        arr[4]=1;
        mx=max(mx, min(b2, a3)+solve(a1, a2, a3-min(b2, a3), b1, b2-min(b2, a3), b3, arr));
        arr[4]=0;
    }

    if(!arr[5]){
        arr[5]=1;
        mx=max(mx, min(b3, a1)+solve(a1-min(b3, a1), a2, a3, b1, b2, b3-min(b3, a1), arr));
        arr[5]=0;
    }

    return mx;
}

int a1,a2,a3,b1,b2,b3;


int main(){
    scanf("%d",&n);
    scanf("%d%d%d",&a1,&a2,&a3);
    scanf("%d%d%d",&b1,&b2,&b3);
    int mx1=0;
    mx1+=min(a1, b2);
    mx1+=min(a2, b3);
    mx1+=min(a3, b1);


    bool ar[6];
    for(int i=0;i<6;i++)ar[i]=0;
    cout << n-solve(a1,a2,a3,b1,b2,b3, ar) << " " << mx1 << "\n";


    return 0;
}
