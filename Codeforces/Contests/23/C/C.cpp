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
    ll n;
    in(n);

    vector<ll> a(n + 1);
    for (ll k = 1; k <= n; ++k) {
        in(a[k]);
    }

    // Difference array to mark forbidden ranges in [0, n - 1]
    vector<ll> diff(n + 2, 0);

    for (ll k = 1; k <= n; ++k) {
        ll L = 1LL * k * a[k];
        ll R = 1LL * k * a[k] + k - 1;

        // Only mark if the range overlaps with {0, 1, ..., n - 1}
        if (L < n) {
            ll left_idx = max(0LL, L);
            ll right_idx = min((ll)n - 1, R);
            if (left_idx <= right_idx) {
                diff[left_idx]++;
                diff[right_idx + 1]--;
            }
        }
    }

    // Identify non-forbidden elements
    vector<ll> B;
    ll current_coverage = 0;
    for (ll x = 0; x < n; ++x) {
        current_coverage += diff[x];
        if (current_coverage == 0) {
            B.push_back(x);
        }
    }

    // Output size and elements
    cout << B.size() << "\n";
    for (ll i = 0; i < B.size(); ++i) {
        cout << B[i] << (i + 1 == B.size() ? "" : " ");
    }
    cout << "\n";
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}