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
const ll MM = 3e5+10;
using namespace std;
int a[MM], N, t;
// can only remove if a[i]<a[i+1]
// 2 4 1 6 3 5
// 2 1 6 3 5
// 2 1 6 5
//
// a number can remove all to the right such that everything is greater
// or all to the left such that everything to the left is smaller than idx
// if a[i] can remove a[i+1] then a[i]< a[i+1]
// use the first idx and remove all to the right that is greater until there is a to the right
// then remove all to the left that is smaller than last
// until you reach one that is smaller than the right
// new idea: continuously find the largest element in the right possible and delete everything in between until you come to first index
// then delete the element,
// and then continuously find an element to the left of a[N] such that it's less than a[N]
// delete everything in between
// you are left with a[1]+some segment + a[N]
// everything in segment is either < a[1] or > a[N]
// if greater than a[N] you can delete with a[1]
// if less than a[1] you can delete with a[N]
// left is a[N] and a[1]
int main()
{
    cin>>t;
    while(t--){
        cin>>N;
        for(int i = 0; i < N; ++i) cin>>a[i];
        if(a[0]<a[N-1]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
