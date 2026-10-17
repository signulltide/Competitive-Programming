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

    vector<vector<ll>> adjList(n);

    ll u, v;
    rep(i, 0, m) {
        in(u, v);
        u--; v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    rep(i, 0, n) {
        if (adjList[i].size() == 0) {
            out("Brain Melt");
            return;
        }
    }

    if (m == n - 1) {
        ll center_count = 0;
        ll leaf_count = 0;
        rep(i, 0, n) {
            if (adjList[i].size() == n - 1) {
                center_count++;
            } else if (adjList[i].size() == 1) {
                leaf_count++;
            }
        }

        if (center_count == 1 && leaf_count == n - 1) {
            out("2");
            return;
        }
    }

    out("Many");
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}