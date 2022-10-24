#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
  const size_t sig_len {100}; // signal length
  vector<double> as (sig_len); // analogous signal
  vector<int> ds (sig_len); // digit signal
                            // conversion between as to ds leads to precision loss

  auto sin_gen ([n{0}] () mutable { // gen sinusod signal
    return 5.0 * sin(n++ * 2.0 * M_PI / 100);
  });
  generate(begin(as), end(as), sin_gen);
  copy(begin(as), end(as), begin(ds));

  copy(begin(as), end(as),
    ostream_iterator<double>{cout, " "});
  cout << "\n";
  copy(begin(ds), end(ds),
    ostream_iterator<double>{cout, " "});
  cout << "\n";

  // output accumulated divergence error
  cout << inner_product(begin(as), end(as), begin(ds),
    0.0, std::plus<double>{},
    [](double a, double b) {
      return pow(a - b, 2);
    })
    << endl;

  return(0);
}
