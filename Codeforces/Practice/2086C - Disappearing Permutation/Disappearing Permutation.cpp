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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_map;

ll n;
vector<ll> arr, d, pos;
vector<bool> resolved;

ll Resolve(ll idx, ll add, ll first) {
    //out("RESOLVING: ", idx);
    add++;
    resolved[idx] = true;
    if (idx == first) {
        return add;
    }
    return Resolve(pos[idx], add, first);
}

void Solve() {
    ll n;
    in(n);
    arr.assign(n + 1, 0); d.assign(n + 1, 0); pos.assign(n + 1, 0);
    resolved.assign(n + 1, false);
    
    for (ll i=1; i<=n; i++) {
        in(arr[i]);
        pos[arr[i]] = i;
    }
    for (ll i=1; i<=n; i++) {
        in(d[i]);
    }

    //vout(arr, d, pos);

    ll curr = 0;
    for (ll i=1; i<=n; i++) {
        curr += resolved[d[i]] ? 0 : Resolve(d[i], 0, arr[d[i]]);
        cout << curr << " ";
        // for (ll j=1; j<=n; j++) {
        //     cout << resolved[j] << " ";
        // }
    }
    cout << endl;
}

int main() {
    //fastIO;

    ll t;
    cin >> t;

    while (t--) Solve();

    return 0;
}

//I AM GOING TO KILL MYSELF