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

void Solve() {
    ll n;
    in(n);

    vector<pair<ll, ll>> arr; // gang, id
    for (ll i=1; i<=n; i++) {
        ll gang;
        in(gang);
        arr.push_back({gang, i});
    }

    sort(all(arr));

    auto it = upper_bound(arr.begin(), arr.end(), arr[0].first, 
        [](ll val, const pair<ll, ll>& elem) {
            return val < elem.first;
        }
    );

    if (it != arr.end()) {
        out("YES");

        auto temp_it = it;
        while (temp_it != arr.end()) {
            out(arr[0].second, temp_it->second);
            temp_it++;
        }

        temp_it = it;
        while (temp_it != arr.begin() + 1) {
            temp_it--;
            out(temp_it->second, it->second);
        }
    } else {
        out("NO");
    }
}

int main() {
    fastIO;

    ll t;
    cin >> t;

    while (t--) Solve();

    return 0;
}