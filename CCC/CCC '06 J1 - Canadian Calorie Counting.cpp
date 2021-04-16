#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define s second
#define f first
char _;
void scana(){}template<class T, class...A> void scana(T&t, A&...a) { scan(t); scana(a...); }
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
    int a,b,c,d;
    int burgers[4]{461,431,420,0};
    int drinks[4]{130,160,118,0};
    int sideorders[4]{100,57,70,0};
    int dessert[4]{167,266,75,0};
    cin>>a>>b>>c>>d;
    cout<<"Your total Calorie count is "<<burgers[a-1]+sideorders[b-1]+drinks[c-1]+dessert[d-1]<<"."<<endl;
    return 0;
}
