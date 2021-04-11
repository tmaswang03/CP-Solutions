#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define f first
#define s second
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 101;
using namespace std;
string s[MM], bord = "##";
int main()
{
    boost();
    int H, W; cin>>H>>W;
    for(int i = 0; i < H; ++i){
        cin>>s[i];
    }
    for(int i = 0; i < W; ++i){
        bord+='#';
    }
    cout<<bord<<"\n";
    for(int i = 0; i < H; ++i){
        cout<<"#"<<s[i]<<"#"<<"\n";
    }
    cout<<bord<<"\n";
    return 0;
}
