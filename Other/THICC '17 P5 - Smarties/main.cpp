#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a, b, sizeof(a));
#define mp make_pair
#define pb push_back
#define s second
#define f first
char _;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const int MAXN = 1e6+10;
using namespace std;
int a[MAXN];
int main()
{
    int N, K;ll res = 0; scan(N); scan(K);
    unordered_map<int, int> freq;
    for(int i = 0; i < N; ++i){
        scan(a[i]);
    }
    for(int l = 0, r = 0; r < N; ++r){
        ++freq[a[r]];
        while(freq.size()>=K){
            res += N-r;
            --freq[a[l]];
            if(!freq[a[l]])freq.erase(a[l]);
            ++l;
        }
    }
    cout<<res<<endl;
    return 0;
}
