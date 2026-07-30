
#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int arr[5];
    cout<<"enter 5 array element "<<endl;
    for(int i=0;i<5;i++){
        cin>>arr[i];
    }
    
    int Max = arr[0];
    cout<<"The max ele is :-"<<endl;
    
    for(int i=0;i<5;i++){
        Max = max(Max,arr[i]);
    }
    cout<<Max;
    
return 0;
}
