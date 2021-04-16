#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int main()
{
    pair<int,int> sensors[1000];
    int secondabs;
    int firstabs;
    int n; cin>>n;
    for(int i = 0 ; i < 1000; i++){
        sensors[i].second=i+1;
        sensors[i].first=0;
    }
    for(int i = 0 ; i < n; i++){
        int b; cin>>b;
        sensors[b-1].first++;
    }
    sort(sensors,sensors+1000);
    pair <int,int> common = sensors[999];
    pair <int,int> secondcommon=sensors[998];
    int i = 998;
    firstabs=abs((secondcommon.second)-(common.second));
    if (sensors[i-1].first!=(secondcommon.first)) {
		cout<<abs((common.second)-(secondcommon.second));
	}
	else {
		firstabs=abs((common.second)-(secondcommon.second));
		while (sensors[i-1].first==secondcommon.first and i!=-1) {
			i-=1;
		}
		secondabs=abs(common.second-sensors[i].second);
		if (firstabs>secondabs) cout<<firstabs<<endl;
		else cout<<secondabs<<endl;
	}

	return 0;
}
