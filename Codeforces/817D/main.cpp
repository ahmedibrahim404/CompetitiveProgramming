#include <iostream>

using namespace std;

int n;
int ns[1000000+9];
int main(){
    scanf("%d",&n);

    for(int i=0;i<n;i++) scanf("%d",&ns[i]);
    int total=0;
    for(int i=0;i<n;i++){
        int mi=ns[i], mx=ns[i];
        for(int j=i;j<n;j++){
            mi=min(mi, ns[j]);mx=max(mx, ns[j]);
            cout << "FROM " << i << " TO " << j << " IS " << (mx-mi) << endl;
            total += mx-mi;
        }
    }

    cout << total << endl;

    return 0;
}
