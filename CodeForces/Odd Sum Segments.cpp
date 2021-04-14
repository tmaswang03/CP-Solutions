#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0); cout.tie(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define f first
#define s second
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 2e5+10;
using namespace std;
int a[MM], q;
int main()
{
    scan(q);
    while(q--){
        int n, k, odd; scan(n); scan(k);
        for(int i = 0; i < n; ++i){
            scan(a[i]);
            if(a[i]%2){
                ++odd; a[i] = 1;
            }
            else a[i] = 0;
        }
        if((odd-k)%2==0 && odd >= k){
            printf("YES\n");
            int oddc = 0;
            for(int i = 0; i < N; ++i){
                oddc += a[i];
                if(oddc)
            }
        }
    }
    return 0;
}
