#include <iostream>

using namespace std;

int n, m;

bool found=false;
void get(int no, int cs){

    if(no > m || found) return;
    if(no == m){
        cout << cs << endl;
        found=true;
        return;
    }

    get(no*2, cs+1);
    get(no*3, cs+1);

}

int main(){

    scanf("%d %d", &n, &m);

    get(n, 0);

    if(!found) cout << "-1" << endl;

    return 0;
}
