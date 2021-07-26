#include <iostream>

using namespace std;
int n;
int vs[1001];
int x, y, z, s, x1;
int main()
{
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i == 0)
                scanf("%d", &vs[j]);

            if(i == 1 && j == 2)
                scanf("%d", &y);
            else
                if(i != 0)
                    scanf("%d", &s);

        }
    }


    x = vs[2];
    z = vs[1];
    x1 = (x-y+z)/2;
    cout << (x-y+z)/2 << " ";

    for(int i=1;i<n;i++)
        cout << vs[i] - x1 << " ";

    return 0;
}
