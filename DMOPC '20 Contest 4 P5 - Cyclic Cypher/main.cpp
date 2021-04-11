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
using namespace std;
int a[1<<12], N, K;
bool check(){
    int sum = 0, cur = 1;
    for(int i = 0; i < K; ++i) cur*=a[i];
    sum+=cur;
    for(int i = 1; i < N; ++i){
        cur*=a[(i+K-1)%N]; cur/=a[i-1]; sum+=cur;
    }
    return (sum==0);
}
void dfs(int pos){
    if(pos==N){
        if(check()){
            for(int i = 0; i < N-1; ++i) cout<<a[i]<<" ";
            cout<<a[N-1]<<endl;
            exit(0);
        }
        return;
    }
    a[pos] = -1; dfs(pos+1); a[pos] = 1; dfs(pos+1);
}
int main()
{
    // idea : alternate positive negative???? only kind of depends on what you want the first segment to be
    // number of cycles = N
    // not possible if N is odd?? otherwise ig you could just always alternate from positive to negative or something
    // probs wrong tho
    // sum of first N-k+1 is -1 or +1 ?
    //
    cin>>N>>K;
    if(N%2==1){ cout<<0<<endl; return 0; }
    for(int i = 0; i < N-1; ++i){
        if(i%2==0) cout<<1<<" ";
        else cout<<-1<<" ";
    }
    if(N-1%2==0) cout<<1<<endl;
    else cout<<-1<<endl;
    return 0;
}
