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
const ll MM = 1e2+10;
using namespace std;
ll a[MM], T, N, ma = 0;
int main()
{
    cin>>T;
    for(int t = 1; t <= T; ++t){
        cin>>N; int len = 0, cnt = 0; ma = 0;
        for(int i = 0; i < N; ++i) cin>>a[i];
        for(int i = 0; i < N; ++i){
            // if greater than keep as max
            // else :
            // first part is equal to max
            // ++ma
            // else if first part > append 2 0s
            //
            string tmp = to_string(a[i]);
            if(a[i]>ma){ ma = a[i]; len = max(len, (int)(tmp.length())); }
            else{
                if((ll)(ma/pow(10, len-tmp.length())<a[i])){
                    ma = a[i]*pow(10, len-tmp.length()); cnt += len-tmp.length();
                }
                else if((ll)(ma/pow(10, len-tmp.length()))>a[i]){
                    ma = a[i]*pow(10, len-tmp.length()+1); cnt+= len-tmp.length()+1; ++len;
                }
                else{
                    if((ll)((ma+1)/pow(10, len-tmp.length()))==a[i]){
                        cnt+=len-tmp.length(); ++ma;
                    }
                    else{
                        ma = a[i]*pow(10, len-tmp.length()+1);
                        cnt += len-tmp.length()+1; ++len;
                    }
                }
            }
        }
        cout<<"Case #"<<t<<": "<<cnt<<endl;
    }
    return 0;
}
