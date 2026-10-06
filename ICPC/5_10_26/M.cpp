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

int n, q;

void inp()
{
    cin >> n >> q;
}

namespace sub1
{
    set<int> S;
    void slv()
    {
        FOR(i, 0, n - 1) S.insert(i);

        while(q--) {
            int k; cin >> k;
            
            auto it = S.lower_bound(k);
            
            int valp, vals;
            valp = vals = -1;
            if(it != S.end()) {
                vals = *it;
            }
            if(it != S.begin()) {
                valp = *(prev(it));
            }
            
            int ans = 0;
            if(valp == -1) ans = vals, S.erase(vals);
            else if(vals == -1) ans = valp, S.erase(valp);
            else {
                if(abs(k - valp) <= abs(k - vals)) {
                    ans = valp;
                    S.erase(valp);
                }
                else {
                    ans = vals;
                    S.erase(vals);
                }
            }

            cout << ans << el;
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
        sub1 :: slv();
    }

    cerr << "\nTime " << 0.001 * clock() << "s "; return 0;
}