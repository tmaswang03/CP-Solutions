#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a, b, sizeof(a));
#define mp make_pair
#define pb push_back
#define boost() cin.tie(0); cin.sync_with_stdio(0);
char _;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll MM = 4e3+10;
using namespace std;
int freq[MM];
vector<int> sols;
int main()
{
    int N, max1 = 0; scan(N); ms(freq, 0);
    for(int i = 0; i < N; ++i){
        int l; scan(l); ++freq[l];
    }
    for(int s = 2; s <= 4000; ++s){
        int counter = 0;
        for(int i = 1; i < s; ++i){
            counter+=min(freq[i], freq[s-i]);
        }
        counter/=2;
        if(counter > max1){
            sols.clear(); sols.pb(s); max1 = counter;
        }
        else if(counter == max1){
            sols.pb(s);
        }
    }
    printf("%d %d\n", max1, sols.size());
    return 0;
}
