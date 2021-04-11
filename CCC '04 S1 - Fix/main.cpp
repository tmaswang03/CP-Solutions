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
string a[3];int N; bool ye;
int len(string x){return x.length();}
bool check(int x){
    for(int i = 0; i < 3; ++i){
        if(i==x||len(a[x])>len(a[i])) co
            ntinue;
        if(a[x]==a[i].substr(0, len(a[x]))||a[x]==a[i].substr(len(a[i])-len(a[x]), len(a[x]))) return 0;
    }
    return 1;
}
int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin>>N;
    while(N--){
        ye = 1;
        for(int i = 0; i < 3; ++i) cin>>a[i];
        for(int i = 0; i < 3; ++i){
            if(!check(i)){ cout<<"No"<<endl; ye = 0; break;}
        }
        if(ye) cout<<"Yes"<<endl;
    }
    return 0;
}
