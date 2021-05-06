#include<bits/stdc++.h>
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
const ll MM = 1e5+10;
using namespace std;
ll N, P;
struct stud{
    string S; ld a, b, c;
};
ll powe(ld a, ll b){
    if(a==0) return 0;
    ld res = 1;
    for(int i = 0; i < b; ++i){
        res*=a;
    }
    return res;
}
stud A[MM];
ld calc(stud i){
    return 4.0*(sqrt(i.a))+3.0*powe(i.b, P)-4.0*i.c;
}
bool cmp(stud x, stud y){
    return floor(calc(x))<=floor(calc(y));
}
int main()
{
    cin>>N>>P;
    for(int i = 0; i < N; ++i){
        cin>>A[i].S>>A[i].a>>A[i].b>>A[i].c;
    }
    sort(A, A+N, cmp);
    cout<<fixed<<setprecision(0)<<A[N-1].S<<" "<<floor(calc(A[N-1]))<<endl;
    cout<<fixed<<setprecision(0)<<A[0].S<<" "<<floor(calc(A[0]))<<endl;
    return 0;
}