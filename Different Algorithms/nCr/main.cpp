#include <iostream>

using namespace std;
void printNcR(int n, int r)
{

    long long p = 1, k = 1;

    if (n - r < r)
        r = n - r;

    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;

            long long m = __gcd(p, k);

            p /= m;
            k /= m;

            n--;
            r--;
        }
    }
    else
        p = 1;

    cout << p << endl;
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
