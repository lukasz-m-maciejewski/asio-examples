# Generic test that uses conan libs
add_executable(intro main.cpp)
target_link_libraries(
  intro
  PRIVATE project_options
          project_warnings
          CONAN_PKG::docopt.cpp
          CONAN_PKG::fmt
          CONAN_PKG::spdlog
          CONAN_PKG::boost)

add_executable(asio_example_1 asio_ex_1.cpp)
target_link_libraries(
  asio_example_1
  PRIVATE
  project_options
  project_warnings
  CONAN_PKG::fmt
  CONAN_PKG::boost
  )

add_executable(asio_example_2 asio_ex_2.cpp)
target_link_libraries(
  asio_example_2
  PRIVATE
  project_options
  project_warnings
  CONAN_PKG::fmt
  CONAN_PKG::boost
  CONAN_PKG::range-v3
  )
