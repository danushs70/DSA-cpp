#include <iostream>
#include <vector>
using namespace std;
void print_arr(vector<int> &a)
{
    for(int e:a)
        cout<<e<<", ";

    cout<<endl;
}
int main() {
    vector<int> a = {29, 7, 6, 12, 2};
    int n = a.size();

    cout << "Before sorted: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    // Insertion Sort
    for (int i = 1; i < n; i++) {
        int key = a[i];       // element to be inserted
        int j = i - 1;

        // move elements greater than key to one position ahead
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;   // insert the key in correct position
        //print_arr(a);
    }

    cout << "After sorted: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    return 0;
}
