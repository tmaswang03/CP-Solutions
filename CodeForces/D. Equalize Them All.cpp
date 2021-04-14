#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 2e5+10;
using namespace std;
int N, a[MM], freq[MM], ch = 0, te = 0;
int main()
{
    cin>>N;
    for(int i = 0; i < N; ++i){
        cin>>a[i]; ++freq[a[i]];
        if(freq[a[i]]>te){
            te = freq[a[i]]; ch = a[i];
        }
    }
    cout<<N-te<<endl;
    while(freq[ch]!=N){
        for(int i = 1; i < N; ++i){
            if(a[i]!=ch&&a[i-1]==ch){
                if(a[i]>ch) cout<<2<<" "<<i+1<<" "<<i<<endl;
                else cout<<1<<" "<<i+1<<" "<<i<<endl;
                a[i] = ch; ++freq[ch];
            }
        }
        for(int i = N-2; i >= 0; --i){
            if(a[i]!=ch&&a[i+1]==ch){
                if(a[i]>ch) cout<<2<<" "<<i+1<<" "<<i+2<<endl;
                else cout<<1<<" "<<i+1<<" "<<i+2<<endl;
                a[i] = ch; ++freq[ch];
            }
        }
    }
    return 0;
}
