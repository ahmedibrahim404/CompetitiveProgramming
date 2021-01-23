#include <bits/stdc++.h>


using namespace std;


typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define MAX 1000000

vector<int>data;
int n; // number of data
int DP[MAX + 5]; // DP array for keeping the length of increasing sub-sequences
bool vis[MAX + 5]; // Direction array to print the solution

int LIS(int current_index)
{
    if (DP[current_index] != -1) {
        return DP[current_index];
    }

    int maxLength = 0;
    for (int next_index = current_index + 1; next_index < n; next_index++) {
        if (data[next_index] > data[current_index]) {
            if (LIS(next_index) > maxLength) {
                maxLength = LIS(next_index);
            }
        }
    }

    DP[current_index] = 1 + maxLength;
    return DP[current_index];
}


void build(int current_index)
{
    if (vis[current_index]) return;
    vis[current_index]=1;

    for (int next_index = current_index + 1; next_index < n; next_index++) {
        if (data[next_index] > data[current_index]) {
            if (LIS(next_index) + 1 == DP[current_index]) {
                cout << data[next_index] << "\n";
                build(next_index);
                return;
            }
        }
    }

    return;
}

int main(){

    int x, ans, test, t, start, i;
    string str;

    cin >> test;
    cin.ignore();
    cin.ignore();
    for (t = 1; t <= test; t++) {

        data.clear();
        memset(DP, -1, sizeof DP);
        memset(vis, 0, sizeof vis);

        while (getline(cin, str)) {
            if (str == "") {
                break;
            }
            x = stoi(str);
            data.push_back(x);
        }

        n = (int) data.size();

        ans = start = 0;
        for (i = 0; i < n; i++) {
            if (LIS(i) > ans) {
                ans = LIS(i);
                start = i;
            }
        }

        if (t != 1) {
            cout << "\n";
        }


        cout << "Max hits: " << ans << "\n";
        cout << data[start] << "\n";
        build(start);


    }

    return 0;
}
