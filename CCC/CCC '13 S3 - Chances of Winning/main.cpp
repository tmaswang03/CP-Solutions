#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define s second
#define f first
char _;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 6;
using namespace std;
bool done[MM][MM];
int T, G, a, b, sa, sb, scores[MM], a1[MM] = {3,1,0}, b1[MM] = {0,1,3};
vector<pii> v;
bool frst(){
    for(int i = 1; i <= 4; ++i){
        if(i==T) continue;
        if(scores[i]>=scores[T]) return 0;
    }
    return 1;
}
int solve(int cur){
    int res = 0;
    if(cur==v.size()){
        return frst();
    }
    for(int i = 0; i < 3; ++i){
        scores[v[cur].f]+=a1[i]; scores[v[cur].s]+=b1[i];
        res+=solve(cur+1);
        scores[v[cur].f]-=a1[i]; scores[v[cur].s]-=b1[i];
    }
    return res;
}
int main()
{
    cin>>T>>G;
    for(int i = 0; i < G; ++i){
        cin>>a>>b>>sa>>sb;
        done[a][b] = 1; done[b][a] = 1;
        if(sa>sb) scores[a]+=3;
        else if (sa==sb){ ++scores[a]; ++scores[b]; }
        else scores[b]+=3;
    }
    for(int i = 1; i <= 4; ++i){
        for(int j = 1; j < i; ++j){
            if(!done[j][i]) v.pb({j,i});
        }
    }
    cout<<solve(0)<<endl;
    return 0;
}
