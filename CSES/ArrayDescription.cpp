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

    int n, m;
    cin >> n >> m;

    vi arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vll> dp(n+1, vll(m+1, 0));
    
    if(arr[0] == 0){
        for(int j=1; j<=m; j++){
            dp[1][j] = 1;
        }
    }
    else{
        dp[1][arr[0]] = 1;
    }
    
    for(int i=2; i<=n; i++){
        if(arr[i-1] != 0) {
            int v = arr[i-1];
            ll sum = 0;
            if(v-1 >= 1) sum += dp[i-1][v-1];
            sum += dp[i-1][v];
            if(v+1 <= m) sum += dp[i-1][v+1];
            dp[i][v] = sum % MOD;
        }
        else{
            for(int j=1; j<=m; j++){
                ll sum = 0;
                if(j-1 >= 1) sum += dp[i-1][j-1];
                sum += dp[i-1][j];
                if(j+1 <= m) sum += dp[i-1][j+1];
                dp[i][j] = sum % MOD;
            }
        }
    }

    ll ans = 0;
    if(arr[n-1] == 0){
        for(int j=1; j<=m; j++){
            ans = (ans + dp[n][j]) % MOD;
        }
    }
    else {
        ans = dp[n][arr[n-1]];
    }
    
    cout << ans << endl;
    return 0;
}