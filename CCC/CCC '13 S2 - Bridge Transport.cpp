
#include<algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector <int> trainarr;
    int w, n; cin >> w >> n;
    trainarr.resize(n);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        trainarr[i] = a;
    }
    int counter = 4;
    int i = 0;
    int sum=trainarr[i]+trainarr[i+1]+trainarr[i+2]+trainarr[i+3];
    if(trainarr[0]>w){
        cout<<0<<endl;
        exit(0);
    }
    if(trainarr[0]+trainarr[1]>w){
        cout<<1<<endl;
        exit(0);
    }
    if(trainarr[0]+trainarr[1]+trainarr[2]>w){
        cout<<2<<endl;
        exit(0);
    }
     if(trainarr[0]+trainarr[1]+trainarr[2]+trainarr[3]>w){
        cout<<3<<endl;
        exit(0);
    }
    for(int i = 1 ; i <= n-4; i++){
                sum=sum-trainarr[i]+trainarr[i+4];
                if(sum>w){
                    break;;
                }
                counter++;

            }

    cout<<counter<<endl;
    return 0;
}
