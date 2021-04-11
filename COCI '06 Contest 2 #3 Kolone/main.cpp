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
int a, b, t, len; string s1, s2; bool group[30];
int main()
{
    cin>>a>>b>>s1>>s2>>t; reverse(s1.begin(), s1.end());
    for(int i = 0; i < s1.length(); ++i) group[i] = 1;
    s1+=s2; len = s1.length();
    while(t--){
        for(int i = 0; i < len-1; ++i){
            if(group[i+1]<group[i]){ swap(group[i], group[i+1]); swap(s1[i], s1[i+1]); ++i; }
        }
    }
    cout<<s1<<endl;
    return 0;
}
