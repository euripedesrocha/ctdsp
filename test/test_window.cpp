#include <algorithm>
#include <catch2/catch.hpp>
#include <functional>
#include <iterator>
#include <numeric>

#include "ctdsp/ctdsp.hpp"
#include "ctdsp/windows.hpp"

// template <class Data>
// bool all_equal(Data& data) {
// return std::adjacent_find(data.cbegin(), data.cend(), std::not_equal_to{}) ==
// data.cend();
//}

// template <class Data>
// bool all_equal_to(Data& data, double value) {
// auto target = Approx(value).epsilon(0.001);
// return std::all_of(data.cbegin(), data.cend(),
//[target](double item) { return item == target; });
//}

// TEST_CASE("Boxcar window", "[window]") {
// constexpr auto boxcar = ctdsp::window::boxcar<32>();
// REQUIRE(all_equal(boxcar));
//}

// TEST_CASE("Direct Window Creation", "[window]") {
// using namespace ctdsp;
//// Uses a immediatly invoked lambda to return the required data
//[[maybe_unused]] constexpr auto manipulated_window = []() {
// constexpr size_t length = 32;
// constexpr auto generator = [n = 0]() mutable { return ++n; };
// constexpr auto my_window = window::window<length>{generator};
// return my_window;
//}();
//}

// TEST_CASE("Window normalization", "ctdsp") {
// using namespace ctdsp;
// constexpr auto boxcar = window::boxcar<32>();
// constexpr auto normalized = ctdsp::normalize(boxcar, by_value{5.0});
// constexpr auto normalized_value = 1. / 5.0;
// REQUIRE(all_equal_to(normalized, normalized_value));
// constexpr auto max_normalized = normalize(boxcar, by_max{});
// REQUIRE(all_equal_to(max_normalized, 1.0));
//[[maybe_unused]] constexpr auto rms_normalized = normalize(boxcar, by_rms{});
//}
