#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ms(a,b) memset(a,b,sizeof(a));
#define mp(a,b) make_pair(a,b);
char _;
typedef long long ll;
const ll mod = 1e9+7;
const int MAXN = 500000;
using namespace std;

pair<ll, ll>twothree(ll a){
  ll twocounter=0, threecounter=0;
  twocounter=a/2;
  if(a%2==1){
    --twocounter; ++threecounter;
  }
  while(twocounter-3>=0){
    threecounter+=2;
    twocounter-=3;
  }
  return mp(twocounter,threecounter);
}

int main()
{
    ll N; scan(N);
    ll min1 = 0, max1 = 0, onecounter = 0;
    priority_queue<ll, vector<ll>,greater<ll> >pq;
    for(int i = 0; i < N; ++i){
        ll a; scan(a);
        if(a == 1){
            ++onecounter;
        }
        else{
            min1+=a;
            pq.push(a);
        }
    }
    if(min1 == 0){
        min1 = 1;
    }
    while(onecounter > 0 ){
        if(pq.size()>=2){
            ll a,b; a = pq.top(); pq.pop(); b = pq.top(); pq.pop();
            if(onecounter>=2 && a==2 && b==2){pq.push(3); pq.push(3); onecounter-=2;}
            else if (onecounter == 1){ pq.push(a+1); pq.push(b); onecounter-=1;}
            else if (onecounter>=2){pq.push(2); onecounter-=2; pq.push(a); pq.push(b);}
        }
        else{
        if(onecounter>=2){pq.push(2); onecounter -=2; }
        else if (onecounter == 1 && !pq.empty()){int temp1 = pq.top(); pq.pop(); pq.push(temp1+1); onecounter -=1;}
        else if(onecounter == 1 && pq.empty()){pq.push(1);onecounter--;}
        }
    }
    // 4 3 2 1 1
    while(pq.size()>1){
        ll a,b;
        a = pq.top();
        pq.pop();
        b=pq.top();
        pq.pop();
        pq.push((a*b)%mod);
    }
    //10 1 1 1 1 1 1 1 1 1 1 min = 1, max = 36
    cout<<min1<<endl;
    cout<<pq.top()<<endl;
    return 0;
}
