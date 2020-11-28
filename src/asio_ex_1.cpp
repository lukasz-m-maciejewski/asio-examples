#include <boost/asio.hpp>
#include <iostream>

// Work lambda
auto io_work = []() -> void
{
    std::cout << "Doing some work within ASIO\n";
};

int main () {
  boost::asio::io_service _io_service;

  _io_service.post(io_work);
  _io_service.run();
}
