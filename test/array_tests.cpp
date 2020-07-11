#include <catch2/catch.hpp>
#include <ranges>
#include <type_traits>

#include "ctdsp/array.hpp"

template <class Data>
bool all_equal(Data& data) {
  return std::adjacent_find(data.cbegin(), data.cend(), std::not_equal_to{}) ==
         data.cend();
}

TEST_CASE("The user constructs the array and transform it", "[array]") {
  constexpr auto N = 32;
  constexpr auto arr =
      ctdsp::array<N>{} | [](auto& input) { std::ranges::fill(input, 1.); };
  STATIC_REQUIRE(std::is_same_v<decltype(arr), const ctdsp::array<N, double>>);
  REQUIRE(all_equal(arr));
}

TEST_CASE("The user generate the array from a view", "[array]") {
  constexpr auto N = 32;
  constexpr auto arr =
      std::ranges::views::iota(-(N / 2)) |
      std::ranges::views::transform([](auto n) { return n * n; }) |
      ctdsp::to_array<N>;
  STATIC_REQUIRE(std::is_same_v<decltype(arr), const ctdsp::array<N, double>>);
}
