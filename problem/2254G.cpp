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

int n, a[N], p[N];
vector<int> adj[N];
void inp()
{
    cin >> n;
    FOR(i, 1, n) adj[i].clear(), p[i] = 0;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 2, n) {
        cin >> p[i];
        adj[p[i]].push_back(i);
    }
}


namespace sub1
{
    multiset<int> mst[N];
    ll ans[N];
    void slv()
    {
        FOR(i, 1, n) mst[i].clear();

        vector<int> vec;
        for(int i = n; i >= 1; i--) {
            if(mst[i].empty()) {
                mst[i].insert(a[i]);
            }
            else {
                int x = *(mst[i].begin());
                mst[i].erase(mst[i].find(x));
                vec.push_back(min(x, a[i]));
                mst[i].insert(max(a[i], x));
            }
            if(i > 1) {
                if(mst[p[i]].size() < mst[i].size()) swap(mst[p[i]], mst[i]);
                for(int x : mst[i]) mst[p[i]].insert(x);
                mst[i].clear();
            }
        }
        int numLeaf = mst[1].size();
//        cout << numLeaf << el;

        FOR(i, 1, n) ans[i] = 0;
        ll sum = 0;
        while(mst[1].size()) {
            sum += *(mst[1].begin());
            mst[1].erase(mst[1].begin());
        }

        sort(all(vec), [&](int x, int y) {
            return x > y;
        });

        ans[numLeaf] = sum;
        ll total = 0;
        FOR(i, 0, vec.size() - 1) {
            total += vec[i];
            ans[numLeaf + i + 1] = sum + total;
        }
        FOR(i, 1, n) {
            if(i < numLeaf) cout << -1 << " ";
            else cout << ans[i] << " ";
        } cout << el;
    }
}


main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    #define __Azul__ "2254G"
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

    cerr << "\nTime" << 0.001 * clock() << "s "; return 0;


}

