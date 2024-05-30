#include <iostream>

int main(int argc, char**argv) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " check" << std::endl;
    return 1;
  }

  std::string command = argv[1];

  std::cout << command;
  return 0;
}
