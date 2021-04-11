#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector <boolean> numarr;
    int n; cin>>n;
    numarr.resize(n)

    for(int i = 0 ; i < n; i++){
        int a; cin>>a;
        numarr[i]=a;
    }
    sort(numarr.begin(),numarr.end());
    int numcounter=0;
    for(int i = 0; i <= n; i++){
        if(i==0||numarr[i]==numarr[i-1]){
            ++numcounter;
        }
        else{
            if(numcounter%2==1){
                cout<<numarr[i-1]<<endl;
                exit(0);
            }
            numcounter=1;
        }
    }
    */
    return 0;
}
