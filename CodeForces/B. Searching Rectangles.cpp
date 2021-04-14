#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define REP(i, N) for(int i = 0; i < N; ++i)
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
int N, ret;
void query(int lox, int loy, int hix, int hiy){
    cout<<"?"<<" "<<lox<<" "<<loy<<" "<<hix<<" "<<hiy<<endl; cin>>ret;
}
// ideas :
// if there was 1 rectangle just binary search for the top and bottom
// binary search the hix, hiy, then lox, loy
//if there are 2 rectangles split grid into the 2 rectangles parts
//

void bsearch(int lx, int ly, int hx, int hy){
    int lox = lx, loy = ly, hix = hx, hiy = hy, res;
    while(lox < hix){
        int mid = lox+hix>>1;
        query(lx, ly, mid, hy);
        if(ret){ hix = mid; res  = mid;}
        else lox=mid+1;
    }
}
void get1(int lox, int loy, int hix, int hiy){
    int lx = lox, ly = loy, hx = hix, hiy = hy;
    while(lx<hx){

    }
}

int main()
{
    cin>>N;
    bsearch();
    return 0;
}
