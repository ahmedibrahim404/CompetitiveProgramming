#include <iostream>

using namespace std;
typedef long long ll;
struct point {
    ll x, y;
};

point p1, p2, p3, p4, p5, p6;

ll inter(point l1, point l2, point l3, point l4){
    ll left = max(l1.x, l3.x),
    right = min(l2.x, l4.x),
    bottom = max(l1.y, l3.y),
    top = min(l2.y, l4.y);

    left = max(left, p1.x),
    right = min(right, p2.x),
    bottom = max(bottom, p1.y),
    top = min(top, p2.y);

    return max(0LL, (top-bottom)*(right-left));

}

ll area(point l1, point l2, point l3, point l4){
    ll left = max(l1.x, l3.x),
    right = min(l2.x, l4.x),
    bottom = max(l1.y, l3.y),
    top = min(l2.y, l4.y);
    return max(0LL, (top-bottom)*(right-left));
}


int main(){
    scanf("%lld%lld",&p1.x, &p1.y);
    scanf("%lld%lld",&p2.x, &p2.y);
    scanf("%lld%lld",&p3.x, &p3.y);
    scanf("%lld%lld",&p4.x, &p4.y);
    scanf("%lld%lld",&p5.x, &p5.y);
    scanf("%lld%lld",&p6.x, &p6.y);

    if(area(p1, p2, p3, p4) + area(p1, p2, p5, p6) - inter(p3, p4, p5, p6) == abs((p1.x-p2.x)*(p1.y-p2.y))) printf("NO\n");
    else printf("YES\n");


    return 0;
}
