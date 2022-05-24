void merge(vector<int> &vec, vector<int> &v1, vector<int> &v2) {
    auto siz1 = v1.size();
    auto siz2 = v2.size();
    size_t p1 = 0;
    size_t p2 = 0;

    while (p1 < siz1 && p2 < siz2) {
        if (v1.at(p1) < v2.at(p2))
            vec.push_back(v1.at(p1++));
        else
            vec.push_back(v2.at(p2++));
    }

    while (p1 < siz1) vec.push_back(v1.at(p1++));
    while (p2 < siz2) vec.push_back(v2.at(p2++));
}


void mergeSort(vector<int> &vec) {
    if (vec.size() <= 1)
        return;

    auto iter = vec.begin() + vec.size() / 2;
    vector<int> v1(vec.begin(), iter);
    vector<int> v2(iter, vec.end());

    mergeSort(v1);
    mergeSort(v2);

    vec.clear();
    merge(vec, v1, v2);
}  

int Solution::kthsmallest(const vector<int> &A, int B) {
    vector<int> sA = A;
    mergeSort(sA);
    return sA[B-1];
}
