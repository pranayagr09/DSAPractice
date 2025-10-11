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

void solve(){
    int n;
    cin >> n;

    vector<int> nums;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        nums.push_back(num);
    } 

    vector<int> dp(n,0);
    dp[n-1] = 0;

    for(int i=n-2; i >= 0; i--){
        int tmp = 0;
        if(i + nums[i] == n-1) tmp = 1 + nums[i];
        else if(i + nums[i] < n-1) tmp = 1 + nums[i] + dp[i+nums[i]+1];

        dp[i] = max(dp[i+1],tmp);
    }

    cout << n - dp[0] << endl;
    return;
}

int main() {
    setIO();

    int t;
    cin >> t;

    while(t--){
        solve();
    }
    return 0;
}