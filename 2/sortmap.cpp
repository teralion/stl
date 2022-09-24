#include <vector>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <algorithm>

std::string filter_punctuation(const std::string &s) {
  const char *forbidden {".,:; "};
  const auto idx_start {s.find_first_not_of(forbidden)};
  const auto idx_end {s.find_last_not_of(forbidden)};
  return s.substr(idx_start, idx_end - idx_start + 1);
}

int main() {
  std::map<std::string, size_t> words;
  int max_word_len {0};

  std::string s;
  while (std::cin >> s) {
    const auto filtered(filter_punctuation(s));
    ++words[filtered];
    max_word_len = std::max<int>(max_word_len, filtered.length());
  }

  std::vector<std::pair<std::string, size_t>> words_count;
  words_count.reserve(words.size());
  std::move(std::begin(words), std::end(words), std::back_inserter(words_count));
  std::sort(std::begin(words_count), std::end(words_count),
    [](const auto &a, const auto &b){ return a.second > b.second; }
  );

  for (const auto &[word, count] : words_count) {
    std::cout << std::setw(max_word_len) << word << ": " << count << '\n';
  }

  return 0;
}
