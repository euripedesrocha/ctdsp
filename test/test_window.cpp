#include <algorithm>
#include <catch2/catch.hpp>
#include <functional>
#include <iterator>
#include <numeric>

#include "ctdsp/window.hpp"
#include "test_helpers.hpp"

TEST_CASE("A directly created Boxcar window") {
  constexpr auto boxcar = ctdsp::window::boxcar<3>();
  REQUIRE(test::all_equal(boxcar));
}

TEST_CASE("A directly created Bartlett window") {}
TEST_CASE("Custom window creation using ctdsp::make") {
  [[maybe_unused]] constexpr auto squared =
      ctdsp::window::make<16>([](double n) { return n * n; });
}

