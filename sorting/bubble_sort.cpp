#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> a = {4,45,2,3,67,5,99,78};
    int i,j,f=0;
    cout<<"befort sorted: ";
    for(int e : a)
        cout<<e<<", ";
    cout<<endl;
    
    do
    {
        f=0;
        for(i=0;i<a.size()-1;i++)
        {
            if(a[i]>a[i+1])
                {
                    swap(a[i],a[i+1]);
                    f=1;
                }
        }

    } while (f);
    cout<<"After sorted: ";
    for(int e:a)
        cout<<e<<", ";


    /*    for (int i = 0; i < n - 1; i++) {

        swapped = false;

        // After each pass, last i elements are already sorted
        for (int j = 0; j < n - i - 1; j++) {

            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }

        // If no swap happened → array already sorted
        if (!swapped)
            break;
    }
    */
    return 0;
}