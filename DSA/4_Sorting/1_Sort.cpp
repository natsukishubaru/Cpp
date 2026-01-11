#include <bits/stdc++.h>
using namespace std;

void print_arr(vector<int>);

vector<int> bubble_sort(vector<int>);
vector<int> selection_sort(vector<int>);
vector<int> insertion_sort(vector<int>);

vector<int> merge_sort(vector<int>);
vector<int> divide(vector<int>&, int, int);
vector<int> merge(vector<int>&, int, int, int);

vector<int> quick(vector<int>);
void partition(vector<int>&, int, int);
int qsort(vector<int>&, int, int);

vector<int> heap_sort(vector<int> arr);

int main(){
    
    vector<int> arr = {2, 1, 4, 3, 4, 6, 5, 9, 10, 8, 7};
    print_arr(arr);
    print_arr(bubble_sort(arr));
    print_arr(selection_sort(arr));
    print_arr(insertion_sort(arr));
    print_arr(merge_sort(arr));
    print_arr(quick(arr));
    print_arr(heap_sort(arr));

    return 0;
}

void print_arr(vector<int> arr){
    cout << "{ ";
    for (auto it : arr){
        cout << it << ' ';
    }
    cout << "}\n";
    return;
}

vector<int> bubble_sort(vector<int> arr){
    int n = arr.size();
    int temp;
    for (int i = 1; i < n; i++){
        bool swap = false;
        for (int j = 0; j < n - i; j++){
            if (arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap = true;   
            }
        if (swap == false) break;
        }
    }
    return arr;
}

vector<int> selection_sort(vector<int> arr){
    int min_index, temp;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++){
        min_index = i;
        for (int j = i; j < n; j++){
            if (arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
    return arr;
}

vector<int> insertion_sort(vector<int> arr){
    int temp;
    int n = arr.size();
    for (int i = 1; i < n; i++){
        for (int j = i; j > 0; j--){
            if (arr[j] < arr[j - 1]){
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
            else{
                break;
            }
        }
    }
    return arr;
}


vector<int> merge_sort(vector<int> arr){
    return divide(arr, 0, arr.size() - 1);
}

vector<int> divide(vector<int>& arr, int low, int high){
    if (low >= high) return arr;
    divide(arr, low, (low+high)/2);
    divide(arr, (low+high)/2 + 1, high);
    merge(arr, low, (low+high)/2, high);
    return arr;
}

vector<int> merge(vector<int>& arr, int low, int mid, int high){
    int p1 = low;
    int p2 = mid + 1;
    int index = low;
    vector<int> arr_copy = arr;

    while ((p1 <= mid) && (p2 <= high)){
        if (arr_copy[p1] < arr_copy[p2]){
            arr[index] = arr_copy[p1];
            index++;
            p1++;
        }
        else{
            arr[index] = arr_copy[p2];
            index++;
            p2++;
        }
    }
    while (p1 <= mid){
        arr[index] = arr_copy[p1];
        index++;
        p1++;
    }
    while (p2 <= high){
        arr[index] = arr_copy[p2];
        index++;
        p2++;
    }
    return arr;
}


vector<int> quick(vector<int> arr) {
    partition(arr, 0, arr.size() - 1);
    return arr;
}

void partition(vector<int> &arr, int low, int high) {
    if (low >= high) return;
    
    int pivot_index  = qsort(arr, low, high);

    partition(arr, low, pivot_index - 1);
    partition(arr, pivot_index + 1, high);
}

int qsort(vector<int> &arr, int low, int high) {
    int index = low;
    int p1 = low;
    int p2 = high;
    
    while (p1 < p2) {
        while (p1 <= p2 && arr[p1] <= arr[low]) p1++;
        while (p1 <= p2 && arr[p2] > arr[low]) p2--;
    
        if (p1 < p2) {
            int temp = arr[p1];
            arr[p1] = arr[p2];
            arr[p2] = temp;
        }
    }

    int temp = arr[p2];
    arr[p2] = arr[low];
    arr[low] = temp;
    return p2;
}

vector<int> heap_sort(vector<int> arr) {
    
    priority_queue<int> heap(arr.begin(), arr.end());
    int index = arr.size() - 1;
    
    while (index >= 0) {
        arr[index--] = heap.top();
        heap.pop();
    }
    
    return arr;
}

vector<int> bucket_sort(vector<int> arr) {
    
    
    
    return arr;
}