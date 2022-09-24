#include "prefixtrie.h"
#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <fstream>
#include <list>

using namespace std;

static void prompt() {
  cout << "Next input, please:\n > ";
}

int main() {
  trie<string> t;
  fstream infile {"db.txt"};
  for (string line; getline(infile, line);) {
    istringstream iss {line};
    t.insert(istream_iterator<string>{iss}, {});
  }

  prompt();
  for (string line; getline(cin, line);) {
    istringstream iss {line};
    if (auto st(t.subtrie(istream_iterator<string>{iss}, {})); st) {
      cout << "Suggestions:\n";
      st->get().print();
    } else {
      cout << "No suggestions found.\n";
    }

    cout << "--------\n";
    prompt();
  }

  return 0;
}