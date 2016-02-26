#include <iostream>
#include <vector>
#include <string>
#include <boost/utility/string_ref.hpp>
#include <functional>
#include <algorithm>
#include <array>
#include "main.hh"

struct BoyerMoore {
  int operator()(const std::string pattern, const std::string target) const {
    const int N = pattern.size();
    const int M = target.size();
    
    std::array<int,128> delta1;
    delta1.fill(1);
    for (int c = 0;c < 128;c++) {
      for (int k = N - 1;k > 0;k--) {
        if (pattern[k] == c) {
            delta1[c] = -k;
        }
      }
    }

    std::vector<int> delta2;
    delta2.resize(N);
    std::fill(delta2.begin(), delta2.end(), N);

    for (int j = N-1; j >= 0;j--) {
      for (int n = 1;n <= j+1;n++) {
        if (pattern.substr( j - n + 1,N - 1 - j) == pattern.substr(j + 1) ||
            pattern.substr(0 , N - 1 - n) == pattern.substr(n + 1)) {
          delta2[j] = n;
          break;
        }
      }
    }
    
    for (int i = N - 1;i < M;) {
      int j = i;
      int posInPat = N - 1;
      while (pattern[posInPat] == target[j]) {
        if (!posInPat) {
          return j;
        }
        j--;
        posInPat--;
      }

      i += std::max (delta1[target[j]] + posInPat,
                     delta2[posInPat]);
    }
    return -1;
  }
};

int main (int argc, char *argv[]) {
  return Main<BoyerMoore>(argc, argv);
}
