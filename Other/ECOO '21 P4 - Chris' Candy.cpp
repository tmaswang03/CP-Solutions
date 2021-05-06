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
ll K, N, A, cnt, idx = 1; vector<ll>v;
int main()
{
    cin>>K; ++K;
    // idea : prime factorize
    // for each prime factor add P-1 of one type of candy
    while(K%2==0){ v.pb(2); K/=2; }
    for(ll i = 3; i*i <= K; i+=2){
        while(K%i==0){
            v.pb(i); K/=i;
        }
    }
    if(K>2) v.pb(K);
    for(auto && i : v) cnt+=i-1;
    if(cnt>1e5){
        cout<<"Sad Chris"<<endl; return 0;
    }
    cout<<cnt<<endl;
    for(int i = 0; i < v.size()-1; ++i){
        for(int j = 0; j < v[i]-1; ++j){
            cout<<idx<<" ";
        }
        ++idx;
    }
    for(int j = 0; j < v[v.size()-1]-2; ++j) cout<<idx<<" ";
    cout<<idx<<endl;
    return 0;
}