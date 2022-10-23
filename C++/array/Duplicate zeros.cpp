#include <bits/stdc++.h>
using namespace std;

bool validMountainArray(vector<int>& A) 
    {
        if(A.size() < 3) return false;
        int i = 1;
        while(i<A.size() && A[i]>A[i-1])
        {
            i++;
        }
        if(i==1 || i==A.size())
        {
            return false;
        }
        
        while(i<A.size() && A[i]<A[i-1])
        {
            i++;
        }
        
        if(i == A.size())
        {
            return true;
        }
        return false;
        
    }
int main()
{
    vector<int> a = {0,3,2,1};
    bool x= validMountainArray(a);
    if(x==0){cout<<"false";}
    else if(x==1){cout<<"true";}
    return 0;
}