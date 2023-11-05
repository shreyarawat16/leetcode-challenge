class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maximum=-1;
    //loop over the whole array elements
    for(int i=arr.size()-1;i>=0;i--){
        //store the current value in a temp variable
        int temp=arr[i];
        //replace the current value with the maximum one & by default, the last element will be -1, as the initial value is it's
        arr[i]=maximum;
        //get the largest element by comparing
        maximum=max(maximum,temp);
    }

    //return the array elements
    return arr;
    }
};