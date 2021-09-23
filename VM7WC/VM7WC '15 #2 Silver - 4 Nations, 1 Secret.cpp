#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define boost() cin.tie(0); cin.sync_with_stdio(0);
#define f first
#define s second
#define ms(a,b) memset(a,b,sizeof(a));
#define mp make_pair
#define pb push_back
char _;
typedef  unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll MM = 25010, seed = 31;
using namespace std;
int N, L, lft, rt; string s;
ll hsh1[MM], rhsh[MM], p[MM];
ll get1(int l, int r){return hsh1[r]-hsh1[l-1]*p[r-l+1];}
ll get2(int l, int r){return rhsh[l] - rhsh[r+1]*p[r-l+1];}
int main()
{
    //dfds
    boost();
    cin>>N>>s; p[0] = 1; ms(hsh1, 0); ms(rhsh, 0);
    string res; L = 0;
    for(int i = 1; i  <= s.length(); ++i){
        hsh1[i] = hsh1[i-1]*seed+s[i-1]-'A'+1;
        p[i] = p[i-1]*seed;
    }
    for(int i = s.length(); i >= 1; --i){
        rhsh[i] = rhsh[i+1]*seed + s[i-1]-'A'+1;
    }
    for(int mid = 1; mid <= s.length(); ++mid){
        int r = mid+1, l = mid-1;
        while(r <= s.length() && l > 0 && get1(l,r)==get2(l,r)){
            if(r-l+1 > L){
                L = r-l+1; lft = l, rt = r;
            }
            ++r, --l;
        }
        l = mid, r = mid+1;
        while(r <= s.length() && l > 0 && get1(l,r)==get2(l,r)){
            if(r-l+1 > L){
                L = r-l+1; lft = l, rt = r;
            }
            ++r, --l;
        }
    }
    cout<<s.substr(lft-1, rt-lft+1)<<"\n"<<L<<endl;
    return 0;
}