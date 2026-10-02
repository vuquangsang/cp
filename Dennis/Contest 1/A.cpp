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


string str;
int n;
void inp()
{
    cin >> str;
    str = ' ' + str;
    n = str.size() - 1;
}

namespace sub1
{   
    int get(int x, int y) 
    {
        int cnt = 0;
        int cur = x;
        FOR(i, 1, n) {
            if(str[i] - '0' == cur) {
                cnt++;
                cur = (cur == x ? y : x);
            }
        }
        if(x != y && cnt & 1) cnt--;
        return cnt; 
    }
    void slv()
    {
        int ans = n + 1;
        FOR(x, 0, 9) FOR(y, 0, 9) {
            mini(ans, n - get(x, y));
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