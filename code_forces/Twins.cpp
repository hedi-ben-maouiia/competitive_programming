#include <cmath>
#include <cstring>
#include <functional>
#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int solve(int arr[],int size)
{
    int i;
    int sums[size];
    memset(sums, 0, size * sizeof(int));
    int sum=0; 
    for(int i=0;i<size;++i)
        cin >> arr[i];
    sort(arr, arr + size, greater<int>());
    for(i = 0; i < size; ++i)
    {
        if(i > 0)
            sums[i] = arr[i] + sums[i-1];
        else 
            sums[i] = arr[i];
        
        sum += arr[i];
    }
    int j;
    int min_sum = sum / 2;
    for(j = 0; j < size; ++j)
    {
        if(arr[j] > min_sum)
            return 1;
        if(sums[j] > min_sum)
            return j + 1;
    }
    return 0;
}

int main()
{
    int size;
    cin >> size;
    int arr[size]; 
    cout << solve(arr, size);
    return 0;
}


