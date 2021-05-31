#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#include<unistd.h>
#include <windows.h>

using namespace std;
unsigned int microsecond = 1000000;
//usleep(10 * microsecond);//sleeps for 3 second

void mergeArrays(int x[],int y[],int a[],int s,int e){
    int mid = (s+e)/2;
    int i=s;
    int j = mid+1;
    int k = s;
    while(i<=mid && j<=e){
        if(x[i] < y[j]){
            a[k] = x[i];
            i++;
            k++;
        }else{
            a[k] = y[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        a[k] = x[i];
        k++;
        i++;
    }
    while(j<=e){
        a[k] = y[j];
        k++;
        j++;
    }
}
int *x = new int[10000000];
int *y = new int[10000000];

void mergeSort(int a[],int s,int e){
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;
    for(int i=s;i<=mid;i++){
        x[i] = a[i];
    }
    for(int i=mid+1;i<=e;i++){
        y[i] = a[i];
    }
    mergeSort(x,s,mid);
    mergeSort(y,mid+1,e);
    mergeArrays(x,y,a,s,e);
}
void quickSort(int arr[], int left, int right) {

    int i = left, j = right;

    int tmp;

    int pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    if (left < j)quickSort(arr, left, j);
    if (i < right)quickSort(arr, i, right);
}
/*/
int partition (int arr[], int start, int end){
    int pivot = arr[start];
    int l = start;
    int r = end;
    while (l < r) {
        do {
            l++;
        } while (arr[l] <= pivot);
        do {
            r--;
        } while (arr[r] > pivot);
        if(l < r)
            swap(arr[l], arr[r]);
    }
    swap(arr[start], arr[r]);
    return r;
}


void quickSort(int a[],int s,int e){
    if(s>=e){
        return;
    }
    int p = partition(a,s,e);
    quickSort(a,s,p-1);
    quickSort(a,p+1,e);
}
/*/
long getTimeInMicroSeconds(){
    struct timeval currentTime;
    gettimeofday(&currentTime, NULL);
    return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);



cout << "all below answers are MACRO SEC"<<endl;
cout << "------------------------------"<<endl;

    for(int n=10;n<=10000000; n *= 10){
        int *arr = new int[n];
        long startTime , endTime;
        srand((unsigned)time(0));
        for(int i=0;i<n;i++){
            arr[i] = rand();
        }
        startTime = getTimeInMicroSeconds();
        mergeSort(arr,0,n-1);
        endTime = getTimeInMicroSeconds();
        cout<<"merge sort n = "<<n<<" time = "<<endTime-startTime<<endl;
        delete []arr;
    }
    cout << "-------------------------------------------------"<<endl;
    cout << "-------------------------------------------------"<< endl;

    for(int n=10;n<=10000000; n *= 10){
        int *arr = new int[n];
        long startTime , endTime;
        srand((unsigned)time(0));
        for(int i=0;i<n;i++){
            arr[i] = rand();
        }
        startTime = getTimeInMicroSeconds();
        quickSort(arr,0,n);
        endTime = getTimeInMicroSeconds();
        cout<<"quick sort n = "<<n<<" time = "<<endTime-startTime<<endl;
        delete []arr;
    }
}















