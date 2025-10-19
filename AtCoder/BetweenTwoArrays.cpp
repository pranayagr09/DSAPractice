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

    vector<int> A(n,0);
    vector<int> B(n,0);
    int mod = 998244353;
    
    for(int i=0; i<n; i++) cin >> A[i];
    for(int i=0; i<n; i++) cin >> B[i];

    int max_num = max(A[n-1], B[n-1]);

    // dp[i][j] denotes number of such sequences possible with index i being atmost j
    vector<vector<int>> dp(n, vector<int> (max_num+1, 0));

    for(int j=A[0]; j<=B[0]; j++) dp[0][j] = 1;

    vector<int> prefix_sum(max_num+1, 0);
    prefix_sum[0] = dp[0][0];
    for(int j=1; j<= max_num; j++) {
        prefix_sum[j] = (prefix_sum[j-1] + dp[0][j]) % mod;
    }


    for(int i=1; i<n; i++){
        for(int j=A[i]; j<= B[i]; j++){
            dp[i][j] = (dp[i][j] + prefix_sum[j]) % mod;
        }

        prefix_sum[0] = dp[i][0];
        for(int j=1; j<= max_num; j++) {
            prefix_sum[j] = (prefix_sum[j-1] + dp[i][j]) % mod;
        }
    }

    int ans = 0;
    for(int j=0; j<= max_num; j++){
        ans = (ans + dp[n-1][j]) % mod;
    }

    cout << ans << endl;
    
    return 0;
}