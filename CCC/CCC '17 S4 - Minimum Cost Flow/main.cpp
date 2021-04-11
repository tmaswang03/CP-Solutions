#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair;
#define f first;
#define s second;
#define pb(i) push_back(i);
using namespace std;
char _;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
const int MAXN = 100001;
using namespace std;
vi v[MAXN];
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
    ll N, M , D; scan(N); scan(M); scan(D);
    tuple<ll, ll, ll, ll> arr[M+1];
    bool used[M+1];
    ms(used,0);
    priority_queue<tuple<ll,ll, ll, ll>, vector<tuple<ll, ll, ll, ll> >,greater<tuple<ll, ll, ll, ll> > >pq; //weight, distance;
    priority_queue<tuple<ll,ll, ll, ll>, vector<tuple<ll, ll, ll, ll> >,greater<tuple<ll, ll, ll, ll> > >pq2; //weight, distance;
    for(int i = 0; i <= N; ++i){
        rank1[i]=1;
        parent[i]=i;
    }
    for(int i = 0; i < M; ++i){
        ll a,b,c; scan(a); scan(b); scan(c);
        if(i<N-1){
            pq.push(make_tuple(c,0,a,b));
            pq2.push(make_tuple(c,0,a,b));
        }
        else{
            pq.push(make_tuple(c,1,a,b));
            pq2.push(make_tuple(c,1,a,b));
        }
    }
    sort(arr,arr+N);
    ll counter = 0;
    ll days = 0;
    ll mw = 0;
    while(!pq.empty()){
        tuple<ll, ll, ll, ll> temp = pq.top();
        pq.pop();
        if(find_set(get<2>(temp))!=find_set(get<3>(temp))){
            mw = max(mw, get<0>(temp));
            union_sets(get<2>(temp),get<3>(temp));
            used[counter]=1;
            if(get<1>(temp)){
                ++days;
            }
        }
        ++counter;
    }
    //arr[i]=make_tuple(c,1,a,b); // 1 = new, 0 = original
    for(int i = 0; i <= N; ++i){
        rank1[i]=1;
        parent[i]=i;
    }
    if(D!=0){
        while(!pq2.empty()){
            tuple<ll,ll,ll,ll>temp = pq2.top();
            pq2.pop();
            if(find_set(get<2>(temp))!=find_set(get<3>(temp))){
                if(get<0>(temp)<mw || (get<0>(temp)==mw && !get<1>(temp))){
                    union_sets(get<2>(temp),get<3>(temp));
                }
                else if (!get<1>(temp) && get<0>(temp)<=D){
                    --days;
                    cout<<days<<endl;
                    exit(0);
                }
            }
        }
    }
    cout<<days<<endl;
    return 0;
}
