#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void Create(int** a, const int k, const int n, const int Low, const int High);
void Print(int** a, const int k, const int n);
void SwapMinMaxInRows(int** a, const int k, const int n);

int main() {
    srand((unsigned)time(NULL));
    int Low = 7;
    int High = 65;
    int k, n;

    cout << "k = ";
    cin >> k;
    cout << "n = ";
    cin >> n;

    int** a = new int* [k]; 
    for (int i = 0; i < k; i++)
        a[i] = new int[n]; 

    Create(a, k, n, Low, High);
    cout << "Matrix before swapping:" << endl;
    Print(a, k, n);

    SwapMinMaxInRows(a, k, n);

    cout << "Matrix after swapping:" << endl;
    Print(a, k, n);


    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int k, const int n, const int Low, const int High) {
    for (int i = 0; i < k; i++) { 
        for (int j = 0; j < n; j++) { 
            a[i][j] = Low + rand() % (High - Low + 1); 
        }
    }
}

void Print(int** a, const int k, const int n) {
    cout << endl;
    for (int i = 0; i < k; i++) { 
        for (int j = 0; j < n; j++) {  
            cout << setw(4) << a[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void SwapMinMaxInRows(int** a, const int k, const int n) {
    for (int i = 0; i < k; i++) { 
        int maxIdx = 0, minIdx = 0;

      
        for (int j = 1; j < n; j++) {
            if (a[i][j] > a[i][maxIdx])
                maxIdx = j;
            if (a[i][j] < a[i][minIdx])
                minIdx = j;
        }

        
        int temp = a[i][maxIdx];
        a[i][maxIdx] = a[i][minIdx];
        a[i][minIdx] = temp;
    }
}
