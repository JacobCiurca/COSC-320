#ifndef BINSEARCH_H_INCLUDED
#define BINSEARCH_H_INCLUDED
#include <iostream>
using namespace std;
int sumFailCom = 0;
int successTotal = 0;
void binSearch(int arr[], int left, int right, int target, int pass = 0){
    if(right>=left){
        int middle = left+(right-left) / 2;

        if(arr[middle] == target){
                successTotal = successTotal + 1;
            return;
        }
        if(arr[middle] > target){
            return binSearch(arr, left, middle-1, target, pass+1);
        }
        else{

            return binSearch(arr, middle+1, right, target, pass+1);
        }



}

        sumFailCom = sumFailCom + pass;
}

#endif // BINSEARCH_H_INCLUDED
