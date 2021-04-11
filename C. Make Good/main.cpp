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
typedef unsigned long long ll;
typedef long double ld;
const ll MM = 1e5+10;
using namespace std;
ll a[MM], t, n, xsum, sum;

int main()
{
    cin>>t;
    while(t--){
        cin>>n; xsum = sum = 0;
        for(int i = 0; i < n; ++i){
            cin>>a[i]; sum+=a[i]; xsum=1LL*(xsum^a[i]);
        }
        ll lg2 = log2(sum); ++lg2;
        if(2*xsum >= sum){
            if((2*xsum - sum)%2==0){
                cout<<2<<endl;
                cout<<(2*xsum-sum)/2<<" "<<(2*xsum-sum)/2<<endl;
            }
            else{
                ll add = 1LL<<lg2|1;
                xsum^=add; sum+=add;
                cout<<3<<endl;
                cout<<add<<" "<<(2*xsum-sum)/2<<" "<<(2*xsum-sum)/2<<endl;
            }
        }
        else{
            if((2*xsum-sum)%2==0){
                ll add = 1LL<<lg2;
                cout<<3<<endl; xsum^=add; sum+=add;
                cout<<add<<" "<<(2*xsum-sum)/2<<" "<<(2*xsum-sum)/2<<endl;
            }
            else{
                ll add = 1LL<<lg2|1;
                cout<<3<<endl; xsum^=add; sum+=add;
                cout<<add<<" "<<(2*xsum-sum)/2<<" "<<(2*xsum-sum)/2<<endl;
            }
        }
    }
    return 0;
}
