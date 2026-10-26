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
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define ff first
#define ss second

#define in(...) [&](auto&... args){ (cin >> ... >> args); }(__VA_ARGS__)
#define out(...) [&](auto&&... args){ int n_ = 0; ((cout << (n_++ ? " " : "") << args), ...); cout << endl; }(__VA_ARGS__)
#define vin(...) [&](auto&... vecs){ (( [&](){ for(auto &x : vecs) cin >> x; }() ), ...); }(__VA_ARGS__)
#define vout(...) [&](auto&&... vecs){ (( [&](){ int n_ = 0; for(auto &x : vecs) cout << (n_++ ? " " : "") << x; cout << endl; }() ), ...); }(__VA_ARGS__)

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_map;

void Solve() {
    ll n;
    string r1, r2;

    in(n, r1, r2);

    vector<ll> dp(n, 0);

    dp[0] = r1[0] != r2[0];
    if (n > 1) dp[1] = min(
        dp[0] + (r1[1] != r2[1]),
        (ll)(r1[1] != r1[0]) + (r2[1] != r2[0])
    );

    for (ll i=2; i<n; i++) {
        dp[i] = min(
            dp[i-1] + (r1[i] != r2[i]),
            dp[i-2] + (r1[i-1] != r1[i]) + (r2[i-1] != r2[i])
        );
    }

    //vout(dp);
    out(dp[n-1]);
}

int main() {
    fastIO;

    ll t;
    cin >> t;

    while (t--) Solve();

    return 0;
}