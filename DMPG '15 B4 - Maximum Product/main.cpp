#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define f first
#define s second
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 35;
using namespace std;
int N, res = 1;
bool zer = 0;
vector<int> pos, neg;
int main()
{
    boost();
    cin>>N;
    for(int i = 0; i < N; ++i){
        int a; cin>>a;
        if(a>0) pos.pb(a);
        else if(a<0) neg.pb(a);
        else zer = 1;
    }
    for(int i = 0; i < pos.size(); ++i){
        res*=pos[i];
    }
    sort(neg.begin(), neg.end());
    for(int i = 0; i < neg.size(); ++i){
        if(i&1){
            res*=neg[i-1]*neg[i];
        }
    }
    if(neg.empty() && pos.empty()){
        cout<<0<<endl;
    }
    else if(neg.size()<=1 && zer && pos.empty()){
        cout<<0<<endl;
    }
    else if(neg.size()<=1 && pos.empty()){
        cout<<neg[0]<<endl;
    }
    else{
        cout<<res<<endl;
    }
    return 0;
}
