
#include <bits/stdc++.h>

bool isPossible(vector<int> arr, int size, int m , int mid){
    int time = 0;
    int dish = 0;
    for(int i=0; i<size ; i++){
        time = arr[i];
        int j = 2;
        while(time <= mid){
            dish ++;
            time = time + (arr[i]*j);
            j++;
        }
        if(dish >= m){
            return true;
        }
    }
    return false;
}

int minCookTime(vector<int> &rank, int m)
{
    // Write your code here
    int start =0 ;
    int end = 1e9;
    int result =0;

    while (start <= end){
        int mid = start + (end-start)/2 ;
        if(isPossible(rank, rank.size(), m, mid)){
            result = mid;
            end = mid -1;
        }
        else{
            start = mid +1;
        }
    }
    return result;
}
