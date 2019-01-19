#include <iostream>

#include <bits/stdc++.h>

using namespace std;
double Function(double);

map<int, pair<int, int>> mp;
int** a = new int*[1000];
int na=0;
int main(){
    for(int i = 0; i < 1000; ++i)
        a[i] = new int[1000];

    int x1, y1, x2, y2, n;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    cin >> n;

    int n1, n2, n3;
    while(n--){
        scanf("%d %d %d", &n1, &n2, &n3);
        pair<int, int> pr;
        pr.first = n1, pr.second = n2;
        mp[n3] = pr;
    }

    for(int i=min(y1, y2);i<= max(y1, y2);i++){
        for ( const auto &p : mp ){

            double v1=0, v2=0;
            if(!a[x1][i]){
                v1 = sqrt( ( x1 - p.second.first ) + ( i - p.second.first ) );
                if(v1 >= p.first)
                    na++;

                a[x1][i]=1;
            }
            if(!a[x2][i]){
                v2 = sqrt( ( x2 - p.second.first ) + ( i - p.second.first ) );
                if(v2 >= p.first)
                    na++;

                a[x1][i]=1;
            }
        }


    }

    for(int i=min(x1, x2);i<= max(x1, x2);i++){

        double v1=0, v2=0;
        for ( const auto &p : mp ){
            if(!a[i][y1]){
                v1 = sqrt( ( i - p.second.first ) + ( y1 - p.second.first ) );
                if(v1 >= p.first)
                    na++;
                a[i][y1]=1;
            }
            if(!a[i][y2]){
                v2 = sqrt( ( i - p.second.first ) + ( y2 - p.second.first ) );
                if(v2 >= p.first)
                    na++;
                a[i][y2]=1;
            }
        }

    }

    cout << na << endl;

    return 0;
}
