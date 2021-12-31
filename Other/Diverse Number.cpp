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
// each position you can either go up by nearest or stay same
ll N, K, cnt[15], m = LLONG_MAX; string str;
void dfs(int pos, ll cur, bool over) {
    if(pos == str.length()) {
        m = min(m, cur);
        return;
    }
    if(over) {
        for(int i = 0; i < 10; ++i) {
            if(cnt[i] < K) {
                ++cnt[i];
                dfs(pos+1, cur*10 + i, over);
                --cnt[i];
                break;
            }
        }
    }
    else {
        int num = str[pos] - '0';
        if(cnt[num] < K) {
            ++cnt[num]; dfs(pos+1, cur*10 + num, over); --cnt[num];
        }
        for(int i = num + 1; i < 10; ++i) {
            if(cnt[i] < K) {
                ++cnt[i]; dfs(pos+1, cur*10 + i, 1); --cnt[i];
                break;
            }
        }
    }

}
//101999 2
int main()
{
    cin>>str>>K;
    dfs(0, 0, 0);
    cnt[1] = 1; dfs(0, 1, 1); --cnt[1];
    if(m != LLONG_MAX){
        cout<<m<<endl;
    }
    else cout<<-1<<endl;
    return 0;
}