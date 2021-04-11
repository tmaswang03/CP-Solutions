#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp(a,b) make_pair(a,b);
#define mt make_tuple;
#define push_back pb;
char _;
typedef long long ll;
const int MAXN = 100001;

using namespace std;

int main()
{
    ll difs[MAXN+1];
    ll arr[MAXN+1];
    ms(difs,0);
    ms(arr,0);
    ll N, M; scan(N); scan(M);
    for(int i = 0; i < M; ++i){
        ll l,r; cin>>l>>r;
        difs[l]+=1;
        difs[r+1]-=1;
    }
    for(int i = 1; i <= N; ++i){
        arr[i]=arr[i-1]+difs[i];
    }
    int counter = 0;
    for(int i = 1; i <= N; ++i){
        if(arr[i]%2==1){
            ++counter;
        }
    }
    cout<<counter<<endl;
    return 0;
}
