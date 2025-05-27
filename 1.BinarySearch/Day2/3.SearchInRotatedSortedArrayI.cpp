#include<iostream>
using namespace std;

 /*
 Problem statement: 
Given an integer array arr of size N, sorted in ascending order (with distinct values) and a target value k. Now the array is rotated at some pivot point unknown to you. Find the index at which k is present and if k is not present return -1.
 */

// Brute force (Linear Search) TC-> O(N)

//Optimal Approach (Binary Search)

int search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(nums[mid]==target){
            return mid;
        }
        // if left part is sorted
        else if(nums[low]<=nums[mid]){
            if(nums[low]<=target && target<=nums[mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        else{// if right part is sorted
            if(nums[mid]<=target&& target<=nums[high]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }
    return -1;
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
    cout<<"Enter the target element: "<<endl;
    cin>>target;
    cout<<search(nums,target);
}
