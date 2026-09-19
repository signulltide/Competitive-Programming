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

ll n;
vector<ll> arr;

bool Check(ll x) {

    vector<ll> brr;

    for (ll a : arr) {
        if (a != x) {
            brr.push_back(a);
        }
    }

    ll s =  brr.size();

    rep(i, 0, s) {
        if (brr[i] != brr[s-i-1]) return false;
    }

    return true;
}

void Solve() {
    in(n);
    arr.resize(n);
    vin(arr);

    ll l = 0, r = n - 1;

    while (l < r) {
        if (arr[l] != arr[r]) {
            if (Check(arr[l]) || Check(arr[r])) {
                out("YES");
                return;
            } else {
                out("NO");
                return;
            }
        }
        l++; r--;
    }

    out("YES");
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}