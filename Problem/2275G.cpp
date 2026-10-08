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

int n, m, q;
struct Edge {
    int x, y, d;
    bool operator<(const Edge&other) const {
        return d < other.d;
    }
} E[N];
void inp()
{
    cin >> n >> m >> q;
    FOR(i, 1, m) {
        int x, y, d; cin >> x >> y >> d;
        E[i] = {x, y, d};
    }
}

namespace sub1
{
    int lab[N];
    int root(int x) {return lab[x] < 0 ? x : lab[x] = root(lab[x]);}
    bool joint(int x, int y) 
    {
        x = root(x); y = root(y);
        if(x == y) return 0;
        if(lab[x] < lab[y]) swap(x, y);
        lab[x] += lab[y];
        lab[y] = x;
        return 1;
    }
    void slv()
    {
        FOR(i, 1, n) lab[i] = -1;
        sort(alla(E, m));

        ll sum = 0;
        vector<int> we;
        FOR(i, 1, m) {
            sum += E[i].d;
            if(joint(E[i].x, E[i].y)) {
                we.push_back(E[i].d);
            }
        }
        int sz = we.size();
        vector<long long> pre(sz + 1, 0);
        for(int i = 0; i < we.size(); i++) {
            pre[i + 1] = pre[i] + we[i];
        }

        while(q--) {
            int x; cin >> x;
            
            int l = 1, r = sz, mid, ans = 0;
            while(l <= r) {
                mid = (r + l) >> 1;
                if(we[mid - 1] <= 1LL * (n - mid) * x) {
                    ans = mid, l = mid + 1;
                }
                else r = mid - 1;
            }
            int cnt = n - 1 - ans;
            ll res = sum - pre[ans] - 1LL * x * cnt * (cnt + 1) / 2;
            cout << res <<  " ";
        } cout << el;
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