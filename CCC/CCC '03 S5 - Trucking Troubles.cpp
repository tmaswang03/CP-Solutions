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
const ll MM = 1e4+10; 
using namespace std;
int minweight[MM], x, y, z, c, r, d, e, maxweight=0x3f3f3f; queue<int>q; 
int main() {
    cin>>c>>r>>d;
    vector<pair<int, int> >cityroads[c+1];
    for(int i = 0 ; i < r; i++){
        cin>>x>>y>>z;
        cityroads[x].push_back({y,z});
        cityroads[y].push_back({x,z});
    }
    minweight[1]=0x3f3f3f; q.push(1);
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(pair<int, int> i: cityroads[temp] ){
            if(minweight[temp]<i.s && minweight[temp] > minweight[i.f]){
                minweight[i.f]=minweight[temp];
                q.push(i.f);
            }
            else if (minweight[temp]>=i.s && i.s>minweight[i.f]){
                minweight[i.f]=i.s;
                q.push(i.f);
            }
        }
    }
    for(int i = 0 ; i < d; i++){
        cin>>x;
        if (minweight[x] < maxweight) maxweight=minweight[x];
    }
    cout<<maxweight<<endl;
}
