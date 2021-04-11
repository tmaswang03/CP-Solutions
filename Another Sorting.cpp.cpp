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
const ll MM = 1e5+20;
using namespace std;
int a[MM], N;
bool comp(int a, int b){
    if(a%10==b%10) return a>b;
    return a%10<b%10;
}

int main()
{
    cin>>N;
    for(int i = 0; i < N; ++i) cin>>a[i];
    sort(a, a+N, comp);
    for(int i = 0; i < N; ++i){
        cout<<a[i]<<" ";
    }
    return 0;
}
