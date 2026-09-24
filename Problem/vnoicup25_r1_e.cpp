#include <bits/stdc++.h>
using namespace std;

#define     el "\n"
#define     FOR(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define     FORD(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
#define     pb push_back
#define     fi first
#define     se second
#define     all(x) x.begin(),x.end()
#define     lg(x) __lg(x)
#define     alla(a,n) a+1,a+n+1
#define     ll long long


template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}

const int N = (1 << 21) + 2;
const int lim = 1e6 + 2;
const int sm = 998244353;
int n, k, a[N];

void inp()
{
    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];
}

void add(ll &x, ll y)
{
    x += y;
    if(x >= sm) x -= sm;
    if(x < 0) x += sm;
}

int fac[N], inv_fac[N];

int Pow(int a, int n)
{
    if(!n) return 1;
    int res = Pow(a, n / 2);
    res = 1LL * res * res % sm;
    if(n & 1) res = 1LL * res * a % sm;
    return res;
}
void prepare()
{
    int lim = (1 << 21);
    fac[0] = inv_fac[0] = 1;
    FOR(i, 1, lim) fac[i] = 1LL * fac[i - 1] * i % sm;
    inv_fac[lim] = Pow(fac[lim], sm - 2);
    FORD(i, lim - 1, 1) inv_fac[i] = 1LL * inv_fac[i + 1] * (i + 1) % sm;
}
int C(int k, int n)
{
    if(k < 0 || k > n) return 0;
    return 1LL * fac[n] * inv_fac[n - k] % sm * inv_fac[k] % sm;
}


namespace sub1
{
    void slv()
    {
        int cnt1 = 0, cnt0 = 0;
        FOR(i, 1, n) {
            if(a[i]) cnt1++;
            else cnt0++;
        }
        if(cnt0 == 0) {
            cout << 1LL * fac[n] * n % sm << el; return;
        }
        ll ans = 0;
        FOR(i, 1, cnt1) {
            add(ans, 1LL * C(i, cnt1) * fac[i] % sm * cnt0 % sm * fac[n - i - 1] % sm * i % sm);
        }
        cout << ans << el;
    }
}

namespace sub2
{
    int cnt[N];
    void slv()
    {
        FOR(i, 1, n) cnt[a[i]]++;

        for(int i = 0; i < k; i++) {
            for(int msk = 0; msk < (1 << k); msk++) if(~msk >> i & 1) {
                cnt[msk] += cnt[msk ^ (1 << i)];
            }
        }

        long long ans = 0;
        for(int msk = 1; msk < (1 << k); msk++) if(cnt[msk] > 0) {
            long long ways = 1LL * fac[n] * cnt[msk] % sm * Pow(n - cnt[msk] + 1, sm - 2) % sm;
            if(__builtin_popcount(msk) & 1) add(ans, ways);
            else add(ans, -ways);
        }
        FOR(msk, 0, (1 << k) - 1) cnt[msk] = 0;
        cout << ans << el;
    }
}

main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    #define __Azul__ "vnoicup25_r1_e"
    if(fopen(__Azul__".inp", "r")) {
        freopen(__Azul__".inp", "r", stdin);
        freopen(__Azul__".out", "w", stdout);
    }
    prepare();

    bool qs = 1;
    int T = 1;
    if(qs) cin >> T;
    while(T--) {
        inp();
        if(k == 1) sub1 :: slv();
        else sub2 :: slv();
    }

    cerr << "\nTime" << 0.001 * clock() << "s "; return 0;


}

