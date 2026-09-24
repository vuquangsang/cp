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
const long long inf = 1e16;
int n, a[N], p[N];

void inp()
{
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> p[i];
}


namespace sub1
{
    bool isDel[N];
    int ans[N];
    void slv()
    {
        FOR(i, 1, n) isDel[i] = 0;
        FOR(t, 0, n - 1) {
            if(t > 0) isDel[p[t]] = 1;

            ll strong  = 0;
            int res = 0;
            FOR(i, 1, n) if(!isDel[i]) {
                if(strong == 0) {
                    strong = a[i];
                    continue;
                }
                if(strong < a[i]) {
                    res++;
                    strong = a[i];
                }
                else strong += a[i];
            }
            ans[t] = res;
        }
        FOR(i, 0, n - 1) cout << ans[i] << " "; cout << el;
    }
}

namespace sub2
{
    ll bit[N];

    void upd(int x, int v)
    {
        for(; x <= n; x += x & - x) bit[x] += v;
    }
    ll get(int x)
    {
        ll ans = 0;
        for(; x >= 1; x -= x & -x) ans += bit[x];
        return ans;
    }
    ll get(int l, int r)
    {
        return get(r) - get(l - 1);
    }
    set<int> S;
    int ans[N];
    void slv()
    {
        FOR(i, 1, n) bit[i] = 0;
        S.clear();
        for(int i = n; i >= 1; i--) {
            auto it = S.lower_bound(p[i]);
            int pos;
            if(it == S.begin() || get(*prev(it), p[i]) < a[p[i]]) {
                pos = p[i];
                S.insert(p[i]);
            }
            else pos = *prev(it);
            upd(p[i], a[p[i]]);

            while(S.upper_bound(p[i]) != S.end()) {
                int far = *S.upper_bound(p[i]);
                if(get(pos, far - 1) >= a[far]) S.erase(far);
                else break;
            }
            ans[i] = S.size() - 1;
        }
        FOR(i, 1, n) cout << ans[i] << " " ; cout << el;
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

    bool qs = 1;

    int T = 1;
    if(qs) cin >> T;
    while(T--) {
        inp();
        sub2 :: slv();
    }

    cerr << "\nTime" << 0.001 * clock() << "s "; return 0;


}

