#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    if (n <= 2) return 0;
    
    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int water = 0;
    
    while (left <= right) {
        if (height[left] <= height[right]) {
            if (height[left] >= leftMax) {
                leftMax = height[left];
            } else {
                water += leftMax - height[left];
            }
            left++;
        } else {
            if (height[right] >= rightMax) {
                rightMax = height[right];
            } else {
                water += rightMax - height[right];
            }
            right--;
        }
    }
    
    return water;
}

vector<int> parseInput(const string& input) {
    vector<int> height;
    if (input.find('[') != string::npos || input.find(']') != string::npos) {
        string cleaned = input;
        cleaned.erase(remove(cleaned.begin(), cleaned.end(), '['), cleaned.end());
        cleaned.erase(remove(cleaned.begin(), cleaned.end(), ']'), cleaned.end());
        stringstream ss(cleaned);
        string token;
        while (getline(ss, token, ',')) {
            token.erase(0, token.find_first_not_of(" "));
            token.erase(token.find_last_not_of(" ") + 1);
            if (!token.empty()) {
                height.push_back(stoi(token));
            }
        }
    } else {
        stringstream ss(input);
        int num;
        while (ss >> num) {
            height.push_back(num);
        }
    }
    return height;
}

int main() {
    string input;
    cout << "Enter the array : ";
    getline(cin, input);
    
    vector<int> height = parseInput(input);
    int result = trap(height);
    cout << "The amount of water trapped is: " << result << endl;
    
    return 0;
}
