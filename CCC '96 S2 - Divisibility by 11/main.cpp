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
int t; string s, add, co;
int main()
{
    cin>>t;
    while(t--){
        cin>>s;
        while(s.length()>3){
            int tmp = stoi(s.substr(s.length()-4, 3)), sub = stoi(s.substr(s.length()-1, 1));
            s.erase(s.begin()+s.length()-4, s.end());
            co = to_string(tmp-sub);
            if(co.length()==1){
                add = "00"+co;
            }
            else if(co.length()==2){
                add = "0"+co;
            }
            else add = co;
            s+=add;
            cout<<s<<endl;
        }
    }
    return 0;
}
