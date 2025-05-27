#include<iostream>
using namespace std;

 /*
 Problem statement: 
You are given a sorted array containing N integers and a number X, you have to find the occurrences of X in the given array.
 */

// Brute force (Linear Search)  TC-> O(n)
int countFreq(vector<int>& arr, int target) {
    int n = arr.size();
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            cnt++;
        }
    }
    return cnt;
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
int countFreq(vector<int>& arr, int target) {
    // code here
    int n = arr.size();
    int first = firstOccurrence(arr,n,target);
    if(first==-1){
        return 0;
    }
    int last = lastOccurrence(arr,n,target);
    return last-first+1;
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
    cout << "No. of Occurrence: "<<countFreq(nums,target) << endl;
}