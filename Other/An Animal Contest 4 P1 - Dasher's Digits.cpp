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
const ll MM = 1e6+10;
using namespace std;
int N, M, a[MM], cnt, idx, os, start; string str;
int main()
{
    cin>>N>>M>>str;
    for(int i = 1; i <= M; ++i){
        cin>>a[i];
        if(a[i] >= cnt) {
            cnt = a[i]; idx = i;
        }
    }
    for(int i = 0; i < N; ++i) {
        if(str[i] == '0') {
            ++os;
            if(os == idx) {
                start = (i + 1) % N;
            }
        }
    }
    for(int i = start; i < start + N; ++i) {
        if(str[i % N] != '0') cout<<str[i % N];
    }
    cout<<endl;
    return 0;
}