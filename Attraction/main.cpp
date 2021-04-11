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
const ll MM = 2e5+10;
using namespace std;
int T, N, a[MM], A, B; priority_queue<pii> pq;
int main()
{
    cin>>T;
    while(T--){
        cin>>N>>A>>B; int cnt = B, res = 0;
        for(int i = 0; i < A; ++i) cin>>a[i];
        // if there is a long gap you can just place 2 at the edges of the gap
        // else you can place at the center and get 11 + 2*((gap)/2)/2
        sort(a, a+A);
        for(int i = 0; i < A-1; ++i){
            pq.push({a[i+1]-a[i]-1, 0});
        }
        pq.push({a[0]-1, 1}); pq.push({N-a[A-1], 1});
        while(!pq.empty()){
            int c = pq.top().f, b = pq.top().s; pq.pop();
            if(cnt==0) continue;
            if(b==0){
                if(cnt>=2&&c>1){
                    cnt-=2;
                    if(c%2==1){ pq.push({1, 0}); res+=c-1; }
                    else res+=c;
                }
                else{
                    --cnt;
                    res+=1+2*((c/2)/2);
                }
            }
            else{
                --cnt; res+=c;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
