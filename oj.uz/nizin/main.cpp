#include <iostream>

using namespace std;

const int MAXN = 1e6 + 10;

int n, nus=0;
long long a[MAXN];

int main()
{
    cin >> n;

    for(int i=0;i<n;i++) cin>>a[i];

    int mi=0, ma=n-1;

    while(ma > mi){

        if(a[ma] == a[mi]){
            mi++;
            ma--;
            continue;
        }

        if(a[ma] > a[mi]){
            a[mi+1] += a[mi];
            mi++;
        } else {
            a[ma-1] += a[ma];
            ma--;
        }

        nus++;

    }

    cout << nus << endl;

    return 0;
}
