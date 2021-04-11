#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);
#define ms(a,b) memset(a,b,sizeof(a));
#define mp(a,b) make_pair(a,b);
char _;
typedef long long ll;
using namespace std;

ll len[31];
string strtemp = "Good writing is good Good writing is good writing is good writing. writing is good Good writing is good writing is good writing. is good writing.";
string str1 = "Good writing is good writing is good writing.";
string str2 = "Good writing is good ";
string str3 = " writing is good ";
string str4 = " is good writing.";

char function1 (int n, ll k){
    if(k>=len[n]){
        return '.';
    }
    else{
        if(n==0){
            return str1[k];
        }
        else if(k<str2.length()){
            return str2[k];
        }
        else if(k>=str2.length() && k < len[n-1]+str2.length()){
            return function1(n-1,k-str2.length());
        }
        else if(k>=len[n-1]+str2.length() && k < len[n-1]+str2.length()+str3.length() ){
            return str3[k-len[n-1]-str2.length()];
        }
        else if (k >= len[n-1]+str2.length()+str3.length() && k < 2*len[n-1]+str2.length()+str3.length()){
            return function1(n-1,k-len[n-1]-str2.length()-str3.length());
        }
        else if (k>=2*len[n-1]+str2.length()+str3.length()){
            return str4[k-2*len[n-1]-str3.length()-str2.length()];
        }

    }
}

int main()
{
    len[0]=str1.length();
//    cout<<len[0]<<endl;
    for(int i = 1; i <= 30; ++i){
        len[i]=str2.length()+len[i-1]+str3.length()+len[i-1]+str4.length();
    }
//    cout<<str2.length()<<" "<<str3.length()<<endl;
    int n,a; cin>>n;
    for(int i = 0; i < n; ++i){
        ll b; cin>>a>>b;
        cout<<function1(a,b-1)<<endl;
    }
    return 0;
}
