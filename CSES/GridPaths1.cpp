#include <bits/stdc++.h>
using namespace std;

// Type aliases for convenience
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;

// Macros for common operations
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()

// Constants
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3fLL;
const ld EPS = 1e-9;

// Fast I/O
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Utility functions
template<typename T>
void ckmin(T& a, T b) { a = min(a, b); }

template<typename T>
void ckmax(T& a, T b) { a = max(a, b); }

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll modpow(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

ll modinv(ll a, ll mod) {
    return modpow(a, mod - 2, mod); // Assumes mod is prime
}

int main() {
    setIO();
    
    int n;
    cin >> n;
    
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < n; j++) {
            grid[i][j] = row[j];
        }
    };

    if(grid[0][0] == '*'){
        cout << 0 << endl;
        return 0;
    }

    vector<int> prev(n, 0);
    vector<int> curr(n, 0);
    prev[0] = 1;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == '*'){
                curr[j] = 0;
            }else{
                curr[j] = (prev[j] + (j > 0 ? curr[j-1] : 0)) % MOD;
            }
        }
        swap(prev, curr);
        curr.assign(n, 0);
    }
    cout << prev[n-1] << endl;
    return 0;
}