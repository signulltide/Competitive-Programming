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

int main() {
    fastIO;

    ll n, k, x;
    in(n, k, x);
    vector<ll> arr(n);
    vin(arr);
    
    sort(all(arr));
    //vout(arr);

    ll groups = 1;
    priority_queue<ll, vector<ll>, greater<ll>> spend;

    for (ll i=1; i<n; i++) {
        ll diff = arr[i] - arr[i-1];
        if (diff > x) {
            groups++;
            spend.push((diff - 1) / x);
        }
    }

    while (k > 0 && groups > 1) {
        ll top = spend.top();
        spend.pop();
        if (k - top < 0) break;
        k -= top;
        groups--;
    }

    out(groups);

    return 0;
}