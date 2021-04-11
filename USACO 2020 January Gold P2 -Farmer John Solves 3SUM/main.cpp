#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll maxn = 5e3+1;
const ll maxv = 1e6+2;
using namespace std;
int N, Q, arr[maxn], freq[2*maxv]; ll psa[maxn][maxn];
int main()
{
    cin>>N>>Q; ms(psa, 0); ms(freq, 0);
    for(int i = 1; i <= N; ++i){
        cin>>arr[i];
    }
    for(int l = 1; l <= N; ++l){
        for(int r = l+1; r <= N; ++r){
            int temp1 = arr[l], temp2 = arr[r];
            int val = -temp1-temp2+maxv;
            if(val>=0 && val < 2*maxv) psa[l][r] = freq[val];
            freq[temp2+maxv]++;
        }
        for(int k = l+1; k <= N; ++k) freq[arr[k]+maxv]--;
    }

    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            psa[i][j]+=psa[i-1][j]+psa[i][j-1]-psa[i-1][j-1];
        }
    }
    for(int i = 1; i <= Q; ++i){
        int l,r; cin>>l>>r;
        cout<<psa[r][r]-psa[l-1][r] - psa[r][l-1] + psa[l-1][l-1]<<endl;
    }
    return 0;
}
