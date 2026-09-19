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
#define out(...) [&](auto&&... args){ ll n_ = 0; ((cout << (n_++ ? " " : "") << args), ...); cout << endl; }(__VA_ARGS__)
#define vin(...) [&](auto&... vecs){ (( [&](){ for(auto &x : vecs) cin >> x; }() ), ...); }(__VA_ARGS__)
#define vout(...) [&](auto&&... vecs){ (( [&](){ ll n_ = 0; for(auto &x : vecs) cout << (n_++ ? " " : "") << x; cout << "\n"; }() ), ...); }(__VA_ARGS__)

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_map;

void Solve() {
    ll n, k;
    in(n, k);

    vector<ll> v(n);
    vin(v);

    vector<ll> colours[k+1];

    rep(i, 1, k+1) {
        colours[i].push_back(0);
    }

    rep(i, 0, n) {
        colours[v[i]].push_back(i + 1);
    }

    rep(i, 1, k+1) {
        colours[i].push_back(n + 1);
    }

    priority_queue<ll> jumps[k + 1];

    ll ans = LLONG_MAX;

    rep(i, 1, k+1) {
        rep(j, 0, colours[i].size() - 1) {
            jumps[i].push(colours[i][j + 1] - colours[i][j] - 1);
        }

        ll max_val = jumps[i].top();

        jumps[i].pop();

        if (max_val % 2 == 0) {
            jumps[i].push(max_val / 2);
            jumps[i].push((max_val / 2) - 1);
        } else {
            jumps[i].push(max_val / 2);
            jumps[i].push(max_val / 2);
        }

        ans = min(ans, jumps[i].top());
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