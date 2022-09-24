#include <map>
#include <iterator>
#include <string>
#include <iostream>
#include <algorithm>

std::string filter_ws(const std::string &s) {
  // TODO: implement
  return s;
}

std::multimap<size_t, std::string> get_sentence_stats(const std::string &content) {
  std::multimap<size_t, std::string> ret;
  const auto end_it {std::end(content)};
  auto it1 {std::begin(content)};
  auto it2 {std::find(it1, end_it, '.')};

  while (it1 != end_it && std::distance(it1, it2) > 0) {
    std::string s {filter_ws({it1, it2})};
    if (s.length() > 0) {
      const auto words_count {std::count(std::begin(s), std::end(s), ' ') + 1};
      ret.emplace(std::make_pair(words_count, std::move(s)));
    }

    if (it2 == end_it) {
      break;
    }

    it1 = std::next(it2);
    it2 = std::find(it1, end_it, '.');
  }

  return ret;
}

int main() {
  std::cin.unsetf(std::ios::skipws);
  std::string content {std::istream_iterator<char>{std::cin}, {}};
  for (const auto &[word_count, sentence] : get_sentence_stats(content)) {
    std::cout << word_count << " words: " << sentence << '\n';
  }

  return 0;
}