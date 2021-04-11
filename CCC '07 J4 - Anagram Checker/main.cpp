#include<bits/stdc++.h>
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
string a,b;
int freq1[27], freq2[27];
int main()
{
    getline(cin, a); getline(cin, b);
    for(char c: a){
        if(c!=' ') ++freq1[c-'A'];
    }
    for(char c: b){
        if(c!=' ') ++freq2[c-'A'];
    }
    for(int i = 0; i < 26; ++i){
        if(freq1[i]!=freq2[i]){ cout<<"Is not an anagram."<<endl; return 0;}
    }
    cout<<"Is an anagram."<<endl;
    return 0;
}
