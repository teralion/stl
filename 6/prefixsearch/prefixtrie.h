#ifndef PREFIXTRIE_H_
#define PREFIXTRIE_H_
#include <map>
#include <functional>
#include <optional>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

template <typename T>
class trie {
  map<T, trie> tries;
public:
  template <typename It>
  void insert(It it, It end_it) {
    if (it == end_it) { return; }
    tries[*it].insert(next(it), end_it);
  }

  template <typename C>
  void insert(const C &container) {
    insert(begin(container), end(container));
  }

  void insert(const initializer_list<T> &il) {
    insert(begin(il), end(il));
  }

  void print(vector<T> &v) const {
    if (tries.empty()) {
      copy(begin(v), end(v), ostream_iterator<T>{cout, " "});
      cout << '\n';
    }
    for (const auto &[leaf, branch] : tries) {
      v.push_back(leaf);
      branch.print(v);
      v.pop_back();
    }
  }

  void print() const {
    vector<T> v;
    print(v);
  }

  template <typename It>
  optional<reference_wrapper<const trie>>
  subtrie(It it, It end_it) const {
    if (it == end_it) { return ref(*this); }
    auto found (tries.find(*it));
    if (found == end(tries)) { return {}; }
    return found->second.subtrie(next(it), end_it);
  }

  template <typename C>
  auto subtrie(const C &c) {
    return subtrie(begin(c), end(c));
  }
};
#endif