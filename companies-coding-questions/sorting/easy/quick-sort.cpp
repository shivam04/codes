int partition(vector<int> &arr, int l, int h) {
    srand(time(NULL));
    int random = l + rand() % (h - l);
    swap(arr[random], arr[h]);
    int pivot = arr[h];
    int i = l-1;
    for(int j=l;j<=h-1;j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);
    return i+1;
}
void quickSort(vector<int> &arr, int l, int h) {
    if(l<h) {
        int pi = partition(arr, l, h);
        quickSort(arr, l, pi-1);
        quickSort(arr, pi+1, h);
    }
}
vector<int> Solution::solve(vector<int> &A) {
    quickSort(A, 0, A.size() - 1);
    return A;
}
