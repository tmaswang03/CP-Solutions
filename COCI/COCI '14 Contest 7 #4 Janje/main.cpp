#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define gc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;
typedef long long ll;
using namespace std;
ll fact(ll i){
    ll temp = 1;
    for(int k = 2; k <= i; ++k){
        temp*=k;
    }
    return temp;
}

ll choose (ll n, ll k){
    return (fact(n)/fact(k))/fact(n-k);
}
ll cases(ll n, ll k){
    // case 1 kc3*(6^10)
    if(n==1){
        return choose(k,3)*60466176;
    }
    // case 2 = kc3* 144
    else if (n==2){
        return choose(k,3)*96;
    }
    else if (n==3){
        return choose(k,3)*24;
    }
    else if (n==4){
        return choose(k,3)*24576;
    }
    else if (n==5){
        return choose(k,3)*12;
    }
    else if (n==6){
        return choose(k,3)*1536;
    }
    else if (n==7){
        return choose(k,3)*96;
    }
    else{
        return choose(k,3)*805306368;
    }


}

int main()
{
    ll n, m; gc(n); gc(m);
    printf("%lld\n",cases(n,m));
    return 0;
}
