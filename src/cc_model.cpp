#include <algorithm>
#include <iostream>
#include <utility>
#include "enums/CCProtocol.h"

CCProtocol getProtocol(std::string protocol)
{
  std::string _protocol = std::move(protocol);
  std::transform(_protocol.begin(), _protocol.end(), _protocol.begin(), ::tolower);

  if (_protocol == "msi") return MSI;
  if (_protocol == "mesi") return MESI;

  throw std::invalid_argument("Invalid protocol name!");
}

int main(int argc, char *argv[]) {
  CCProtocol protocol = argc > 1 ? getProtocol(argv[1]) : throw std::invalid_argument("Protocol required!");

  if (protocol == MSI)
  {
    std::cout << "YAY!" << std::endl;
  }

  std::cout << "Hello world! argc: " << argc << std::endl;

  return 0;
}