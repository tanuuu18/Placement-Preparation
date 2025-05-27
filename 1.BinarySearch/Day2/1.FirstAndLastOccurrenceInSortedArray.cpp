#include<iostream>
using namespace std;

 /*
 Problem statement: 
Given a sorted array arr of n integers and a target value k. Write a program to find the indices of the first and the last occurrences of the target value. If the target is not found then return -1 as indices.
 */

// Brute force (Linear Search)  TC-> O(n)
vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    int first = -1, last = -1;
    for(int i=0;i<n;i++){
        if(nums[i]==target){
            if(first==-1){
                first = i;
            }
            last = i;
        }
    }
    return {first,last};
}


// Better (Using Lower Bound & Upper Bound) TC ->O(2*log(N))

int lowerBound(vector<int>& nums,int n, int target){
    int low = 0;
    int high = n-1;
    int ans = n;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(nums[mid]>=target){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

int upperBound(vector<int>& nums,int n, int target){
    int low = 0;
    int high = n-1;
    int ans = n;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(nums[mid]>target){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}
vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    int lb = lowerBound(nums,n,target);
    if(lb==n || nums[lb]!=target){
        return {-1,-1};
    }
    int ub = upperBound(nums,n,target);
    return {lb,ub-1};
}


// Optimal using Binary Search from Scratch TC ->O(2*log(N))
int firstOccurrence(vector<int>& nums,int n, int target){
    int low = 0;
    int high = n-1;
    int first = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(nums[mid]==target){
            first = mid;
            high = mid-1;// move left
        }
        else if(nums[mid]<target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return first;
}

int lastOccurrence(vector<int>& nums,int n, int target){
    int low = 0;
    int high = n-1;
    int last = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(nums[mid]==target){
            last = mid;
            low = mid+1;// move right
        }
        else if(nums[mid]>target){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return last;
}
vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    int first = firstOccurrence(nums,n,target);
    int last = lastOccurrence(nums,n,target);
    return {first,last};
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
    vector<int> result = searchRange(nums, target);

    cout << "First and Last Occurrence: ";
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
}