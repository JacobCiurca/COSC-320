#ifndef DESELSORT_H_INCLUDED
#define DESELSORT_H_INCLUDED
template <class T>
    void double_ended_selection(T a[], int n){
        T min;
        T max;
        int pass = 1;
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        min = a[i];
        max = a[i];
        int min_i = i, max_i = i;
        for (int k = i; k <= j; k++)  {
            if(a[k] > max) {
                max = a[k];
                max_i = k;
            } if(a[k] < min) {
                min = a[k];
                min_i = k;
            }
        }
        T temp = a[i];
        a[i] = a[min_i];
        a[min_i] = temp;
                if(a[i] != a[min_i]){

                }

        if (a[min_i] == max){
            T temp = a[j];
            a[j] = a[min_i];
            a[min_i] = temp;
                if(a[i] != a[min_i]){

                }

        }
        else{
            T temp = a[j];
            a[j] = a[max_i];
            a[max_i] = temp;
                if(a[i] != a[max_i]){

                }


    }

    }
    }


#endif // DESELSORT_H_INCLUDED
