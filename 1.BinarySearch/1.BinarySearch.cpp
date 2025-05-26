#include<iostream>
using namespace std;

// ################# Recursive Implementation ###################

int binarySearch(vector<int>& nums,int low, int high, int target){
    // Recursive implementatiion
    if(low<=high){
        int mid = low + (high-low)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]<target){
            return binarySearch(nums,mid+1,high,target);
        }
        else{
            return binarySearch(nums,low,mid-1,target);
        }
    }
    return -1;
}

int search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    return binarySearch(nums,low,high,target);
}

// ################# Iterative Implementation ###################

int search(vector<int>& nums, int target) {
    // Iterative Implementation
    int n = nums.size();
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]<target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
    int n,target;
    cout<<"Enter the no. of elements in array: "<<endl;
    cin>>n;
    cout<<"Enter the elements of array: "<<endl;
    vector<int>nums(n,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<"Enter the target element: "<<endl;
    cin>>target;
    cout<<search(nums,target);
}
