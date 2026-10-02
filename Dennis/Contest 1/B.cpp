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

const int N = 1e5 + 2;

int n, a[N];

void inp()
{
    cin >> n; FOR(i, 1, n) cin >> a[i];
}

namespace sub1
{
    const int SQRT = 500;

    int cnt[SQRT];

    int nxt[N], pos[N], lst[N];
    void slv() 
    {
        int lim = sqrt(2 * n) + 5;
        FOR(i, 1, n) {
            if(a[i] > lim) continue;
            if(!lst[a[i]]) lst[a[i]] = i;
            else nxt[lst[a[i]]] = i;
            lst[a[i]] = i;
        }

        ll ans = 0;

        FOR(i, 1, n) {
            if(a[i] > lim) continue;
            cnt[a[i]]++;

            if(!pos[a[i]]) pos[a[i]] = i;
            if(cnt[a[i]] > a[i]) pos[a[i]] = nxt[pos[a[i]]];

            int far = n + 1;
            FOR(val, 1, lim) {
                if(cnt[val] < val) break;
                far = min(far, pos[val]);
                if(val * (val + 1) / 2 == i - far + 1) ans++;
            }
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
        sub1 :: slv();
    }

    cerr << "\nTime " << 0.001 * clock() << "s "; return 0;
}