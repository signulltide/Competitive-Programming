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
    ll n, q, temp;
    in(n, q);
    vector<ll> arr(n), queers(q);
    vin(arr, queers);
    map<ll, ll> first_occ;
    rep(i, 0, n) {
        first_occ[arr[i]] = i;
    }
    rep(i, 0, n) {
        if (first_occ[arr[i]] > i) first_occ[arr[i]] = i;
    }
    rep(i, 0, q) {
        ll orig_pos = first_occ[queers[i]];
        cout << orig_pos + 1 << " ";
        rep(j, orig_pos + 1, 1) {
            arr[j] = arr[j-1];
            first_occ[arr[j]] = j;
        }
        arr[0] = queers[i];
        first_occ[queers[i]] = 0;
    }
}

int main() {
    fastIO;

    Solve();

    return 0;
}