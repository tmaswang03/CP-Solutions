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
typedef unsigned long long ull;
const ll MAXN = 1e5+1;
using namespace std;
vector<pair<int, int> >v[MAXN];
ll diam1 = -1, diam2 = 0, ind1 = 1, tempind, ind2 = 1, maxl = 0,par1[MAXN], par2[MAXN];
ll maxlength[MAXN];
void dfsmax1(ll node, ll length = 0){
    if(length > diam1){
        diam1 = length;
        ind1 = node;
    }
    for(auto && i : v[node]){
        if(i.f!=par1[node]){
            par1[i.f] = node;
            dfsmax1(i.f, length+i.s);
        }
    }
}
void reset(){
    int indt = ind1;
    while(ind1!=tempind){
        for(int i = 0; i < v[ind1].size(); ++i){
            if(v[ind1][i].f == par1[ind1]){
                v[ind1][i].s = -1;
                ind1 = par1[ind1];
                break;
            }
        }
    }
    ms(par1, -1);
    dfsmax1(indt);
    while(ind1!=indt){
        for(int i = 0; i < v[ind1].size(); ++i){
            if(v[ind1][i].f == par1[ind1]){
                v[ind1][i].s = -1;
                ind1 = par1[ind1];
                break;
            }
        }
    }
}

void dfsmax2(int node){
    ll tempmax  = 0;
    for(auto && i : v[node]){
        if(i.f!=par2[node]){
            par2[i.f] = node;
            dfsmax2 (i.f);
            ll tempd = maxlength[i.f] + i.s;
            maxlength[node] =  max(maxlength[node], tempd);
            tempd = max(maxlength[node], tempd+tempmax);
            diam2 = max(diam2, tempd);
            tempmax = max(tempmax, maxlength[node]);
        }
    }
}

int main()
{
    int N, K, res; scan(N); scan(K); res = 2*N-2;
    for(int i = 0; i < N-1; ++i){
        int a,b; scan(a); scan(b); v[a].pb({b,1}); v[b].pb({a,1});
    }
    par1[ind1] = -1; dfsmax1(ind1); tempind = ind1;
    ms(par1, -1); diam1 = 0; dfsmax1(ind1);
    if(K==1){
        cout<<res - diam1 + 1<<endl;
    }
    else{
        ms(maxlength, 0); ms(par2, -1);
        reset();
        dfsmax2(1);
        cout<<res-diam1-diam2+2<<endl;
    }
    // idea: create the 2 biggest cycles possible
    // make sure the cycles aren't within each other or small amount in each other
    // first connection is the diameter of the tree,

    return 0;
}
