#include <algorithm>
#include <catch2/catch.hpp>
#include <functional>
#include <iterator>
#include <numeric>

#include "ctdsp.hpp"
#include "windows.hpp"

template <class Data>
bool all_equal(Data& data) {
  return std::adjacent_find(data.cbegin(), data.cend(), std::not_equal_to{}) ==
         data.cend();
}

template <class Data>
bool all_equal_to(Data& data, double value) {
  auto target = Approx(value).epsilon(0.001);
  return std::all_of(data.cbegin(), data.cend(),
                     [target](double item) { return item == target; });
}

TEST_CASE("Boxcar window", "[window]") {
  constexpr auto boxcar = ctdsp::window::boxcar<32>();
  REQUIRE(all_equal(boxcar));
}

TEST_CASE("Direct Window Creation", "[window]") {
  // Uses a immediatly invoked lambda to return the required data
  constexpr auto manipulated_window = []() {
    auto n = 0;
    auto generator = [n]() mutable { return ++n; };
    auto my_window = window::window<32>{generator};
    return my_window;
  }();
}

TEST_CASE("Window normalization", "ctdsp") {
  using ctdsp;
  constexpr auto normalized =
      ctdsp::normalize(ctdsp::window::boxcar<32>(), 5.0);
  constexpr auto normalized_value = 1. / 5.0;
  REQUIRE(all_equal_to(normalized, normalized_value));
  constexpr auto max_normalized = normalize(window::boxcar<32>(), by_max{});
  constexpr auto rms_normalized = normalize(window::boxcar<32>(), by_rms{});
}
