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

int n, k, a[N];

void inp()
{
    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];
}

namespace sub1
{   
    const int MAX = N * 31;

    struct Trie {
        int child[2];
        int id, cnt;
        Trie() {
            child[0] = child[1] = cnt = 0;
            id = -1;
        }
    } T[MAX];
    int idx = 0;

    void add(int x, int val) 
    {
        int r = 0;
        FORD(i, 31, 0) {
            bool v = (x >> i) & 1;
            if(T[r].child[v] == 0) {
                T[r].child[v] = ++idx;
            }
            r = T[r].child[v];
            maxi(T[r].id, val);
            T[r].cnt++;
        }
    }
    int Find(int x, int k) 
    {
        int r = 0, ans = -1;
        FORD(i, 31, 0) {
            bool bx = (x >> i) & 1;
            bool bk = (k >> i) & 1;
            if(bk) {
                r = T[r].child[bx ^ 1];
            }
            else {
                if(T[r].child[bx ^ 1]) maxi(ans, T[T[r].child[bx ^ 1]].id);
                r = T[r].child[bx];
            }
            if(T[r].cnt == 0) break;
        }
        maxi(ans, T[r].id);
        return ans;
    }

    void slv() 
    {
        int ans = n + 1;
        FOR(i, 1, n) {
            int pos = Find(a[i], k);
            if(pos != -1) mini(ans, i - pos + 1);
            add(a[i], i);
        }
        cout << (ans == n + 1 ? -1 : ans);
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