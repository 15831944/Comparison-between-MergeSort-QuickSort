/*
CopyRights:
Cairo University
Faculty of Computers and Information
This code is implemented by : Mariam Ahmad Amin Beshary
To : Compare the performance between Merge Sort and Quick Sort
*/
#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

///Merging sort
void mergee(int arr[], int left, int middle, int right)
{
    int i, j, k;
    int size1 = middle - left + 1;
    int size2 =  right - middle;

    // create temp arrays that divide the original array by two
    //, one from the beginning to the middle and the other from the middle+1 to the end
    int *L = new int [size1];
    int *R = new int [size2];

   // storing data of the original array into the two temp arrays
    for (i = 0; i < size1; i++)
        L[i] = arr[left + i];

    for (j = 0; j < size2; j++)
        R[j] = arr[middle + 1+ j];

    //Now we merge the two temp arrays
    i=0 ; j=0 ; k = left ;

    while ( (i<size1) && (j<size2) )
    {
        if (L[i]<=R[j])
            arr[k++]=L[i++];
        else
            arr[k++]=R[j++];
    }
    // the first array has not ended
    while (i<size1)
    {
        arr[k++]=L[i++];
    }
    while (j<size2)
    {
        arr[k++]=R[j++];
    }

    delete [] R ;
    delete [] L ;
}

void mergeSort (int arr[] ,int left , int right )
{
    if (right>left)
    {
        int middle = left + ((right - left)/2) ;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle+1, right);
        mergee(arr, left, middle, right);
    }
}
///Quick sort
int dividing (int arr[] , int left , int right)
{
    int pivot = arr [right];
    int IndexOfGrearter = left -1 ;
    for (int i=left ; i< right ; i++)
    {
        if (arr[i]<=pivot)
        {
            IndexOfGrearter++;
            swap (arr[IndexOfGrearter],arr[i]);
        }

    }
    swap(arr[++IndexOfGrearter ], arr[right]);
    return (IndexOfGrearter );
}
void quickSort(int arr[], int left, int right )
{
    if (left < right)
    {
        int piv = dividing(arr, left, right);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, left, piv - 1);
        quickSort(arr, piv + 1, right);
    }
}

void basicFunction(int arr1 [] ,int arr2[], int sizee )
{
    for(int i=0 ; i<sizee ; i++)
    {
        arr1[i]=  rand() % 1000000 + 0;
    }
     for(int i=0 ; i<sizee ; i++)
    {
        arr2[i]=  arr1[i];
    }
    clock_t    startMerge;
    clock_t    TheEndMerge;

    startMerge = clock();

    mergeSort(arr1,0,sizee-1);
    TheEndMerge= clock();
    clock_t periodMerge = TheEndMerge - startMerge;
     cout<<"The time of sorting an array sized "<<sizee <<" using merge sort is : " <<periodMerge <<" time unit"<<endl;

    clock_t    startQuick;
    clock_t    TheEndQuick;

    startQuick = clock();

    quickSort(arr2,0,sizee-1);
    TheEndQuick= clock();
    clock_t periodQuick = TheEndQuick - startQuick;
     cout<<"The time of sorting an array sized "<<sizee <<" using Quick sort is : " <<periodQuick <<" time unit"<<endl;

     if (periodQuick<periodMerge) cout<<"Quick sort is faster .It's " <<double(periodMerge*1.0/periodQuick)<<" faster"<<endl<<endl ;
     else cout<<"Merge sort is faster.It's " <<double(periodQuick*1.0/periodMerge)<<" faster"<<endl<<endl ;

}
int main()
{
    int arr1[5000]; int arr12[5000];
    basicFunction(arr1,arr12, 5000 ) ;

    int arr2[10000];  int arr22[10000];
    basicFunction(arr2,arr22, 10000 ) ;


    int arr3[100000]; int arr32[100000];
     basicFunction(arr3,arr32, 100000 ) ;


    return 0;
}
