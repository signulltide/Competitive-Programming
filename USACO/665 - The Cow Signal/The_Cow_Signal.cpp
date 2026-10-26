#include <bits/stdc++.h>
using namespace std;
#define MOD1 1000000007
#define MOD2 998244353

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define ff first
#define ss second

int main() {
    fastIO;

    ll m, n, k;
    cin >> m >> n >> k;

    vector<string> grid(m);
    for (ll i=0; i<m; i++) {
        cin >> grid[i];
    }

    for (ll i=0; i<grid.size(); i++) {
        for (ll a=0; a<k; a++) {
            for (ll j=0; j<n; j++) {
                for (ll b=0; b<k; b++) cout << grid[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}