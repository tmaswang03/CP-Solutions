#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define f first
#define s second
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;
ll sum1 = 0, sum2 =  0;
string s1, s2;
int main()
{
    cin>>s1>>s2;
    for(int i = 0; i < s1.length(); ++i) s1[i] = tolower(s1[i]);
    for(int i = 0; i < s2.length(); ++i) s2[i] = tolower(s2[i]);
    for(int i = 0; i < s1.length();  ++i){
        int p; p = i%4+1;
        sum1+=pow((s1[i]-'a'+1)%10, p);
        sum1%=10;
    }
    for(int i = 0; i < s2.length();  ++i){
        int p; p = i%4+1;
        sum2+=pow((s2[i]-'a'+1)%10, p);
        sum2%=10;
    }
    sum1%=10; sum2%=10;
    if(sum1==0) sum1 = 10;
    if(sum2 == 0) sum2 = 10;
    cout<<sum1+sum2<<endl;
    return 0;
}
