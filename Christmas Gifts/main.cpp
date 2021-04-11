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
const ll MM = 1e3+10;
using namespace std;
typedef pair<ll, ll> pll;
ll N, B, cnt = 0, add = 0;  pll a [MM];
bool cmp (pll &a, pll &b){return a.f+a.s < b.f+b.s;}
int main()
{
    cin>>N>>B;
    for(int i = 0; i < N; ++i) cin>>a[i].f>>a[i].s;
    sort(a, a+N, cmp);
    for(int i = 0; i < N;  ++i){
        if(a[i].f+a[i].s<=B){ ++cnt; B-=a[i].f+a[i].s;}
        else{
            for(int j = i; j < N; ++j){
                if(a[i].f/2+a[i].s <= B){
                    ++cnt; cout<<cnt<<endl; return 0;
                }
            }
            for(int j = 0; j < i; ++j){
                add = max(add, a[i].f/2);
            }
            B+=add;
            if(a[i].f+a[i].s <= B) ++cnt;
            cout<<cnt<<endl; return 0;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
