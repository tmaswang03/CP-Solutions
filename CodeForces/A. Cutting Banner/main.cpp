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
using namespace std;
// problem is just finding if some order of the letters occurs before
string str, key = "CODEFORCES", tempstr; int cnt = 0;
int main()
{
    cin>>str;
    for(int i = 0; i <= str.length(); ++i){
        for(int j = i; j <= str.length(); ++j){
            tempstr = str.substr(0, i) + str.substr(j, str.length()-j);
            if(tempstr==key){cout<<"YES"<<endl; return 0;}
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
