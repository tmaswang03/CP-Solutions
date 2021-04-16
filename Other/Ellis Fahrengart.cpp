#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1e5+50;
using namespace std;
int N, BIT[MAXN], K = 350, Q, L1 = 1, R1 = 0, arr2[MAXN], temp1, temp2, temp3;
ll res[MAXN], ans = 0;
//MOs + BIT

struct rng{
    int l,r,rs;
};

bool myComparison(const rng &a,const rng &b)
{
  return mp(a.l/K, a.r) < mp(b.l/K, b.r);
}


int main()
{
    scan(N);
    pair<int,int> arr1[MAXN];
    rng que[MAXN];
    for(int i = 1; i <= N; ++i) {
        scan(arr1[i].first); arr1[i].second = i;
    }
    int counter = 1;
    sort(arr1+1,arr1+N+1);
    for(int i = 1; i <= N; ++i){
        arr2[arr1[i].second] = i;
    }
    scan(Q);
    for(int i = 0; i < Q; ++i){
        int l,r; scan(l); scan(r);
        que[i] = rng{l,r,i}; //right then left;
    }
    sort(que, que+Q, myComparison);
    for(int i = 0; i < Q; ++i){
      // if L1 < temp1 sub the amnt less
      // if l1 > temp1 add the amnt less
      // if r1 <temp2 add the aamount greater (range - amnt less)
      // if r1 > temp2 sub the amount greater (range - amnt less)
        temp1 = que[i].l, temp2 = que[i].r, temp3 = que[i].rs;
        while(L1 < temp1){
            int index = arr2[L1]-1;ll sum = 0;
            while(index > 0){
                sum+=BIT[index];
                index -= (index & -index);
            }
            index = arr2[L1];
            while(index <= N){
                --BIT[index];
                index += (index & -index);
            }
            ans -= sum;
            ++L1;
        }
        while(L1 > temp1){
            --L1;
            int index = arr2[L1]-1 ;ll sum = 0;
            while(index > 0){
                sum+=BIT[index];
                index -= (index & -index);
            }
            index = arr2[L1];
            while(index <= N){
                ++BIT[index];
                index += (index & -index);
            }
            ans += sum;
        }
        while(R1 < temp2){
            ++R1;
            int range = R1-L1;
            int index = arr2[R1];ll sum = 0;
            while(index > 0){
                sum+=BIT[index];
                index -= (index & -index);
            }
            index = arr2[R1];
            while(index <= N){
                ++BIT[index];
                index += (index & -index);
            }
            ans += range - sum;
        }
        while(R1 > temp2){
            int range = R1-L1+1;
            int index = arr2[R1];ll sum = 0;
            while(index > 0){
                sum+=BIT[index];
                index -= (index & -index);
            }
            index = arr2[R1];
            while(index <= N){
                --BIT[index];
                index += (index & -index);
            }
            ans -= range - sum;
            --R1;
        }
        res[temp3] = ans;
    }
    for(int i = 0; i < Q; ++i){
        printf("%lld\n", res[i]);
    }
    return 0;
}
