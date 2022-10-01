class Solution {
    int MissingNumber(int array[], int n) {
        // Your Code Here
         Arrays.sort(array);
       int num =n;
      for(int i=1;i<n;i++){
          if(array[i-1]!=i){
              return i;
          }
  
      }
      return num;
    }
}