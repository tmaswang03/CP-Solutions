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
typedef double dbl;
typedef unsigned long long ull;
const ll MM = 5e5+10;
using namespace std;
int psa[MM], a[MM], N, res, lft, rgt;
vector<int>mids[MM];
int main()
{
    scan(N);
    for(int i = 0; i < N; ++i){
        scan(a[i]); mids[(a[i]+i)>>1].pb(abs(a[i]-((a[i]+i)>>1)));
        psa[i] = psa[i-1]+(a[i]==i);
    }
    for(int i = 0; i <= N; ++i) sort(mids[i].begin(), mids[i].end());
    for(int mid = 1; mid < N-1; ++mid){
        for(int i = 0; i < mids[mid].size(); ++i){
            int l = mid - mids[mid][i], r = mid+mids[mid][i],  flps = i+1, val = flps+psa[N-1]-psa[r]+psa[l-1];
            if(val > res){
                res = val; lft = l, rgt = r;
            }
            cout<<lft<<" "<<rgt<<endl;
        }
    }
    cout<<a[lft]<<" "<<a[rgt]<<endl;
    return 0;
}
