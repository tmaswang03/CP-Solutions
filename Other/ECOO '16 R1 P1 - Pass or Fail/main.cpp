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
int cnt, N, w1, sum, wes[5];
int main()
{
    for(int t = 0; t < 10; ++t){
        cnt = 0;
        for(int i = 0; i < 4; ++i) cin>>wes[i];
        cin>>N;
        for(int i = 0; i < N; ++i){
            sum = 0;
            for(int j = 0; j < 4; ++j){
                cin>>w1; sum+=w1*wes[j];
            }
            cnt+= ((1.0*sum)/(100.0)>=50.0);
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
