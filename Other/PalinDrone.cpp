#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define gc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
char _;
using namespace std;

unsigned long long stalindrome(int n){
    if(n==1){
        return 9;
    }
    unsigned long long total=0;
    total+=(unsigned long long) pow(10,(n-1)/2)*9%1000000000;
    total+=stalindrome(n-1)%1000000000;
    return total;
}

int main()
{
    string N; cin>>N;
    int temp;
    if(N.length()>=2){
        reverse(N.begin(),N.end());
        temp=10*(N[0]-('0'))+(N[1]-('0'));
    }
    else{
        temp=N[0]-('0');
    }
    if(temp>=19){
        temp=19;
    }
    if(temp==0){
        temp=19;
    }
    printf("%lli\n",stalindrome(temp));

    return 0;
}
