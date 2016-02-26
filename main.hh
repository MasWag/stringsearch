#pragma once
#include <chrono>
#include <iostream>
#include <iterator>
#include <string>

template <class PTYPE>
int Main(int argc, char *argv[])
{
  if (argc != 2) {
    std::cout << "usage: " << argv[0] << " pattern" << std::endl;
  }
 
  const std::istream_iterator<char> it(std::cin);
  const std::istream_iterator<char> end;
  const std::string target(it, end);
  PTYPE prog;
  
  auto tstart = std::chrono::system_clock::now();
  int ret = prog (argv[1],target);
  auto tend = std::chrono::system_clock::now();
  auto dur = tend - tstart;
  auto nsec = std::chrono::duration_cast<std::chrono::nanoseconds>(dur).count();
  std::cout << nsec / 1000000.0 << " ms" << std::endl;


  std::cout << ret << std::endl;
  
  return 0;
}
