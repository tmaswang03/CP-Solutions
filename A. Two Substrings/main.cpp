#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
#define s second
#define f first
char _;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;
string str; vector<int> ab, ba;
int main()
{
    cin>>str;
    for(int i = 0; i <= (ll)(str.length())-2; ++i){
        if(str.substr(i, 2) == "AB") ab.eb(i);
        else if(str.substr(i, 2)== "BA") ba.eb(i);
    }
    for(auto && i : ab){
        for(auto && j : ba){
            if(i+1 < j || j+1 < i){
                cout<<"YES"<<endl; return 0;
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
