#include <string>

#include <string>
#include "main.hh"

using namespace std;

struct naive {
  int operator()(const string pattern, const string target) const
  {
    const int N = pattern.size();
    const int M = target.size();
    for (int i = 0; i <= M - N;i++) {
      int j = 0;
      for (;j < N && pattern[j] == target[i+j];j++);
      if (j == N) {     
        return i;
      }
    }

    return -1;
  }
};
  
int main (int argc, char *argv[]) {
  return Main<naive>(argc, argv);
}
