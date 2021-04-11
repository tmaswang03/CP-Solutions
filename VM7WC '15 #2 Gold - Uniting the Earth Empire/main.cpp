#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define s second
#define f first
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
    ll N, counter = 0; scan(N); stack<pair<ll, ll> >s; //index, height
    for(int i = 0; i < N; ++i){
        ll h, mebeingstupid = 1; scan(h);
        while(!s.empty() && s.top().f <= h){
            counter+=s.top().s;
            if(s.top().f==h) mebeingstupid+=s.top().s;
            s.pop();
        }
        if(!s.empty()) ++counter;
        s.push({h,mebeingstupid});
    }
    cout<<counter<<endl;
    return 0;
}
