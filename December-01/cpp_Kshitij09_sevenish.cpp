//
// Created by Kshitij Patil.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M int(floor(log(LONG_LONG_MAX)/log(7)))

void fast_exp(ll a, ll n, ll e[]) {
    e[0] = 1;
    e[1] = a;
    for (int i = 2; i <= n; i++)
        e[i] = e[i / 2] * (!(i & 1) ? e[i / 2] : e[i / 2] * a);
}

ll sevenish(int n, const ll e[]) {
    ll res = 0;
    for (int i = 0; i <= M && n; ++i) {
        if (n & 1)
            res += e[i];
        n >>= 1;
    }
    return res;
}

int main(int argc, char *argv[]) {

    ll e[M + 1];
    fast_exp(7, M, e);

    int n;
    cin >> n;

    cout << sevenish(n, e);


    return 0;
}