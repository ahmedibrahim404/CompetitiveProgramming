#include <iostream>
#include <bits/stdc++.h>

using namespace std;

set<int> st;

int main(){

    int n, x0, y0, x, y, slope;
    scanf("%d %d %d", &n, &x0, &y0);

    for(int i=0;i<n;i++){
        scanf("%d %d", &x, &y);
        slope = (x-x0)/(y-y0);
        st.insert(slope);
        cout << i << endl;
    }

    cout << st.size() << endl;

    return 0;
}