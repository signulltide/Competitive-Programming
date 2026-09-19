#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define MOD1 1000000007
#define MOD2 998244353

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define ff first
#define ss second

#define in(...) [&](auto&... args){ (cin >> ... >> args); }(__VA_ARGS__)
#define out(...) [&](auto&&... args){ int n_ = 0; ((cout << (n_++ ? " " : "") << args), ...); cout << endl; }(__VA_ARGS__)
#define vin(...) [&](auto&... vecs){ (( [&](){ for(auto &x : vecs) cin >> x; }() ), ...); }(__VA_ARGS__)
#define vout(...) [&](auto&&... vecs){ (( [&](){ int n_ = 0; for(auto &x : vecs) cout << (n_++ ? " " : "") << x; cout << "\n"; }() ), ...); }(__VA_ARGS__)

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_map;

void Solve() {
    ll n, m;
    in(n, m);
    vector<vector<ll>> grid(m, vector<ll>(n));

    rep(i, 0, n) {
        rep(j, 0, m) {
            in(grid[j][i]);
        }
    }

    ll ans = 0;
    rep(i, 0, m) {
        sort(all(grid[i]));

        for (ll j=n-1; j>=0; j--) {
            ans += j * (grid[i][j] - grid[i][n-j-1]);
        }
    }

    out(ans);
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}