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
const ll MM = 1e3+10;
using namespace std;
int a[MM], res[MM]; string s;
int main()
{
    // consider sequence of 1 and 0
    // find the greatest number :
    // idea :
    // if the current number is an a, flip it to the beginning of the string (keep it there until next a comes along)
    // then when next a comes along flip the previous b
    // if the previous letter was a don't flip previous letter
    // this results in the best sequence.
    cin>>s;
    for(int i = 1; i <= s.length(); ++i) a[i] = (s[i-1]=='a');
    for(int i = 1; i <= s.length(); ++i){
        if(a[i]){
            res[i] = 1;
            if(a[i-1]) res[i-1] = 0;
            else res[i-1] = 1;
        }
    }
    for(int i = 1; i <= s.length(); ++i){
        cout<<res[i]<<" ";
    }
    return 0;
}
