#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, m, k, t, a, b;

struct pnt {
    int x, y, until;
};

pnt A[1000+9];

bool cpr(pnt a, pnt b){
    return (a.x-1)*m+a.y >(b.x-1)*m+b.y;
}

int main(){

    scanf("%d %d %d %d", &n, &m, &k, &t);

    for(int i=0;i<k;i++){
        scanf("%d %d", &a, &b);
        A[i].x = a, A[i].y = b;
    }

    sort(A, A+k, cpr);

    int d=0;
    for(int i=k-1;i>=0;i--) A[i].until = d++;


    while(t--){

        scanf("%d %d", &a, &b);
        int pos = (a-1)*m+b ;
        bool block=false;

        for (int j = 0; j < k; j++){
            if (a > A[j].x || (a == A[j].x&&b > A[j].y)){
                pos--;
            }
            if (b == A[j].y&&a == A[j].x){
                block = true;
                break;
            }
        }


        if(block){
            cout << "Waste" << endl;
            continue;
        }



        if(pos % 3 == 1)
            cout << "Carrots" << endl;
        else if(pos % 3 == 2)
            cout << "Kiwis" << endl;
        else
            cout << "Grapes" << endl;


    }


    // (a-1)*m+b



    return 0;
}
