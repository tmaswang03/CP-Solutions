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
ll N, M, K, x, y, cntr, cntc; map<ll, bool> r, c;
int main()
{
    cin>>N>>M>>K;
    for(int i = 0; i < K; ++i){
        cin>>x>>y; r[x]^=1; c[y]^=1;
        if(r[x]) ++cntr;
        else --cntr;
        if(c[y]) ++cntc;
        else --cntc;
    }
    auto itc = c.begin(), itr = r.begin();
    cout<<max(cntr, cntc)<<endl;
    if(cntr>cntc){
        while(itr!=r.end()){
            if(itr->s){
                while(itc!=c.end() && itc->s==0) ++itc;
                cout<<itr->f<<" "<<itc->f<<endl;
                if(itc!=c.end()) ++itc;
            }
            ++itr;
        }
    }
    else{
        while(itc!=c.end()){
            if(itc->s){
                while(itr!=r.end() && itr->s==0) ++itr;
                cout<<itr->f<<" "<<itc->f<<endl;
                if(itr!=r.end())++itr;
            }
            ++itc;
        }
    }
    return 0;
}
