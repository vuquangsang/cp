#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define el "\n"


#define TASK "qs"
ll rd(ll l, ll r ) {return l + 1LL * rand() * rand() % (r - l + 1);}
void inp()
{
    ofstream cout(TASK".INP");

    int T = rd(2, 4);
    cout << T << el;
    while(T--) {
        int n = rd(3, 5); cout << n << el;
        FOR(i, 1, n) cout << rd(1, 7) << " "; cout << el;
        vector<int> a(n);
        for(int i = 0; i < n - 1; i++) a[i] = i + 1;
        shuffle(a.begin(), a.end());
        for(int x : a) cout << x << " "; cout << el;
    }

    cout << el;
    cout.close();
}
main()
{
    srand(time(0));

    int T = 100;
    FOR(i, 1, T){
        inp();
        system(TASK "_trau.exe");
        system(TASK ".exe");

        if(system("fc " TASK ".OUT " TASK ".ANS") != 0) {
            cout << "test" << " " << i << " " << "wa";
            return 0;
        }
        cout << "test" << " " << i << " " << "ac" << el;
    }
}

