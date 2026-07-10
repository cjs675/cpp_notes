#include <iostream>
#include <chrono> 

using namespace std;

int partition(vector<int> &vec, int low, int high) {

    // selecting last element as pivot 
    int pivot = vec[high];

    // index 2nd to last element 
    // used for swapping 
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {

        // if current element <= pivot 
        if (vec[j] <= pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }

    // put pivot to its position 
    swap(vec[i + 1], vec[high]);

    // return point of partition 
    return (i + 1);
}

void quickSort(vector<int> &vec, int low, int high) {

    // base case: will be executed until starting index 
    // < ending index high 
    if (low < high) {

        // pi = partitioning index
        // arr[p] now at right place 
        int pi = partition(vec, low, high);

        // separately sort elements before & after pi 
        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}

int main() {

    vector<int> vec = {19, 17, 15, 12, 16, 18, 4, 11, 13};
    int n = vec.size();
    
    // start timer 
    auto start = chrono::high_resolution_clock::now();

    // calling quicksort for vector vec 
    quickSort(vec, 0, n - 1);
    

    // stop timer 
    auto stop = chrono::high_resolution_clock::now();
    
    // calculate elapsed time 
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    for (auto i : vec) {
        cout << i << " ";
    }
    
    cout << "\n\nTime Taken by quicksort: " 
         << duration.count() << " microseconds" << endl;

    
    return 0;
}
