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
int t, a, b, res; string stra, strb, stres;
int main()
{
    cin>>t;
    while(t--){
        cin>>stra>>strb;
        reverse(stra.begin(), stra.end()); reverse(strb.begin(), strb.end());
        a = stoi(stra); b = stoi(strb);
        res = a+b;  stres = to_string(res);
        while(!stres.empty() && stres.back()=='0') stres.pop_back();
        reverse(stres.begin(), stres.end());
        cout<<stres<<endl;
    }
    return 0;
}
