#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int a,b,c,d,e;
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>d;
    cin>>e;
    if ( ((e-((c-a)+(d-b)))%2==0)&&(e>=(abs(c-a))+abs(d-b)) ){
        cout<<"Y"<<endl;
    }
    else{
        cout<<"N"<<endl;
    }
    return 0;
}
