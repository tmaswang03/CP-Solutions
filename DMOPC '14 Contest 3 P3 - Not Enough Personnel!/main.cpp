#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll maxn = 500;
using namespace std;
char _;
int main()
{
    vector<tuple<int, int, string> >v;
    int N, K; scan(N);
    for(int i = 0; i < N; ++i){
        string s; int rat;
        cin>>s>>rat;
        v.pb({rat, i, s});
    }
    sort(v.begin(), v.end());
    scan(K);
    for(int i = 0; i < K; ++i){
        int r,d; scan(r); scan(d);
        int temp1 = lower_bound(v.begin(), v.end(), make_tuple(r, 0, "")) - v.begin();
        if(get<0>(v[temp1])<= r+d && get<0>(v[temp1])>=r){
            cout<<get<2>(v[temp1])<<endl;
        }
        else{
            cout<<"No suitable teacher!"<<endl;
        }
    }

    return 0;
}
