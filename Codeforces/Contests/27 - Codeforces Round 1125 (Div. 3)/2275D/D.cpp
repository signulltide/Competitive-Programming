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

struct Lab {
    ll a, b, c;
    ll init_sum;
    ll setup;
};

void Solve() {
    ll n, k;
    in(n, k);
    vector<Lab> labs(n);

    ll r = LLONG_MAX;

    rep(i, 0, n) {
        in(labs[i].a, labs[i].b, labs[i].c);
        labs[i].init_sum = labs[i].a + labs[i].b + labs[i].c;
        
        if (a == b && b == c) {
            labs[i].setup = (ll)
        }
    }

    auto Check = [&](ll s) -> bool {
        ll ops_needed = 0;
        rep(i, 0, n) {
            if (s > labs[i].init_sum) {
                if (!labs[i].can_grow) return false;
                ll diff = s - labs[i].init_sum;
                if (ops_needed > k) return false;
                ops_needed += diff;
            }
        }
        return ops_needed <= k;
    };

    ll min_init = labs[0].init_sum;
    rep(i, 1, n) {
        min_init = min(min_init, labs[i].init_sum);
    }
    ll l = min_init;
    r = min(r, min_init + k);

    ll ans = l;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (Check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
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