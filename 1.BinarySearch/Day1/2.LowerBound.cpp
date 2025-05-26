#include<iostream>
using namespace std;

// ################ Brute Force Approach ##################

// perform the linear search to the array and return the index;
// if not found any such index the return n



// ################### Optimal Approach (Binary Search) #############

int lowerBound(vector<int>& arr, int target) {
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int ans = n;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]>=target){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

//main code
int main(){
    int n,target;
    cout<<"Enter the no. of elements in array: "<<endl;
    cin>>n;
    cout<<"Enter the elements of array: "<<endl;
    vector<int>nums(n,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<"Enter the target to find lower bound:"<<endl;
    cin>>target;
    cout<<lowerBound(nums,target)<<endl;
}
