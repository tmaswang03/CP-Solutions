#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
char _;
typedef  unsigned long long ull;
typedef long long ll;
const ll MAXN = 1e5+1;
const ll INF = 0x3f3f3f3f;
#define pb push_back
using namespace std;

int main()
{
    //BITMASKSKDSKSKDJFGKSDJGKSDJGKSDJGKJ
    int G; scan(G);
    for(int i = 0; i < G; ++i){
        int a, taunt, totaldmg = 0, hp; scan(a);
        int arr[a];
        for(int j = 0; j < a; ++j){
            scan(arr[j]); totaldmg+=arr[j];
        }
        scan(taunt); scan(hp);
        //bitmask 0.o
        bool lethal = 0;
        for(int mask = 0; mask < (1<<a); ++mask){
            int dmgtotaunt = 0;
            for(int k = 0; k < a; ++k){
                if(mask & (1<<k)){
                    dmgtotaunt+=arr[k];
                }
            }
            if(dmgtotaunt>=taunt && totaldmg-dmgtotaunt>=hp){lethal = 1; break;}
        }
        if(lethal) cout<<"LETHAL"<<endl;
        else cout<<"NOT LETHAL"<<endl;

    }
    return 0;
}
