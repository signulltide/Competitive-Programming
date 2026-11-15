#include <bits/stdc++.h>
using namespace std;
#define MOD1 1000000007
#define MOD2 998244353

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define ff first
#define ss second

void SetIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    SetIO("notlast");

    ll n;
    cin >> n;

    map<string, ll> milk;

    for (ll i=0; i<n; i++) {
        
        string s;
        ll t;
        cin >> s >> t;

        milk[s] += t;

    }

    vector<pair<ll, string>> cows;

    for (auto &[cow, amt] : milk) {
        cows.push_back({amt, cow});
    }

    sort(cows.begin(), cows.end());

    ll least = cows[0].first;
    for (ll i=1; i<7; i++) {
        if (cows[i].first > least) {
            cout << cows[i].second;
            return 0;
        }
    }
}