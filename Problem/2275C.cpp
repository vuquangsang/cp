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

int n, a[N];

void inp()
{
    cin >> n; FOR(i, 1, n) cin >> a[i];
}

namespace sub1
{
    map<int, int> mp;
    int vals[N];

    void slv()
    {
        mp.clear();
        FOR(i, 1, n - 4) {
            vals[i] = a[i] + a[i + 2] - a[i + 4];
        }
        ll ans = 0;
        FOR(i, 1, n - 4) {
            ans += mp[vals[i]];
            if(i > 2 && vals[i - 2] == vals[i]) ans--;
            if(i > 4 && vals[i - 4] == vals[i]) ans--;
            mp[vals[i]]++;
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