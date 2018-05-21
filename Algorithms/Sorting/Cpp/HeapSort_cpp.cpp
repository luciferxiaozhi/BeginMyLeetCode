#include <iostream>

//void Fix_up(int* A, int k);
void Fix_down(int* A, int& size, int k);
//void Insert(int* A, int& size, const int& x);
int DeleteMax(int *A, int& size);
void Heapify(int *A, int& size);
void HeapSort(int *A, int& size);

/*
void Fix_up(int* A, int k)
{
    while (k > 0 && A[(k-1)/2] < A[k])
    {
        int tmp = A[k];
        A[k] = A[(k-1)/2];
        A[(k-1)/2] = tmp;
        k = (k-1) / 2;
    }
}
*/

void Fix_down(int* A, int& size, int k)
{
    // k is not a leaf
    while (2 * k + 1 <= size - 1)
    {
        // Find the child with the largest key
        int j = 2 * k + 1;
        if (j < size - 1 && A[j + 1] > A[j])
            j += 1;
        if (A[k] >= A[j]) break;
        //swap A[k] and A[j]
        int tmp = A[k];
        A[k] = A[j];
        A[j] = tmp;
        k = j;
    }
}
/*
void Insert(int* A, int& size, const int& x)
{
    size += 1;
    A[size - 1] = x;
    Fix_up(A, size - 1);
}
*/
int DeleteMax(int *A, int& size)
{
    int res = A[0];
    A[0] = A[size - 1];
    A[size - 1] = res;
    size -= 1;
    Fix_down(A, size, 0);
    return res;
}

void Heapify(int *A, int& size)
{
    for (int i = (size - 2) / 2; i >= 0; i--)
        Fix_down(A, size, i);
}

void HeapSort(int *A, int size)
{
    int n = size;
    Heapify(A, size);
    while (n > 1)
    {
        DeleteMax(A, n);
    }
}

int main()
{
    const int SIZE = 10;
    int A[SIZE] = { 4, 5, 1, 3, 7, 9, 9, 9, 9, 8 };
    HeapSort(A, SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << A[i] << std::endl;
    }
    
    std::cin.get();
}