
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <functional>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <sstream> //stringstream
#include <cstring> // getline
#include <cmath>
#include <unordered_set>
#include <limits>
#include <unordered_map>


#define go(i,init ,n) for(int  i=init ;i<n ;i++)
#define X first
#define Y second
#define ll long long int
#define ALL arr.begin() ,arr.end()
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define FI freopen("input.txt", "r", stdin)
#define FO freopen("output.txt", "w", stdout)
#define OO 2*1e18
#define oo 1e9
#define N 200100
#define EPS 1e-14
#define PI 3.141592653589793238462643383279502884L
using namespace std;

ll MOD = 1e9 + 7;

ll prime[10000000];
ll fac[N], ifac[N];
ll inv[N];
vector<ll>primes;

ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b); }
bool IsPrime(ll x) { if (x == 1) return false; for (ll i = 2; i * i <= x; i++) { if (x % i == 0) return false; } return true; }
void seive(ll n) { prime[0] = prime[1] = 1; for (ll i = 2; i * i <= n; i++) if (!prime[i]) { primes.push_back(i); for (ll j = i * i; j <= 1e6; j += i) prime[j] = 1; } }
bool sortMa7boub(const pair<ll ,ll>& a, const pair<ll, ll>& b)
{ if (a.first == b.first) return (a.second > b.second); return(a.first < b.first); }
bool IsVowel(char c) { return(c == 'a' || c == 'e' || c == 'i' || c == 'u' || c == 'o' || c == 'y' || c == 'A' || c == 'E' || c == 'I' || c == 'U' || c == 'O' || c == 'Y'); }
bool IsEqual(string s1, string s2) { if (s1.length() != s2.length())return 0; go(i, 0, s1.length()) if (s1[i] != s2[i])return 0; return 1; }
ll  powMod(ll  base, ll  pw) { ll ret = 1; while (pw) { if (pw & 1) ret = (ret * base) % MOD; base = (base * base) % MOD; pw >>= 1; }return ret; }

//should use makeFact before useing C or P
void makeFact() { fac[0] = ifac[0] = 1; for (ll i = 1; i < N; i++) { fac[i] = (fac[i - 1] * i) % MOD; ifac[i] = powMod(fac[i], MOD - 2); } }
inline void Init() { inv[1] = 1; for (int i = 2; i < N; ++i) inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD; }

ll  C(ll  a, ll  b) { if (a < b) return 0; return (((fac[a] * ifac[b]) % MOD) * ifac[a - b]) % MOD; }
ll  P(ll a, ll b) { if (a < b) return 0; return(fac[a] * ifac[a - b]) % MOD; }
ll sum(ll k) { return (k % MOD) * ((k + 1) % MOD) / 2; }
ll pascalDivisibility(ll n, ll p) { ll ans = 1; ll i = 0; while (n) { ans = (sum(n % p) % MOD) * (powMod(sum(p), i) % MOD) + ((n % p + 1) % MOD) * (ans % MOD); ans %= MOD; n /= p; i++; } return ans % MOD; }

bool PointInRectangle(long double x1, long double  y1, long double x2, long double y2, long double x, long double y) { return(x >= x1 && x <= x2 && y >= y1 && y <= y2); }
bool InRange(ll a, ll b, ll c) { return a >= b && a <= c; }
bool isPalindrome(string str) { ll l = 0; ll h = str.length() - 1; while (h > l) { if (str[l++] != str[h--]) { return 0; } } return 1; }
bool IsSubSequanc(string t, string s, ll m, ll n) { if (m == 0)return 1; if (n == 0)return 0; if (t[m - 1] == s[n - 1]) return IsSubSequanc(t, s, m - 1, n - 1); else return IsSubSequanc(t, s, m, n - 1); }

string AL = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int dy[4] = { 1  , 0 , -1 ,  0 };
int dx[4] = { 0  , 1 ,  0 , -1 };

vector<long double>vec;
ll n;
ll freq[200100];
char arrChar[3][9];

long double ok(long double x) {

	long double ans = 0;

	for (ll i = 0; i < n ; i++) {
		ans += asin(vec[i] / (2 * x));
	}

	return ans;

}

double long solve1(long double mx) {

	long double l = mx/2, r = 10000, mid = (l+r)/2;

	while(r - l >= 0.0000001){

		if (abs(ok(mid) - PI) <= 0.0000001) {
			return mid;
		} else if (ok(mid) - PI < 0.0000001) {
			r = mid;
			mid = (l + r) / 2;
		} else if (ok(mid) - PI > 0.0000001) {
			l = mid;
			mid = (l + r) / 2;
		}

	}

	return -1;
}

int main()
{

	cin >> n;
	vec.resize(n);
	long double mx = 0;
	for (ll i = 0; i < n; i++) cin >> vec[i] , mx = max(mx , vec[i]);


	cout.precision(10);
	cout <<fixed<< solve1(mx);



}
