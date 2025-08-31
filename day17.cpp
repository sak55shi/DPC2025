#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> primeFactorization(int N) {
    vector<int> factors;
    
    while (N % 2 == 0) {
        factors.push_back(2);
        N /= 2;
    }
    
    for (int i = 3; i <= sqrt(N); i += 2) {
        while (N % i == 0) {
            factors.push_back(i);
            N /= i;
        }
    }
   
    if (N > 1) {
        factors.push_back(N);
    }
    return factors;
}

int main() {
    int N;
    cout << "Enter N: ";
    cin >> N;
    vector<int> factors = primeFactorization(N);
    cout << "[";
    for (int i = 0; i < factors.size(); i++) {
        cout << factors[i];
        if (i < factors.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    return 0;
}
