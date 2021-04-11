#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp(a,b) make_pair(a,b);
#define mt make_tuple;
#define push_back pb;
char _;
typedef long long ll;
const int MAXN = 1000010;
using namespace std;
ll rank1[MAXN], parent [MAXN];

ll find_set(ll v){
    if(parent[v]==v){
        return v;
    }
    else{
        return parent[v] = find_set(parent[v]);
    }
}

void union_sets(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank1[a] < rank1[b])
            swap(a, b);
        parent[b] = a;
        if (rank1[a] == rank1[b])
            rank1[a]++;
    }
}



int main()
{
    queue<ll> res;
    ll N,M; scan(N); scan(M);
    queue<pair<ll, ll> >q;
    for(int i = 1; i <= M; ++i){
        parent[i]=i;
        rank1[i]=1;
    }
    ll edgecounter = 0;
    for(int i = 1; i <= M; ++i){
        ll a,b; scan(a); scan(b);
        q.push({a,b});
        if(find_set(a)!=find_set(b)){
            res.push(i);
            union_sets(a,b);
            ++edgecounter;
        }
    }
    if(edgecounter!=N-1){
        cout<<"Disconnected Graph"<<endl;
    }
    else{
        while(!res.empty()){
            cout<<res.front()<<endl;
            res.pop();
        }
    }
    return 0;
}
