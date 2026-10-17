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
    ll n, k;
    in(n, k);
    vector<ll> arr(n);
    vin(arr);

    ll sum = 0;
    for (ll x : arr) sum += x;

    if (k == 1) {
        out(sum);
        return;
    }

    // pref[i] = sum of first i elements
    // suff[i] = sum of last i elements
    vector<ll> pref(k, 0), suff(k, 0);
    for (int i = 1; i < k; i++) {
        pref[i] = pref[i - 1] + arr[i - 1];
        suff[i] = suff[i - 1] + arr[n - i];
    }

    // We want to keep (k - 1) elements total:
    // l elements from the prefix, (k - 1 - l) elements from the suffix.
    ll min_kept = sum;
    for (int l = 0; l <= k - 1; l++) {
        int r = (k - 1) - l;
        min_kept = min(min_kept, pref[l] + suff[r]);
    }

    out(sum - min_kept);
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}