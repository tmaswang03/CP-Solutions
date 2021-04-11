#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MAXN = 100+1;
using namespace std;
char _;
string names[MAXN];
pair<int , int> rank1[MAXN];

int main()
{
    ms(rank1, 0);
    int N, P; scan(N); scan(P);
    for(int i = 0; i < N; ++i){
        cin>>names[i];
    }
    for(int i = 0; i < N; ++i){
        rank1[i].second = i;
    }
    for(int i = 0; i < P; ++i){
        for(int j = 0; j < N; ++j){
            int a; cin>>a;
            rank1[j].first+=a;
        }
    }
    sort(rank1, rank1+N, greater<pair<int, int> >());

    for(int i = 0; i < N; ++i){
        cout<<i+3<<". "<<names[rank1[i].second]<<endl;
    }
    return 0;
}
