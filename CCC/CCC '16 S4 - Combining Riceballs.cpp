#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define gc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;
typedef long long ll;
using namespace std;
int dp[401][401];
int cb[401][401];
ll pfsum[401], balls[401];

ll pfsum1(int l, int r){
    return pfsum[r]-pfsum[l-1];
}

bool combine(int l, int r){
    if(cb[l][r]==-1){
        cb[l][r]=0;
        if(r<l){
            cb[l][r]=0;
        }
        else if(r==l){
            cb[l][r]=1;
        }
        else{
            if(r-l<=2){
                if(dp[l][l]==dp[r][r]){
                    cb[l][r]=1;
                }
                else if(r-l==2){
                    if((combine(l+1,r) && pfsum1(l+1,r)==dp[l][l])||(combine(l,l+1) && pfsum1(l,l+1)==dp[r][r])){
                        cb[l][r]=1;
                    }
                }
            }
            else{
                for(int l1 = l; l1 <= r; ++l1){
                    int r1=r;
                    while(pfsum1(l,l1)>pfsum1(r1,r)){
                        --r1;
                          }
                    if(r1<l1)break;
                    --r1;
                    if(pfsum1(l,l1)==pfsum1(r1+1,r)){
                        if(r1==l1){
                            if(combine(l,l1) && combine(l1+1,r)){
                                cb[l][r]=1;
                            }
                        }
                        else{
                            if(combine(l,l1) && combine(l1+1,r1) && combine(r1+1,r)){
                                cb[l][r]=1;
                            }
                        }
                    }
                }
            }
        }
    }
//    printf("%i %i %i\n",cb[l][r],l,r);
    return cb[l][r];
}

int main()
{
    ms(cb,-1);
    int t; gc(t);
    pfsum[0]=0;
    for(int i = 1; i <= t; ++i){
        int a; gc(a);
        pfsum[i]=pfsum[i-1]+a;
        dp[i][i]=a;
        cb[i][i]=1;
    }

    ll max1 = 0;
    for(int gap = 0; gap < t; ++gap){
        for(int l = 1; l + gap <= t; ++l){
            if(combine(l,l+gap)){
                max1=max(max1,pfsum1(l,l+gap));
            }
        }
    }

    printf("%lld\n",max1);
    return 0;
}
