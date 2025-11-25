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

    int n,h,l,r;
    cin >> n >> h >> l >> r;

    vi hours(n,0);
    for(int i=0;i<n;i++){
        cin >> hours[i];
    }
    
    vi prev(h, -1), curr(h, -1);
    prev[0] = 0;

    for(int i=0; i<n; i++){
        fill(curr.begin(), curr.end(), -1);

        for(int j=0; j<h; j++){
            if(prev[j] != -1){
                int t1 = (j + hours[i]) % h;
                int t2 = (j + hours[i]-1) % h;

                curr[t1] = max(curr[t1], prev[j] + ((t1 >= l && t1 <= r) ? 1 : 0));
                curr[t2] = max(curr[t2], prev[j] + ((t2 >= l && t2 <= r) ? 1 : 0));
            }
        }
        swap(prev, curr);
    }

    int ans = 0;
    for(int j=0; j<h; j++) ans = max(ans, prev[j]);

    cout << ans << endl;
    return 0;
}