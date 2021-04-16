#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
    ll N; scan(N);
    unordered_map<ll, string>umap;
    unordered_map<ll, ll>freq;
    for(int i = 0; i < N; ++i){
        string name; ll num;
        cin>>name; scan(num);
        umap[num] = name;
    }
    ll calls, freqs = 0,number; scan(calls);
    for(ll i = 0; i < calls; ++i){
        ll num; scan(num);
        freq[num]++;
    }
    for(auto && it  : freq){
        if(it.second>freqs){
            number = it.first;
            freqs = it.second;
        }
        if(it.second == freqs){
            if(it.first<number){
                number = it.first;
            }
        }
    }
    cout<<umap[number]<<endl;
    return 0;
}
