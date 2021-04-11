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
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;
pii p1, p2; int tme;
int main()
{

    cin>>p1.f>>p1.s>>p2.f>>p2.s;
    if(p1>p2) swap(p1, p2);
    if(abs(p2.s-p1.s) && abs(p2.f-p1.f) && abs(p2.s-p1.s)!= abs(p2.f-p1.f)){cout<<-1<<endl; return 0;}
    if(!abs(p1.s-p2.s) && abs(p1.f-p2.f)){
        // same y coord
        tme = abs(p1.f-p2.f);
        cout<<p1.f<<" "<<p1.s-tme<<" "<<p2.f<<" "<<p2.s-tme<<endl;
    }
    else if(abs(p1.s-p2.s) && !abs(p1.f-p2.f)){
        // same y coord
        tme = abs(p1.s-p2.s);
        cout<<p1.f+tme<<" "<<p1.s<<" "<<p2.f+tme<<" "<<p2.s<<endl;
    }
    else{
        cout<<p2.f<<" "<<p1.s<<" "<<p1.f<<" "<<p2.s<<endl;
    }
    return 0;
}
