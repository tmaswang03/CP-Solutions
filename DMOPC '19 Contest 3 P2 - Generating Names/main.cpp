#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp(a,b) make_pair(a,b);
char _;
typedef long long ll;
using namespace std;

ll choose(int c, int r){
    ll res = 1;
    if(c==r){
        return res;
    }
    if(c-r>=r){
        for(int i = c-r+1; i <= c; ++i){
            res*=i;
        }
        for(int i = 2; i <= r; ++i){
            res/=i;
        }
    }
    else{
        for(int i = r+1; i <= c; ++i){
            res*=i;
        }
        for(int i = 2; i <= c-r; ++i){
            res/=i;
        }
    }
    return res;
}


int main()
{
    int n,k; scan(n); scan(k);
    string s; cin>>s;
    unordered_map <char, int>freq;
    for(int i = 0; i < n; ++i){
        if(s[i]!='*'){
            ++freq[s[i]];
        }
    }
    ll res = 0;
    if(k==1){
        for(int i = 0; i < 26; ++i){
            freq[(char)('a'+i)]+=1;
            ll temp1 = 1;
            int templen = n;
            for(auto && h : freq){
                temp1*= choose(templen,h.second);
                templen-=h.second;
            }
            res+=temp1;
            --freq[(char)('a'+i)];
        }
    }
    else if (k==2){
        for(int i = 25; i >=0; --i){
            for(int j = i; j < 26; ++j){
                ++freq[(char)('a'+i)];
                ++freq[(char)('a'+j)];
                ll temp1 = 1;
                int templen = n;
                for(auto && h : freq){
                    temp1*=choose(templen,h.second);
                    templen-=h.second;
                }
                res+=temp1;
                --freq[(char)('a'+i)];
                --freq[(char)('a'+j)];
            }
        }
    }
    else{
        res = 1;
        for(auto && k : freq){
            res*=choose(n,k.second);
            n-=k.second;
        }
    }// 3 0 b b c
    cout<<res<<endl;
    return 0;
}
