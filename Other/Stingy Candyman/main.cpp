#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define REP(i, N) for(int i = 0; i < N; ++i)
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
const ll MM = 20;
using namespace std;
int N, a[MM], m[MM], b[MM], x[MM];
int get(int cur){
    string t = to_string(cur);
    int ma = 2;
    for(int i = 0; i < t.length(); ++i){
        ma = max(ma, t[i]-'0'+1);
    } return ma;
}
int conv(int cur, int base){
    int n = 1, res = 0;
    string t = to_string(cur); reverse(t.begin(), t.end());
    for(int i = 0; i < t.length(); ++i){
        res = res + (int)(t[i]-'0')*n; n*=base;
    }
    return res;
}
bool check(){
    for(int i = 0; i < N; ++i) x[i] = conv(a[i], b[i]);;
    for(int i = 0; i < N; ++i){
        for(int j = i+1; j < N; ++j){
            if(__gcd(x[i], x[j])!=1) return 0;
        }
    }
    return 1;
}
void dfs(int cur){
    if(cur==N){
        if(check()){
            for(int i = 0; i < N; ++i) printf("%d\n", b[i]);
            exit(0);
        }
        else return;
    }
    for(int i = 10; i >= m[cur]; --i){
        b[cur] = i; dfs(cur+1);
    }
}
int main()
{
    cin>>N;
    for(int i = 0; i < N; ++i) scan(a[i]);
    for(int i = 0; i < N; ++i) m[i] = get(a[i]);
    dfs(0);
    return 0;
}
