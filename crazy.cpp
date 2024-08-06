#include <iostream>

int binarySearch(int arr[],int low, int high, int target){
    while (low <= high){
        int mid = (low+high)/2;
        if (arr[mid]==target){
            return 1;
        }
        else if (arr[mid]<target){
            return binarySearch(arr,mid+1,high,target);
        }
        else{
            return binarySearch(arr,low,mid-1,target);
        }
    }
    return 0;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    std::cout << binarySearch(arr,0,8,7);
}