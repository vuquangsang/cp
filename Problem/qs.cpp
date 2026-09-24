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
const int inf = 1e16;
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
    ll st[4 * N], lz[4 * N];

    void down(int id)
    {
        if(lz[id]) {
            ll val = lz[id];
            st[id << 1] += val; st[id << 1 | 1] += val;
            lz[id << 1] += val; lz[id << 1 | 1] += val;
            lz[id] = 0;
        }
    }
    void upd(int id, int l, int r, int u, int v, ll val)
    {
        if(r < u || v < l) return;
        if(u <= l && r <= v) {
            st[id] += val;
            lz[id] += val;
            return;
        }
        int mid = (r + l) >> 1;
        down(id);
        upd(id << 1, l, mid, u, v, val);
        upd(id << 1 | 1, mid + 1, r, u, v, val);
        st[id] = min(st[id << 1], st[id << 1 | 1]);
    }
    int get(int id, int l, int r, int pos)
    {
        if(l == r) return st[id];
        int mid = (r + l) >> 1;
        down(id);
        if(pos <= mid) return get(id << 1, l, mid, pos);
        return get(id << 1 | 1, mid + 1, r, pos);
    }
    int walk(int id, int l, int r, int u, int v, ll val)
    {
        if(r < u || v < l || st[id] >= val) return -1;
        if(l == r) return l;
        int mid = (r + l) >> 1;
        down(id);
        int res = walk(id << 1, l, mid, u, v, val);
        if(res != -1) return res;
        return walk(id << 1 | 1, mid + 1, r, u, v, val);
    }


    bool isDel[N];
    int ans[N];
    ll pre[N];

    void update(int pos)
    {
        upd(1, 1, n, pos + 1, n, -a[pos]);
        upd(1, 1, n, pos, pos, inf);
        a[pos] = 0;
    }
    void slv()
    {
        FOR(id, 1, 4 * n) st[id] = lz[id] = 0;
        FOR(i, 1, n) isDel[i] = ans[i] = 0;

        pre[0] = 0;
        FOR(i, 1, n) pre[i] = pre[i - 1] + a[i];

        FOR(i, 1, n) upd(1, 1, n, i, i, pre[i - 1] - a[i]);

//        FOR(i, 1, n) cout << pre[i - 1] - a[i] << " "; cout << el;

        FOR(t, 0, n - 1) {
            if(t > 0) {
                update(p[t]);
                isDel[p[t]] = 1;
            }

            int pos = 0;
            FOR(i, 1, n) if(!isDel[i]) {
                pos = i;
                break;
            }

            ll strong = get(1, 1, n, pos) + a[pos];
//            cout << strong; return;
            int res = 0;
            while(1) {
                int far = walk(1, 1, n, pos + 1, n, strong);
                if(far == -1) {
                    break;
                }
                res++;
                pos = far;
                strong = get(1, 1, n, pos) + a[pos];
            }

            ans[t] = res;
        }
        FOR(t, 0, n - 1) cout << ans[t] << " "; cout << el;
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

