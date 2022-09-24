#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <map>

using namespace std;

int main() {
  const size_t data_points {100000};
  const size_t samples_points {100};

  const int mean {10};
  const size_t dev {3};

  random_device rd;
  mt19937 gen {rd()};
  normal_distribution<> d {mean, dev};

  vector<int> v;
  v.reserve(data_points);
  generate_n(back_inserter(v), data_points,
    [&]{ return d(gen); });

  vector<int> samples;
  v.reserve(samples_points);

  sample(begin(v), end(v), back_inserter(samples), samples_points, mt19937{random_device{}()});

  map<int, size_t> hist;
  for (int i : samples) { ++hist[i]; }
  for (const auto &[value, count] : hist) {
    cout << setw(2) << value << " "
      << string(count, '*') << '\n';
  }

  return 0;
}