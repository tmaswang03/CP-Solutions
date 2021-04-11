#include<bits/stdc++.h>
#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a, b, sizeof(a));
#define mp make_pair
#define pb push_back
#define s second
#define f first
char _;
typedef long long ll;
typedef long double ld;
typedef double dbl;
typedef unsigned long long ull;
using namespace std;
string dp[4][51]; //split number, optimal split pos

int main()
{
    string s, minstr = "zzzzzzzzzzzzzzzzzzzzzzzzzz"; cin>>s;
    for(int r = 1; r < s.length(); ++r){
        for(int l = 1; l < r; ++l){
            string temp1 = s.substr(0, l), temp2 = s.substr(l, r-l), temp3 = s.substr(r, s.length()-r);
            reverse(temp1.begin(), temp1.end()); reverse(temp2.begin(), temp2.end()); reverse(temp3.begin(), temp3.end());
            minstr = min(temp1+temp2+temp3, minstr);
        }
    }
    cout<<minstr<<endl;
    return 0;
}
