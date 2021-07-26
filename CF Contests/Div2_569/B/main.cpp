 #include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] >= 0)
            arr[i] = -arr[i] - 1;
    }

    if (n % 2) {
        int m = 0;

        for (int i=0;i<n;i++){
            if(arr[i] < arr[m]) m=i;
        }

        arr[m] = -arr[m]-1;
    }

    for (int x : arr)
        cout << x << ' ';
    cout << '\n';

    return 0;
}
