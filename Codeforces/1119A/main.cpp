#include <iostream>

using namespace std;

int n;
int v[300000+9];
int result=0;
int main(){

    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%d", &v[i]);
    for(int i=0; i< n; ++i)
    {
        if(v[i] != v[0])
        {
            result = max(result, i);
        }
        if(v[i] != v[n-1])
        {
            result = max(result, n - 1 - i);
        }
    }
    cout << result << endl;


    return 0;
}
