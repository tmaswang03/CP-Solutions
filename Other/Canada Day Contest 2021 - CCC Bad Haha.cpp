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
int b[MM], T, N, K; deque<int> st; string s;
int main()
{
    cin>>T;
    while(T--){
        cin>>s>>K; N = s.length(); int cnt = 0;
        for(int i = 0; i < N; ++i){
            int cur = s[i] - '0';
            while(!st.empty() && cnt < K && st.back() > cur){
                b[cnt++] = st.back(); st.pop_back();
            }
            st.push_back(cur);
        }
        while(!st.empty() && cnt < K){
            b[cnt++] = st.back(); st.pop_back();
        }
        sort(b, b+cnt);
        while(!st.empty()){ cout<<st.front(); st.pop_front(); }
        for(int i = 0; i < cnt; ++i) cout<<b[i];
        cout<<endl;
    }
    return 0;
}