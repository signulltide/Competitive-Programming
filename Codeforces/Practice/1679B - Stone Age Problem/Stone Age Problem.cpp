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

int main() {
    ll n, q;
    in(n, q);
    vector<ll> arr(n);
    vin(arr);

    ll sum = 0;
    for (ll a : arr) {
        sum += a;
    }

    ll pending = -1;
    ll global_updates = 0;
    vector<ll> local_updates(n, 0);

    while (q--) {
        ll cq, idx, x;
        in(cq);

        if (cq == 1) {

            in(idx, x);
            idx--;

            if (local_updates[idx] < global_updates) {
                sum += x - pending;
                local_updates[idx] = global_updates;
            } else {
                sum += x - arr[idx];
            }

            arr[idx] = x;

        } else if (cq == 2) {

            in(x);
            sum = x * n;
            pending = x;
            global_updates++;

        }

        out(sum);
    }

    return 0;
}