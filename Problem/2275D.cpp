#include <bits/stdc++.h>
using namespace std;

#define el "\n"
#define FOR(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define lg(x) __lg(x)
#define alla(a,n) a+1,a+n+1
#define ll long long

template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}

const int N = 2e5 + 2;

int n;
ll k;
struct Queries 
{
    ll a, b, c;
} ps[N];
void inp()
{
    cin >> n >> k;
    FOR(i, 1, n) {
        int a, b, c; cin >> a >> b >> c;
        ps[i] = {a, b, c};
    }
}

namespace sub1
{

    bool check(ll x) 
    {
        ll sumCnt = 0;
        FOR(i, 1, n) {
            ll total = ps[i].a + ps[i].b + ps[i].c;
            if(total >= x) continue;

            ll need = x - total;
            if(ps[i].a == ps[i].b && ps[i].b == ps[i].c) return 0;

            if(ps[i].a <= ps[i].b && ps[i].b <= ps[i].c) {
                sumCnt += 2LL * (min(ps[i].b - ps[i].a, ps[i].c - ps[i].b) + 1);
            }
            sumCnt += need;
            if(sumCnt > k) return 0;
        }
        return sumCnt <= k;
    }
    void slv()
    {
        ll l = -4e9, r = 2e18, mid, ans;
        while(l <= r) {
            mid = l + (r - l) / 2;
            if(check(mid)) ans = mid, l = mid + 1;
            else r = mid - 1;
        }
        cout << ans << el;
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
        sub1 :: slv();
    }

    cerr << "\nTime " << 0.001 * clock() << "s "; return 0;
}