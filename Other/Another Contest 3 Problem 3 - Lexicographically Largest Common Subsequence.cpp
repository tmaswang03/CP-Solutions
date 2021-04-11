#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;
const ll MM = 1e5+1;
string s[MM], res = "";
int ps[MM], temptr[MM];
bool comp(string s1, string s2){
    return s1.length()<s2.length();
}

bool contains(int l, char c, int i){
    for(temptr[i] = l+1; temptr[i] < s[i].length(); ++temptr[i]){
        if(s[i][temptr[i]]==c){
            return 1;
        }
    }
    return 0;
}

int main()
{
    boost();
    int N; cin>>N; ms(ps, -1);
    for(int i = 0; i < N; ++i)
        cin>>s[i];
    sort(s, s+N, comp);
    char cur = 'z';
    while(cur>='a'){
        bool subs  = 1;
        for(int i = 0; i < N; ++i){
            if(!contains(ps[i], cur, i)){
                subs = 0;
                break;
            }
        }
        if(subs){
            for(int i = 0; i < N; ++i){
                ps[i] = temptr[i];
            }
            res+=cur;
        }
        else --cur;
    }
    if(res.empty()) cout<<-1<<endl;
    else cout<<res<<endl;
    return 0;
}
