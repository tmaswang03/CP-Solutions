#include<bits/stdc++.h>
#define REP(i, N) for(int i = 0; i < N; ++i)
const int MM = 2e5+10;
using namespace std;
struct il{
    int l, r, idx;
};
int N, tmp; il a[MM]; bool in[MM], out[MM];
bool cmp(il x, il y){
    if(x.l==y.l) return x.r>y.r;
    return x.l<y.l;
}
int main()
{
    cin>>N;
    for(int i = 0; i < N; ++i){ cin>>a[i].l>>a[i].r; a[i].idx = i;}
    sort(a, a+N, cmp);
    REP(i, N){
        if(tmp>=a[i].r) in[a[i].idx] = 1;
        tmp = max(tmp, a[i].r);
    } tmp = 1e9;
    for(int i = N-1; i >= 0; --i){
        if(tmp<=a[i].r) out[a[i].idx] = 1;
        tmp = min(tmp, a[i].r);
    }
    REP(i, N) cout<<out[i]<<" ";
    cout<<endl;
    REP(i, N) cout<<in[i]<<" ";
}
