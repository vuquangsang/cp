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
    cin >> n;
    cin >> str;
    str = ' ' + str;
}

namespace sub1
{
    void slv()
    {
        vector<int> vec;
        vector<bool> isValid(n + 2);
        FOR(i, 1, n) {
            if(str[i] == '1') vec.push_back(i);
            else if(str[i] == '2') {
                if(vec.empty()) isValid[i] = 1;
                else isValid[vec.back()] = 1, vec.pop_back();
            }
            else isValid[i] = 1;
        }
        vector<int> ans;
        FOR(i, 1, n) if(!isValid[i]) ans.push_back(i);
        cout << ans.size() << el;
        for(int x : ans) cout << x << " "; cout << el;
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