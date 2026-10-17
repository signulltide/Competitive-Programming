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
    ll n, q;
    in(n, q);
    vector<ll> arr(n), qrs(q);
    vin(arr);
    vin(qrs);

    vector<ll> pref(n, 0), req(n, 0);
    pref[0] = arr[0];
    req[0] = arr[0];
    rep(i, 1, n) {
        pref[i] = pref[i-1] + arr[i];
        req[i] = max(req[i-1], arr[i]);
    }

    //vout(arr, req, qrs);

    vector<ll> res(q, 0);
    rep(i, 0, q) {
        auto it = upper_bound(req.begin(), req.end(), qrs[i]);
        ll idx = n;
        idx = distance(req.begin(), it);
        if (idx == 0) {
            res[i] = 0;
        } else {
            res[i] = pref[idx - 1];
        }
    }
    
    //out("---");

    vout(res);

    //out("=====");
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}