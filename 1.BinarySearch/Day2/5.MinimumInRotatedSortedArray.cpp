#include<iostream>
using namespace std;

 /*
 Problem statement: 
 Given an integer array arr of size N, sorted in ascending order (with distinct values). Now the array is rotated between 1 to N times which is unknown. Find the minimum element in the array. 
 */

// Brute Force Approach (Linear search) and return the min element

// Optimal (Binary search)
int findMin(vector<int>& nums) {
    int n = nums.size();
    int low = 0;
    int high = n-1;
    int ans = INT_MAX;
    while(low<=high){
        int mid = low + (high-low)/2;
        // if left part is sorted
        if(nums[low]<=nums[mid]){
            ans = min(ans,nums[low]);
            low = mid+1;//eliminate left half
        }
        else{
            ans = min(ans,nums[mid]);
            high = mid-1;//eliminate right half
        }
    }
    return ans;
}

// Further Optimized Approach (Binary Search)
int findMin(vector<int>& nums) {
    int n = nums.size();
    int low = 0;
    int high = n-1;
    int ans = INT_MAX;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(nums[low]<=nums[high]){
            ans = min(ans,nums[low]);
            break;
        }
        // if left part is sorted
        if(nums[low]<=nums[mid]){
            ans = min(ans,nums[low]);
            low = mid+1;//eliminate left half
        }
        else{
            ans = min(ans,nums[mid]);
            high = mid-1;//eliminate right half
        }
    }
    return ans;
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
    cout<<findMin(nums)<<endl;
}
