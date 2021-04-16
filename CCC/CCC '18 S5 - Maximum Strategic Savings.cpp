#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp(a,b) make_pair(a,b);
#define mt make_tuple;
#define push_back pb;
char _;
typedef long long ll;
const int MAXN = 100001;
using namespace std;
ll rank1[MAXN], parent [MAXN];
ll rank2[MAXN], parent2 [MAXN];

ll find_set(ll v){
    if(parent[v]==v){
        return v;
    }
    else{
        return parent[v] = find_set(parent[v]);
    }
}


bool same(ll a, ll b){
    return (bool)(find_set(a)==find_set(b));
}

void union_sets(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank1[a] < rank1[b])
            swap(a, b);
        parent[b] = a;
        rank1[a]+=rank1[b];
    }
}

ll find_set2(ll v){
    if(parent2[v]==v){
        return v;
    }
    else{
        return parent2[v] = find_set2(parent2[v]);
    }
}

bool same2(ll a, ll b){
    return (bool)(find_set2(a)==find_set2(b));
}
void union_sets2(ll a, ll b) {
    a = find_set2(a);
    b = find_set2(b);
    if (a != b) {
        if (rank2[a] < rank2[b])
            swap(a, b);
        parent2[b] = a;
        rank2[a]+=rank2[b];
    }
}

int main()
{
    priority_queue<tuple<ll,ll, ll, ll>, vector<tuple<ll, ll, ll, ll > >,greater<tuple<ll, ll, ll, ll > > >pq; //weight, distance;
    ll N,M,P,Q; scan(N); scan(M); scan(P); scan(Q); // Planets, Cities, Flights, Portals
    // initializing
    for(int i = 0; i <= M; ++i){
        parent[i]=i;
        rank1[i]=1;
    }
    for(int i = 0; i <= N; ++i){
        parent2[i]=i;
        rank2[i]=1;
    }
    //input
    ll totweight = 0;
    for(int i = 0; i < P; ++i){
        ll a,b,c; scan(a); scan(b); scan(c);
        pq.push(make_tuple(c,0,a,b));
        totweight+=c*N;
    }
    for(int i = 0; i < Q; ++i){
        ll x,y,z; scan(x); scan(y); scan(z);
        pq.push(make_tuple(z,1,x,y));
        totweight+=z*M;
    }
    // 0 = city, 1 = Planet
    // M = cities;
    // N = Planets
    // weight,portal or flight, planet/city, dest, .

    ll citiesmerge=M, planetmerge=N;
    while(!pq.empty()){
        ll temp1 = get<0>(pq.top()),temp2 = get<1>(pq.top()),temp3 = get<2>(pq.top()),temp4 = get<3>(pq.top());
        pq.pop(); // weight, flight/portal, start, dest,
        if(temp2==0){//flight
            if(!same(temp3,temp4)){
                union_sets(temp3,temp4);
                totweight-=temp1*(planetmerge);
                --citiesmerge;
            }
        }
        else{//portal
            if(!same2(temp3,temp4)){
                union_sets2(temp3,temp4);
                totweight-=temp1*(citiesmerge);
                --planetmerge;

            }
        }
    }
//    for(int i = 0; i <= M; ++i){
//        cout<<parent[i]<<",";
//    }
//    cout<<citiesmerge<<" "<<planetmerge<<endl;
    cout<<totweight<<endl;
    return 0;
}
