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

ll rd(ll l, ll r) {return l + 1LL * rand() * rand() % (r - l + 1);}

int ans[10], a[10];
bool isValid[10];
map<int, int> mp;
int getR1()
{
    int res = 0;
    FOR(i, 1, 4) if(a[i] == ans[i]) {
        res++;
        isValid[i] = 1;
    }
    return res;
}
int getR2()
{
    mp.clear();
    FOR(i, 1, 4) if(!isValid[i]) mp[a[i]]++;
    int res = 0;
    FOR(i, 1, 4) if(!isValid[i] && mp[ans[i]] > 0) {
        res++;
        mp[ans[i]]--;
    }
    return res;
}

set<int> S;

int calc(int number, int R1, int R2)
{
    vector<int> vec(5);

    while(number > 0) {
        vec[i] = number / 10;
    }
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    srand(time(0));

    #define __Azul__ ""
    if(fopen(__Azul__".inp", "r")) {
        freopen(__Azul__".inp", "r", stdin);
        freopen(__Azul__".out", "w", stdout);
    }


    int qs = 0;
//    cout << "Do you want to be a player or a referee? Choose 1 for a player, or 2 for a referee." << endl;
//    cin >> qs;

    if(qs) {
        FOR(i, 1, 4) ans[i] = rd(1, 6);
        int n = 10;
        while(n--) {
            cout << "Please choose 4 random numbers from 1 to 6." << endl;
            FOR(i, 1, 4) cin >> a[i];

            FOR(i, 1, 4) isValid[i] = 0;

            int R1 = getR1();
            int R2 = getR2();
            if(R1 == 4) {
                cout << "You win !";
                return 0;
            }
            cout << "Result -> R1: " << R1 << " | R2: " << R2 << endl;
        }
        cout << "You are lose !" << endl;
        FOR(i, 1, 4) cout << ans[i] << " "; cout << endl;
    }
    else {
        FOR(i, 1, 4) cin >> ans[i];

        FOR(i, 1, 6) FOR(j, 1, 6) FOR(x, 1, 6) FOR(y, 1, 6) {
            ll val = i * 1000 + j * 100 + x * 10 + y;
            S.insert(val);
        }

        cout << S.size() << el;

        a[1] = a[2] = 1;
        a[3] = a[4] = 2;

        int number = 1122;

        int R1 = getR1(), R2 = getR2();

        int ans = calc(number, R1, R2);
    }

    cerr << "\nTime" << 0.001 * clock() << "s "; return 0;


}

