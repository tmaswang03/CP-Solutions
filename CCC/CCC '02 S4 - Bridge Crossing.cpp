#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define boost() cin.tie(0); cin.sync_with_stdio(0); cout.tie(0);
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 101;
using namespace std;
int dp[MM], pos[MM]; //holds starting point of split
string strinq[MM];
int main()
{
    // dp[i] = min(dp[k]+max(arr[k]-arr[i]);
    ms(dp,0x3f);
    dp[0] = 0;
    int M, Q; cin>>M>>Q;
    pair<int, string> arr[Q+1];
    arr[0] = {0,""};
    for(int i = 1; i <= Q; ++i){
        string s; cin>>s;
        int a; cin>>a;
        arr[i] = {a,s};
        int max1 = arr[i].first, optpos;
        for(int k = 1; k<=min(i,M); ++k){
            if(dp[i-k]+max1<dp[i]){
                dp[i] = dp[i-k]+max1;
                optpos = i-k+1;
            }
            max1 = max(max1, arr[i-k].first);
        }
        pos[i] = optpos;
    }
    cout<<"Total Time: ";
    cout<<dp[Q]<<"\n";
    int i = Q, cur = 0;
    while(i >= 1){
        int optpos = pos[i];
        string tempstr = "";
        for(int k = max(1,optpos); k <= i; ++k){
            tempstr+=arr[k].second;
            tempstr+=" ";
        }
        tempstr+="\n";
        i=optpos-1;
        strinq[cur]=tempstr;
        ++cur;
    }
    for(int i = cur; i >= 0; --i){
        cout<<strinq[i];
    }
    return 0;
}
