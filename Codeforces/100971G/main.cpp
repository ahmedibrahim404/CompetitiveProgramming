#include<bits/stdc++.h>
using namespace std;

int a, b;
int v1[2][2];

bool solve(int idx, int height, int width){

    if(idx == 2) return 1;

    bool ans = 0;
    if(height - v1[idx][0] >= 0 && v1[idx][1] <= width) ans |= solve(idx+1, height - v1[idx][0], width);
    if(height - v1[idx][1] >= 0 && v1[idx][0] <= width) ans |= solve(idx+1, height - v1[idx][1], width);

    if(width - v1[idx][0] >= 0 && v1[idx][1] <= height) ans |= solve(idx+1, width - v1[idx][0], height);
    if(width - v1[idx][1] >= 0 && v1[idx][0] <= height) ans |= solve(idx+1, width - v1[idx][1], height);

    return ans;

}
int v[2];
//int v1[2], v2[2];
int main(){
    scanf("%d%d",&v[0],&v[1]);
    for(int i=0;i<2;i++) scanf("%d",&v1[0][i]);
    for(int i=0;i<2;i++) scanf("%d",&v1[1][i]);

    if(solve(0, v[0], v[1]) || solve(0, v[1], v[0])) printf("YES\n");
    else printf("NO\n");

//do {
//    do {
//        do {
//            if(v1[0] + v2[0] <= v[0] && max(v1[1], v2[1]) <= v[1])
//                return cout << "YES\n", 0;
//            if(v1[0] + v2[0] <= v[1] && max(v1[1], v2[1]) <= v[0])
//                return cout << "YES\n", 0;
//
//        } while(next_permutation(v1, v1+2));
//    } while(next_permutation(v2, v2+2));
//} while(next_permutation(v, v+2));

//    cout << "NO\n";

    return 0;
}
