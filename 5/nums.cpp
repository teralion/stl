#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {
  ifstream fin("nums.txt");
  if (!fin.is_open()) {
    cout << "Can not open file nums.txt";
    exit(EXIT_FAILURE);
  }

  vector<double> nums {istream_iterator<double>{fin}, {}};
  fin.close();

  for (double num : nums) {
    cout << num << ", ";
  }
  cout << '\n';
  return 0;
}