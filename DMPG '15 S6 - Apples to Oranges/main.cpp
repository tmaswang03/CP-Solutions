#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a, b, sizeof(a));
#define mp make_pair
#define pb push_back
#define s second
#define f first
char _;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll MAXN = 4e3+10;
const ll MOD = 1e9+7;
using namespace std;
map<string, int>mep; // convert string to int;
vector<pair<int, double> > v[MAXN], component[MAXN];
int lownode1[MAXN], starttime[MAXN], time1 = 0, N, M;
double lownode[MAXN], ret;
bool visited[MAXN], in[MAXN];
stack<int>s;

void dfs(ll node, double res){
    ret = res;
    visited[node] = 1;
    ++time1;
    lownode1[node] = time1;
    starttime[node] = time1;
    s.push(node); in[node] = 1;
    for(auto && i : v[node]){
        if(!visited[i.f]){
            dfs(i.f, res*i.s);
            lownode1[node] = min(lownode1[node], lownode1[i.f]);
        }
        else if (in[i.f]) lownode1[node] = min(lownode1[node], starttime[i.f]);
    }
    if (lownode1[node] == starttime[node]){
        double  t = ret;
        while (s.top() != node){
            ll i = s.top();
            s.pop();
            in[i] = 0;
            lownode[i] = max(lownode[i], t);
        }
        s.pop();
        lownode[node] = max(lownode[node], t); in[node] = 0;
    }
}

int main()
{
    boost();
    cin>>N>>M;
    for(int i = 0; i < N; ++i){
        string s; cin>>s;
        mep[s] = i;
    }
    for(int i = 0; i < M; ++i){
        string s, e; cin>>s>>e;
        double cst; cin>>cst;
        v[mep[s]].pb({mep[e], cst});
    }
    dfs(mep["APPLES"], 1.0);
    cout<<lownode[mep["APPLES"] ]<<endl;
    if(lownode[mep["APPLES"]]>1.0){
        cout<<"YA"<<endl;
    }
    else{
        cout<<"NAW"<<endl;
    }
    return 0;
    /*
    3 4
    APPLES ORANGE GRAPE
    ORANGE APPLES 2.0
    APPLES ORANGE 0.5
    APPLES GRAPE 1.0
    GRAPE ORANGE 1.0
*/
}
