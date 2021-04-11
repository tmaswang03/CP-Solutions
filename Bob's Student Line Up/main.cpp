#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp(a,b) make_pair(a,b);
#define mt make_tuple;
#define push_back pb;
char _;
typedef long long ll;
const int MAXN = 100001;

using namespace std;

int main()
{
    ll N; cin>>N;
    string s; cin>>s;
    ll minstudents = 0x3f3f3f;
    ll leftcounter = 0, rightcounter = 0;
    for(int i = 0; i < s.length(); ++i){
        if(s[i]=='L'){
            ++leftcounter;
        }
        else{
            ++rightcounter;
        }
    }
    ll leftemp = 0, rightemp = 0;
    for(int i = 0; i < s.length(); ++i){
        if(s[i]=='L'){
            --leftcounter;
        }
        else{
            --rightcounter;
        }
        minstudents=min(minstudents,leftemp+rightcounter);
        if(s[i]=='L'){
            ++leftemp;
        }
        else{
            ++rightemp;
        }
    }

    cout<<minstudents<<endl;
    return 0;
}
