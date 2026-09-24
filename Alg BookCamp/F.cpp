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
const int maxVal = 1e6 + 2;


int n, a[N];

void inp()
{
    cin >> n; FOR(i, 1, n) cin >> a[i];
}


namespace sub1
{

    void slv()
    {
        FOR(i, 1, n) {
            int ans = 0;
            FOR(j, 1, n) if((a[i] & a[j]) != 0) ans++;
            cout << ans << el;
        }
    }
}

namespace sub2
{
    int cnt[(1 << 21) + 5];
    void slv()
    {
        FOR(i, 1, n) cnt[a[i]]++;
        int lim = (1 << 20) - 1;
        for(int i = 0; i < 20; i++) {
            for(int msk = 0; msk < (1 << 20); msk++) {
                if(msk >> i & 1) cnt[msk] += cnt[msk ^ (1 << i)];
            }
        }
        FOR(i, 1, n) {
            int temp_msk = lim ^ a[i];
            cout << n - cnt[temp_msk] << el;
        }
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

