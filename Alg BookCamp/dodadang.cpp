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

const int sm = 998244353;
const int N = 2e5 + 2;

int n, m, a[N];

void inp()
{
    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];
}

void add(ll &x, ll y)
{
    x += y;
    if(x >= sm) x -= sm;
    if(x < 0) x += sm;
}

int Pow(int a, int n)
{
    if(!n) return 1;
    int res = Pow(a, n / 2);
    res = 1LL * res * res % sm;
    if(n & 1) res = 1LL * res * a % sm;
    return res;
}

int fac[N], inv_fac[N];

void prepare()
{
    int lim = 2e5;
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
    bool check_sub() {return (n <= 5000 && m <= 5000);}

    void slv()
    {
        ll ans = 0;
        FOR(x, 1, m) {
            int lst = 0;
            ll total = 0;
            FOR(i, 1, n) if(a[i] == x) {
                add(total, 1LL * (C(2, i - lst - 1) + i - lst - 1)  * x % sm);
                lst = i;
            }
            if(a[n] != x) add(total, 1LL * (C(2, n - lst) + n - lst) * x % sm);
//            cout << x << " " << total << el;
            add(ans, total);
        }
        cout << ans;
    }
}

namespace sub2
{
    vector<int> vec;
    map<int, vector<int>> pos;
    void slv()
    {
        FOR(i, 1, n) vec.push_back(a[i]);
        sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin());

        FOR(i, 1, n) pos[a[i]].push_back(i);


        ll ans = 0;
        for(int x : vec) add(ans, x);

        ans = (1LL * n * (n - 1) % sm * inv_fac[2] % sm + n) % sm * (1LL * m * (m + 1) % sm * inv_fac[2] % sm - ans + sm) % sm;

//        cout << ans; return;

        for(int x : vec) {
            int lst = 0;
            ll total = 0;
            for(int i : pos[x]) {
                add(total, 1LL * (C(2, i - lst - 1) + i - lst - 1)  * x % sm);
                lst = i;
            }
            if(a[n] != x) add(total, 1LL * (C(2, n - lst) + n - lst) * x % sm);
            add(ans, total);
        }
        cout << ans;
    }
}

main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    #define __Azul__ "qs"
    if(fopen(__Azul__".inp", "r")) {
        freopen(__Azul__".inp", "r", stdin);
        freopen(__Azul__".out", "w", stdout);
    }

    prepare();
    bool qs = 0;

    int T = 1;
    if(qs) cin >> T;
    while(T--) {
        inp();
        sub2 :: slv(); return 0;
        if(sub1 :: check_sub()) sub1 :: slv();
        else sub2 :: slv();
    }

    cerr << "\nTime" << 0.001 * clock() << "s "; return 0;


}

