#include <iostream>
#include <string>
using namespace std;

int main() {
    string str, sub;
    int count = 0;

    cout << "Enter main string: ";
    getline(cin, str);

    cout << "Enter substring: ";
    getline(cin, sub);

    int n = str.length();
    int m = sub.length();

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (str[i + j] != sub[j])
                break;
        }

        if (j == m) {   // full substring matched
            count++;
        }
    }

    cout << "Substring occurs " << count << " times." << endl;

    return 0;
}
