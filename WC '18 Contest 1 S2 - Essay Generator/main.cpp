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
using namespace std;
int w, cnt; string s;
void gett(int len, int cur, int ma){
    if(cnt==w) return;
    if(cur==len){
        do{
            cout<<s<<" "; ++cnt;
            if(cnt==w) return;
        } while(next_permutation(s.begin(), s.end()));
        return;
    }
    for(int i = ma; i < 26; ++i){
        s+=char(i+'a');
        gett(len, cur+1, i);
        s.pop_back();
    }
}
int main()
{
    cin>>w;
    for(int i = 1; i <= 26; ++i){
        gett(i, 0, 0);
        if(cnt==w) return 0;
    }
}
