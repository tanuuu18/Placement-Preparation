#include<iostream>
using namespace std;

 /*
 Problem statement: 
Given an integer array arr of size N, sorted in ascending order (may contain duplicate values) and a target value k. Now the array is rotated at some pivot point unknown to you. Return True if k is present and otherwise, return False. 
 */

// Brute force (Linear Search) TC-> O(N)

//Optimal Approach (Binary Search)

bool search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(nums[mid]==target){
            return true;
        }
        if(nums[low]==nums[mid] && nums[mid]==nums[high]){
            low = low+1;
            high = high-1;
            continue;
        }
        // if left part is sorted
        if(nums[low]<=nums[mid]){
            if(nums[low]<=target && target < nums[mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        else{// if right part is sorted
            if(nums[mid]<target && target<=nums[high]){
                
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
    
    return false;
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
