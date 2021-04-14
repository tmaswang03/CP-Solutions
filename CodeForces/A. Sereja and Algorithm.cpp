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
const ll MM = 1e5+10;
using namespace std;
int psa[MM][3], Q, l, r; string s;
// program terminates if the entire string is a shift of zyx
// it is possible to attain any permutation of the string through a set of moves
// determine if it is possible to attain a permutation of the string that uses only shifts of zyx
// occurs when cnt of all 3 letters are equal
// cnt of 2 letters greater than other by 1
// cnt of 1 letter is greater than others by 1
// zyx, zyxz, zyxzy,
// query by using psa holding counts of z,x,y
bool ye(int l, int r){
    int x = psa[r][0]-psa[l-1][0], y = psa[r][1]-psa[l-1][1], z = psa[r][2]-psa[l-1][2];
    if(x > y) swap(x, y);
    if(y > z) swap(y, z);
    if(x > y) swap(x, y); // sort ascending
    if(r-l+1<3) return 1;
    if(x==y && y==z) return 1;
    if(y==z && x==y-1) return 1;
    if(z==y+1 && y==x) return 1;
    return 0;
}
int main()
{
    cin>>s;
    for(int i = 1; i <= s.length(); ++i){
        int cur = s[i-1]-'x';
        ++psa[i][cur];
        for(int j = 0; j < 3; ++j) psa[i][j]+=psa[i-1][j];
    }
    cin>>Q;
    while(Q--){
        cin>>l>>r;
        if(ye(l, r)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
