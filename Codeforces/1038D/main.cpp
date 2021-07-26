#include <iostream>
using namespace std;
const int MAX=5e5+3;
int n, ns[MAX];

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&ns[i]);
    for(int i=0;i<n;i++){
        if(i==0 || i==n-1) printf("%d ", -ns[i]);
        if(i!=n-1) printf("%d ", ns[i]-ns[i+1]);
    }
    return 0;
}
