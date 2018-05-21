#include <iostream>

using namespace std;

void merge(int *a, int l, int m, int r) {
    // i_l and i_r are two pointers that points to the index of each tmp array.
    int i_r = 0, i_l = 0;
    int n_l = m - l + 1, n_r = r - m;

    //create tmp array
    int* L = new int[n_l];
    int* R = new int[n_r];

    for (int i = 0; i < n_l; i++)
    {
        L[i] = a[l + i];
    }
    for (int i = 0; i < n_r; i++)
    {
        R[i] = a[m + 1 + i];
    }

    // merge two tmp array into a.
    for (int k = l; k <= r; k++)
    {
        if (i_l >= n_l) a[k] = R[i_r++];
        else if (i_r >= n_r) a[k] = L[i_l++];
        else if (L[i_l] <= R[i_r]) a[k] = L[i_l++];
        else a[k] = R[i_r++];
    }

    delete[] L, R;
}

void mergesort(int *a, int l, int r) {
    int m;
    if (l < r) {
        m = (l + r) / 2;
        mergesort(a, l, m);
        mergesort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main(int argc, char** argv) {
    int num;
    cout << "How many numbers do you want to sort: ";
    cin >> num;
    int* a = new int [num];
    for (int i = 0; i < num; i++) {
        cout << (i + 1) << ": ";
        cin >> a[i];
    }

    // l merge sort
    mergesort(a, 0, num - 1);

    // Print the sorted array
    for (int i = 0; i < num; i++) {
        cout << a[i] << " ";
    }

    delete[] a;
    cin.get();
    cin.get();
    return 0;
}