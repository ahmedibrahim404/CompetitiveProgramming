#include <iostream>

using namespace std;
int ca, cb, n;
bool found = false;
bool visited[1000+9][1000+9];
void way(int a, int b, string s){

    if(found) return;
    if(visited[a][b]) return;

    visited[a][b] = true;

    if(b == n){
        cout << s;
        found=true;
        return;
    }

    if(a > 0)
        way(0, b, s + "empty A\n");
    if(b > 0)
        way(a, 0, s + "empty B\n");
    if(a != ca)
        way(ca, b, s + "fill A\n");
    if(b != cb)
        way(a, cb, s + "fill B\n");

    if(b > 0)
        way((a+b)>ca ? ca:a+b, (a+b)>ca ? (a+b)-ca:0, s + "pour B A\n");

    if(a > 0)
        way((a+b)>cb ? (a+b)-cb:0, (a+b)>cb ? cb:a+b, s + "pour A B\n");

}

int main(){

    while(cin >> ca >> cb >> n){
        found=false;

        for(int i=0;i<1009;i++)
            for(int j=0;j<1009;j++)
                visited[i][j]=false;

        way(0, 0, "");
        cout << "success" << endl;
    }


    return 0;
}
