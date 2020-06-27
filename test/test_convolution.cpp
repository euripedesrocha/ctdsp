#include <catch2/catch.hpp>

#include "ctdsp.hpp"
#include "windows.hpp"

SCENARIO("A time domain kernel applied to data of the same size",
         "[convolution]") {
  GIVEN("A compile time defined kernel") {
    constexpr auto comp_kernel = ctdsp::window::bartlett<32>();
  }
  REQUIRE(true);
}
SCENARIO("A time domain kernel applied to data of arbitrary size",
         "[convolution]") {}
SCENARIO("A time domain kernel applied to empty data", "[convolution]") {}
