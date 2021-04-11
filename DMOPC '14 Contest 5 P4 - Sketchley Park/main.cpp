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
const ll MM = 1e5+10, seed = 31;
using namespace std;
ll hsh1[MM], p[MM], hsh;
ll get1(int l, int r){return hsh1[r]-hsh1[l-1]*p[r-l+1];}
string s, ke = "HAILHYDRA", tmp;
void decrpt(){
    char rvmp[27];
    for(int i = 0; i < tmp.length(); ++i){
        rvmp[tmp[i]-'A'] =  'A'+i;
    }
    for(int j = 0; j < s.length(); ++j){
        s[j] = rvmp[s[j]-'A'];
    }
}
int main()
{
    map<ll, bool> contains;
    boost();
    cin>>s; p[0] = 1;
    for(int i = 1; i <= s.length(); ++i){
        hsh1[i]= hsh1[i-1]*seed+s[i-1];
        p[i] = p[i-1]*seed;
    }
    for(int i = 1; i <= s.length()-ke.length()+1; ++i){
        contains[get1(i, i+ke.length()-1)] = 1;
    }
    int N; cin>>N;
    for(int i = 0; i < N; ++i){
        cin>>tmp;
        hsh = 0;
        for(int j = 0; j < ke.length(); ++j){
            hsh*=seed;
            hsh+=tmp[ke[j]-'A'];
        }
        if(contains[hsh]){
            decrpt();
            cout<<s<<endl;
            return 0;
        }
    }
    cout<<"KeyNotFoundError"<<endl;
    return 0;
}
