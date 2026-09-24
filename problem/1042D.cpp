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

const int N = 2e5 + 2;

int n, a[N];
long long t;
void inp()
{
    cin >> n >> t;
    FOR(i, 1, n) cin >> a[i];
}


namespace sub1
{
    long long sum[N];
    void slv()
    {
        FOR(i, 1, n) sum[i] = sum[i - 1] + a[i];

        ll ans = 0;
        FOR(i, 1, n) {
            FOR(j, 1, i) {
                if(sum[i] - sum[j - 1] < t) ans++;
            }
        }
        cout << ans;
    }
}

namespace sub2
{
    ll sum[N];
    vector<ll> vec;
    void compress()
    {
        vec.push_back(0);
        FOR(i, 1, n) vec.push_back(sum[i]), vec.push_back(sum[i] - t);
        sort(all(vec));
        vec.resize(unique(all(vec)) - vec.begin());
    }
    int getId(ll val)
    {
        return lower_bound(all(vec), val) - vec.begin() + 1;
    }

    int bit[2 * N];
    int lim;
    void upd(int x, int v)
    {
        for(; x >= 1; x -= x & -x) bit[x] += v;
    }
    ll get(int x)
    {
        ll ans = 0;
        for(; x <= lim; x += x & -x) ans += bit[x];
        return ans;
    }
    void slv()
    {
        FOR(i, 1, n) sum[i] = sum[i - 1] + a[i];
        compress();
        lim = vec.size();

        ll ans = 0;
        upd(getId(0), 1);

        FOR(i, 1, n) {
            ans += get(getId(sum[i] - t) + 1);
            upd(getId(sum[i]), 1);
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

    bool qs = 0;

    int T = 1;
    if(qs) cin >> T;
    while(T--) {
        inp();
        sub2 :: slv();
    }

    cerr << "\nTime" << 0.001 * clock() << "s "; return 0;


}
