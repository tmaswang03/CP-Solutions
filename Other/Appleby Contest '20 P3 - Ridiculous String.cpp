#include<bits/stdc++.h>
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
using namespace std;
ll SS, TT, cur = -1, cnt; string S, T; vector<ll> v[30];
int main()
{
    cin>>SS>>TT>>S>>T;
    for(int i = 0; i < SS; ++i) v[S[i]-'a'].pb(i);
    for(int i = 0; i < TT; ++i){
        int ch = T[i]-'a';
        if(v[ch].size()==0){
            cout<<-1<<endl; return 0;
        }
        int pt = upper_bound(v[ch].begin(), v[ch].end(), cur) - v[ch].begin();
        if(pt == v[ch].size()){
            ++cnt; cur = v[ch][0];
        }
        else cur = v[ch][pt];
    }
    cout<<cnt*SS+cur+1<<endl;
    return 0;
}