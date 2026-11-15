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

int main() {
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);

    fastIO;

    ll n;
    string s;
    cin >> n >> s;

    for (ll x = 1; x <= n; x++) {
        
        bool flag = true;
        set<string> found;
        
        for (ll i = 0; i < n; i++) {
            
            string curr = s.substr(i, x);
            
            if (found.count(curr)) {
                flag = false;
                break;
            }

            found.insert(curr);

        }

        if (flag) {
            cout << x;
            return 0;
        }
        
    }
}