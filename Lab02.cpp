#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include "binsearch.h"
#include "deSelsort.h"
using namespace std;
int main()
{
    int arr[10000];
    for(int i=0; i<10000; i++){
        arr[i] = rand() % 100000; //set array to number between 0-99999

    }
    double_ended_selection(arr, 10000);
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;
    for(int i = 0; i<10000; i++){
        target = rand() % 100000;
        binSearch(arr, 0, n-1, target);
    }
    float averageCase = sumFailCom/(10000-successTotal);
    cout << "Total number of successful searches out of 10000: " << successTotal << endl;
    cout << "Worst case results for unsuccessful binary search of array size 10000: ";
    cout << averageCase << endl;
    return 0;
}
