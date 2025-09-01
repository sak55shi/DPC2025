#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int countDivisors(int N) {
    if (N == 1) return 1;
    int count = 1;
    int temp = N;
   
    int exponent = 0;
    while (temp % 2 == 0) {
        exponent++;
        temp /= 2;
    }
    count *= (exponent + 1);
    
    
    for (int i = 3; i <= sqrt(temp); i += 2) {
        exponent = 0;
        while (temp % i == 0) {
            exponent++;
            temp /= i;
        }
        count *= (exponent + 1);
    }
    
    
    if (temp > 1) {
        count *= 2;
    }
    return count;
}

int main() {
    int N;
    cout << "Enter N: ";
    cin >> N;
    cout << countDivisors(N) << endl;
    return 0;
}
