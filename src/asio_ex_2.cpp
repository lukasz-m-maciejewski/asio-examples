#include <boost/asio.hpp>
#include <iostream>
#include <memory>
#include <ranges>

// Start and make threads available to the io_service
constexpr int num_threads = 8;

int main() {
  // Make io_service
  boost::asio::io_service io_service;

  std::array<std::thread, num_threads> threads;

  auto work = std::make_unique<boost::asio::io_service::work>(io_service);

  std::ranges::for_each(threads, [&io_service](auto& thread) {
    thread = std::thread([&io_service]() { io_service.run(); });
  });

  auto print_thread_id = []() {
    std::cout << "Current thread id: " << std::this_thread::get_id() << "\n";
  };

  // Make the threads work
  // for (auto i = 0; i < num_threads * 2; ++i) {
    io_service.post(print_thread_id);
  // }
  // Reset work
  work.reset();

  // Wait for completion
  for (auto& thread : threads) {
    thread.join();
  }
  return 0;
}
