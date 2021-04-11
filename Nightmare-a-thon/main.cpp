#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define f first
#define s second
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 5e5+10;
using namespace std;
int N, Q, a[MM], pmx[MM], smx[MM], cntpr[MM], cntsf[MM];
int main()
{
    scan(N); scan(Q);
    for(int i = 1; i <= N; ++i){
        scan(a[i]);
        cntpr[i] = cntpr[i-1];
        pmx[i] = max(pmx[i-1], a[i]);
        if(a[i] == pmx[i-1]) cntpr[i] = cntpr[i-1]+1;
        else if (pmx[i]>pmx[i-1]) cntpr[i] = 1;
    }
    for(int i = N; i >=1 ; --i){
            smx[i] = max(a[i], smx[i+1]);
            cntsf[i] = cntsf[i+1];
            if(a[i]==smx[i+1]) cntsf[i] = cntsf[i+1]+1;
            else if(smx[i]>smx[i+1]) cntsf[i] = 1;
    }
    while(Q--){
        int a,b; scan(a); scan(b);
        int res = smx[b+1], cnt = cntsf[b+1];
        if(pmx[a-1]>smx[b+1]){
            cnt = cntpr[a-1];
            res = pmx[a-1];
        }
        else if(pmx[a-1]==smx[b+1]){
            cnt += cntpr[a-1];
        }
        printf("%d %d\n", res, cnt);
    }
    return 0;
}
