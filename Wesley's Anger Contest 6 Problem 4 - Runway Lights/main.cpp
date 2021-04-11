#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define REP(i, N) for(int i = 0; i < N; ++i)
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
const ll mod = 998244353;
using namespace std;
ll N, K, res, len, psa[300*300+10]; string s, a, b; vector<int> v[3];
int main()
{
    cin>>N>>K;
    cin>>a;
    for(int i = 0; i < a.length(); ++i){
        if(a[i]=='W' || a[i]== 'A' || a[i] =='C') b.pb(a[i]);
    }
    // every time you
    for(int i = 0; i < K; ++i) s+=b;
    len = s.length();
    for(int i = s.length()-1; i >= 0; --i){
        psa[i] = s[i]=='C'; psa[i]+=psa[i+1];
    }
    for(int i = 0; i < len; ++i){
        if(s[i]=='W'){
            for(int j = i+1; j < len; ++j){
                if(s[j]=='A'){
                    res+=psa[j+1];
                }
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
