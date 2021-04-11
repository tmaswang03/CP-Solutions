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
using namespace std;

int main()
{
    map<int, int> mep;
    int N, first; scan(N); scan(first);
    mep[first] = 0;
    for(int i = 2; i <= N; ++i){
        int rk; scan(rk);
        auto p1 = mep.lower_bound(rk);
        if(p1==mep.begin()){
            cout<<"NO"<<endl;
            return 0;
        }
        else{
            mep[rk] = 0;
            --p1; p1->second++;
            if(p1->second==2){
                mep.erase(p1);
            }
        }
    }
    cout<<"YES"<<endl;
    return 0;
}
