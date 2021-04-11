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
using namespace std;
int r, c, ro, x, y;
set<int>rs, cs;

int main()
{
    for(int t = 0; t < 5; ++t){
        cin>>r>>c>>ro; rs.clear(); cs.clear();
        for(int i = 0; i < ro; ++i){
            cin>>x>>y;
            rs.insert(x); cs.insert(y);
        }
        cout<<(r-rs.size())*(c-cs.size())<<endl;
    }
    return 0;
}
