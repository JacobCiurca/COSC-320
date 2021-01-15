#include <iostream>
#include "deSelsort.h"
using namespace std;

int main()
{
    cout << "Please enter the size you would like the array to be.\n";
    int s;
    cin >> s;
    cout << "Please enter the array.\n";
    int arr[s];
    for(int i=0; i<s; i++){
        cin >> arr[i];
    }
    cout << "Starting Array: ";
    for(int i=0; i<s; i++){
        cout << arr[i] << ", ";
    }
    cout << endl;
    double_ended_selection(arr, s);
    cout << "Sorted Array: ";
    for(int i=0; i<s; i++){
        cout << arr[i] << ", ";
    }
    return 0;
}
