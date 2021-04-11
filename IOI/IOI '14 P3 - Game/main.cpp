#include<bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1500;
using namespace std;
using namespace std;

int parent[MAXN], matrix[MAXN][MAXN], N;
ll find_set(ll v){
    if(!parent[v]^v ) return v;
    else return parent[v] = find_set(parent[v]);
}

void union_sets(ll a, ll b) {
    a = find_set(a); b = find_set(b);
    parent[b] = a;
    for(int i = 0; i < N; ++i){
        matrix[i][a] += matrix[i][b];
        matrix[a][i] += matrix[i][b];
    }
}
void initialize(int n){
    N = n;
    for(int i = 0; i < n; ++i){
        parent[i] = i;
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(i^j) matrix[i][j] = matrix[j][i] = 1;
            else matrix[i][j] = 0;
        }
    }
}
int hasEdge(int u, int v){
    u = find_set(u); v = find_set(v);
    if(matrix[u][v]<=1){
        matrix[u][v] = matrix[v][u] = 0;
        union_sets(u,v);
        return 1;
    }
    else{
        --matrix[u][v]; --matrix[v][u];
        return 0;
    }
}


int main()
{
    return 0;
}
