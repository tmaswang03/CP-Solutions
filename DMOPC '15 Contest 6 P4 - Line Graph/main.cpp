#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp(a,b) make_pair(a,b);
#define mt make_tuple;
#define push_back pb;
char _;
typedef long long ll;
const int MAXN = 10001;
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
    int N, K; scan(N); scan(K);
    priority_queue<tuple<int,int, int>, vector<tuple<int, int, int > >,greater<tuple<int, int, int > > >pq; //weight, distance;
    for(int i =1; i <= N-1; ++i){
        rank1[i]=1;
        parent[i]=i;
    }
    for(int i = 1; i <= N-1; ++i){
        int a; scan(a);
        pq.push({a,i,i+1});
    }
    for(int i = 1; i <= N-K; ++i){
        pq.push({0,i,i+K});
    }
    ll weightcounter = 0;
    while(!pq.empty()){
        int temp1= get<0>(pq.top()), temp2 = get<1>(pq.top()), temp3 = get<2>(pq.top());
        pq.pop();
        if(find_set(temp2)!=find_set(temp3)){
            weightcounter+=temp1;
            union_sets(temp2,temp3);
        }
    }
    cout<<weightcounter<<endl;
    return 0;
}
