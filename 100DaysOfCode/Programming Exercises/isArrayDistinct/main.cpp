#include <iostream>

using namespace std;


void merge(int A[], int l, int mid, int h){
    int i, j, k;
    i = l, j = mid+1, k = l;

    int B[h+1];


    while(i <= mid && j<=h){
        if(A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    for(; i<= mid; i++)
        B[k++] = A[i];
    for(; j<= h; j++)
        B[k++] = A[j];

    for(int i=l; i<=h; i++){
        A[i] = B[i];
    }


}

void mergeSort(int A[], int l, int h){
    int mid;
    if(l<h){
        mid = (l+h) / 2;
        mergeSort(A, l, mid);
        mergeSort(A,mid+1, h);
        merge(A, l, mid, h);
    }
}

void isDistinct(int A[], int n){
    bool disjoint = true;

    for(int i=1; i<=n; i++){
        if(A[i-1] == A[i])
            disjoint = false;
    }

    if(disjoint){
        cout<<"Array is disjoint"<<endl;
    }else{
        cout<<"Array is not disjoint"<<endl;
    }
}

int main()
{

    int A[] = {2,1,5,4,8,12,6, 12};
    int n = 8 ;

    mergeSort(A, 0, n-1);

    for(int i=0; i<n; i++){
        cout<<A[i] << " ";
    }
    cout<<endl;

    isDistinct(A, n);


    return 0;
}
