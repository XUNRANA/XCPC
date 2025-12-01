#include <bits/stdc++.h>
#define ll long long
#define int long long
#define double long double
#define pb push_back
#define cn cout << "NO\n"
#define cy cout << "YES\n"
#define debug(x) cerr << #x << "=" << x << "\n"
#define debug2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << "\n"
#define all(v) v.begin(), v.end()
#define all1(v) v.begin() + 1, v.end()
#define ft first
#define sd second
#define Vector Point

const double pi = acos(-1);
const double dinf = 1e18, eps = 1e-8;
const int N = 1e5 + 10;
const ll MOD = 998244353;
using namespace std;

ll fastpow(ll a, ll b, ll mod)
{
    ll res = 1 % mod;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
vector<int> fact(N + 1), infact(N + 1);
void init()
{
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = 1ll * fact[i - 1] * i % MOD;
        infact[i] = 1ll * infact[i - 1] * fastpow(i, MOD - 2, MOD) % MOD;
    }
}
int C(int a, int b, int mod)
{
    if (a < 0 || b < 0 || a < b)
        return 0;
    return fact[a] * infact[b] % MOD * infact[a - b] % MOD;
}
void solve()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    s = " " + s;
    int l = 1, r = 0, sum = 0, ans = 0;
    while (r <= n && sum <= k)
    {
        r++;
        sum += (s[r] - '0');
    }
    sum -= (s[r--] - '0');
    if (sum != k)
    {
        cout << "0\n";
        return;
    }
    cout<<l<<" "<<r<<"+\n";
    ans += C(r - l + 1, k, MOD);

    while (l <= r && r <= n)
    {
        int rr = r;
        while (l <= r && sum == k)
            sum -= (s[l++] - '0');
        while (r <= n && sum <= k)
            sum += (s[++r] - '0');
        sum -= (s[r--] - '0');
        if (sum != k || r < l)
            break;
        
        cout<<l<<" "<<r<<"+\n";
        
        cout<<l<<" "<<rr<<"-\n";
       
        ans = (ans + C(r - l + 1, k, MOD) % MOD);
        
        ans = ((ans - C(rr - l + 1, k - 1, MOD)) % MOD + MOD) % MOD;
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    init();
    cin >> _;
    while (_--)
        solve();
    return 0;
}