#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define f first
#define s second
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 1e3+10;
using namespace std;
int N, a[MM];
bool check(){
    for(int i = 0; i < N; ++i) if(a[i]!=i) return 0;
    return 1;
}
int main()
{
    scan(N);
    for(int i = 0; i < N; ++i){
        scan(a[i]);
    }
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(j%2){
                a[j]+=1; a[j]%=N;
            }
            else{
                a[j]-=1; if(a[j]<0) a[j]=N-1;
            }
        }
        if(check()){
            cout<<"Yes"<<endl; return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}
