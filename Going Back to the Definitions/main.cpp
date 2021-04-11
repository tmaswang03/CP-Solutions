#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define f first
#define s second
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;
bool mycomp(string  &a, string &b){
    bool isa = 0;
    for(int i = 0; i < max(a.length(), b.length()); ++i){
        if(i >= a.length()||a[i] > b[i]){isa = 1; break;}
        if(isa >= b.length()||a[i] < b[i])  break;
    }
    return isa;
}
vector<string> v;
int main()
{
    boost();
    int N; cin>>N;
    for(int i = 0; i < N; ++i){
        string s; cin>>s;
        v.pb(s);
    }
    sort(v.begin(), v.end(), mycomp);
    for(int i = 0; i < v.size(); ++i){
        cout<<v[i];
    }
    return 0;
}
