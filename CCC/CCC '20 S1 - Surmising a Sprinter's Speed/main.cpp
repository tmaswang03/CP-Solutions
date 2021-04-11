#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp(a,b) make_pair(a,b);
char _;
typedef long long ll;
const int MAXN = 100000;
using namespace std;

bool myComparison(const pair<int,int> &a,const pair<int,int> &b)
{
       return (double)a.second/(double)a.first>(double)b.second/(double)b.first;
}


int main()
{
    int a; scan(a);
    pair<int, int>arr[MAXN];
    for(int i = 0; i < a; ++i){
        int x,y; cin>>x>>y;
        arr[i]={x,y};
    }
    long double res = 0;
    sort(arr, arr+a);
    for(int i = 0; i < a-1; ++i){
        res = max(res, abs((long double)(arr[i+1].second-arr[i].second)/ (long double) (arr[i+1].first - arr[i].first)) );
    }
    cout<<setprecision(18)<<res<<endl;
    return 0;
}
