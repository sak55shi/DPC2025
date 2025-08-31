#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(long long n, long long m) {
    return (n / gcd(n, m)) * m;
}

int main() {
    string input;
    cout << "Enter input: ";
    getline(cin, input);

    long long n, m;
    size_t n_pos = input.find("N = ");
    if (n_pos != string::npos) {
        n_pos += 4;
        size_t n_end = input.find(',', n_pos);
        if (n_end == string::npos) {
            n_end = input.length();
        }
        string n_str = input.substr(n_pos, n_end - n_pos);
        n = stoll(n_str);
    }

    size_t m_pos = input.find("M = ");
    if (m_pos != string::npos) {
        m_pos += 4;
        size_t m_end = input.length();
        string m_str = input.substr(m_pos, m_end - m_pos);
        m = stoll(m_str);
    }
    cout<< "Output : ";
    cout << lcm(n, m) << endl;
    return 0;
}
