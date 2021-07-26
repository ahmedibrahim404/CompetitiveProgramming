#include <iostream>

using namespace std;

typedef pair<int, int> pi;

pi a, b, c;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        cin >> a.first >> a.second;
        cin >> b.first >> b.second;
        cin >> c.first >> c.second;

        if(a.first == b.first)
            printf("%d\n", abs(a.second - b.second) + ((c.first == a.first && c.second > min(a.second, b.second) && c.second < max(a.second, b.second)) ? 2 : 0));
        else if(a.second == b.second)
            printf("%d\n", abs(a.first - b.first) + ((c.second == a.second && c.first > min(a.first, b.first) && c.first < max(a.first, b.first)) ? 2 : 0));
        else
            printf("%d\n", abs(a.first-b.first) + abs(a.second-b.second));
    }
    return 0;
}
