#include <iostream>
using namespace std;

int main() {
    
int n , arr[10000];
cin>>n;

for(int i = 0 ; i < n ; i++){
    cin>>arr[i];
}

int max = arr[0];

for(int i = 0 ; i < n ; i++){
    
    if(arr[i]>max){
        max = arr[i];
        cout<<max<<" ";
    }
    
    else {
        cout<<max<<" ";
    }
}




    return 0;
}
