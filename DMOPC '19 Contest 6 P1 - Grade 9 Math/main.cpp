#include <iostream>
#include <math.h>
#include <stdio.h>
#include <iomanip>
using namespace std;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
  long double x1,y1,x2,y2; scanf("%Lf%Lf%Lf%Lf",&x1,&y1,&x2,&y2);
  long double a1,b1,a2,b2; scanf("%Lf%Lf%Lf%Lf",&a1,&b1,&a2,&b2);
  long double slope1,slope2;
  if(x1-x2!=0){
    slope1=(y1-y2)/(x1-x2);
  }
  else{
    slope1=0x3f3f3f;
  }
  if(a1-a2!=0){
    slope2= (b1-b2)/(a1-a2);
  }
  else{
    slope2=0x3f3f3f;
  }
  long double const1,const2;
    if(slope1!=0x3f3f3f){
      const1=y1-slope1*x1;
    }
    else{
      const1=x1;
    }
    if(slope2!=0x3f3f3f){
      const2=b1-slope2*a1;
    }
    else{
      const2=a1;
    }
    if(abs(const1-const2)<=0.0001 && abs(slope1-slope2)<=0.0001){
      cout<<"coincident"<<endl;
    }
    else if(abs(const1-const2)>0.0001 && abs(slope1-slope2)<=0.0001){
      cout<<"parallel"<<endl;
    }
    else{
      long double xcoord;
      long double ycoord;
      if(slope1!=0x3f3f3f && slope2!=0x3f3f3f){
        xcoord= (long double)((const2-const1))/(long double)((slope1-slope2));
        ycoord = (long double)(slope1*xcoord+const1);
      }
      else if(slope1==0x3f3f3f && slope2!=0x3f3f3f){
        xcoord= const1;
        ycoord = (long double)(slope2*xcoord)+const2;
      }
      else if(slope1!=0x3f3f3f && slope2==0x3f3f3f){
        xcoord=const2;
        ycoord = (long double)(slope1*xcoord)+const1;
      }
      cout<<setprecision(6)<<fixed;
      cout<<xcoord<<" "<<ycoord<<endl;
    }


  return 0;
}
