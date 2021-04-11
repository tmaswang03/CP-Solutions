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
string in;
int conv(char a, char b, char c){
    int x = (int)(a-'0'), y = (int)(b-'0'), z = (int)(c-'0');
    return 100*x+10*y+z;
}
int main()
{
    cin>>in;
    for(int i = 0; i < in.length(); ++i){
        if(conv('0', '0', in[i])%8==0){
            cout<<"YES\n"<<conv('0', '0', in[i])<<endl;
            return 0;
        }
    }

    for(int i = 0; i < in.length(); ++i){
        if(in[i]=='0') continue;
        for(int j = i+1; j < in.length(); ++j){
            if(conv('0', in[i], in[j])%8==0){
                    cout<<"YES\n"<<conv('0', in[i], in[j])<<endl;
                    return 0;
            }
        }
    }
    for(int i = 0; i < in.length(); ++i){
        if(in[i]=='0') continue;
        for(int j = i+1; j < in.length(); ++j){
            for(int k = j+1; k < in.length(); ++k){
                if(conv(in[i], in[j], in[k])%8==0){
                    cout<<"YES\n"<<conv(in[i], in[j], in[k])<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
