#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define f first
char _;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;
int N; string s;
bool m, sc;
int main()
{
    cin>>N;
    while(N--){
        cin>>s;
        bool m = 0, sc = 0;
        for(int i = 0; i < s.length(); ++i){
            if(s[i]=='M') m = 1;
            if(s[i]=='C') sc = 1;
        }
        if(!m && !sc) cout<<"PASS"<<endl;
        else if(m && sc) cout<<"NEGATIVE MARKS"<<endl;
        else cout<<"FAIL"<<endl;
    }
    return 0;
}
