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
ll K, D, a[10];
int main()
{
    cin>>K>>D;
    for(int i = 0; i < D; ++i) cin>>a[i];
    sort(a, a+D);
    if(D == 1 && a[0] == 0) {
        cout<<-1<<endl; return 0;
    }
    if(a[0] == 0){
        if(K>=2) {
            cout<<a[1];
            for(int i = 0; i < K-2; ++i) cout<<a[0];
            cout<<a[1]<<endl;
        }
        else cout<<a[1]<<endl;
    }
    else {
        for(int i = 0; i < K; ++i) cout<<a[0];
        cout<<endl;
    }
    return 0;
}