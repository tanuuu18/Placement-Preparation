#include<iostream>
using namespace std;


 /*
 Problem statement: 
You're given an sorted array arr of n integers and an integer x. Find the floor and ceiling of x in arr[0..n-1].

The floor of x is the largest element in the array which is smaller than or equal to x.

The ceiling of x is the smallest element in the array greater than or equal to x.
 */

int findFloor(vector<int>& arr, int x) {
    // Your code here
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int ans = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]<=x){
            ans = mid;
            low = mid + 1;// to find larger eliminate left half and goest to right half
        }
        else{
            high = mid - 1;
        }
    }
    return ans; // return the element
}


int findCeil(vector<int>& arr, int x) {
    // code here
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int ans = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]>=x){
            ans = mid;
            high = mid-1;// to find the smaller element eliminate the right half and goes to left half
        }
        else{
            low = mid+1;
        }
    }
    return ans;//return the index
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
    cout<<"Floor value:" << findFloor(nums,target)<<endl;
    cout<<"Ceil Value index:" << findCeil(nums,target)<<endl;
}