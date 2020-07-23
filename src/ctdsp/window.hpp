#include <cstddef>
#include <ranges>
#include <utility>

#include "array.hpp"

namespace ctdsp::window {

template <size_t length, class Generator, typename T = double>
constexpr auto make(Generator &&generator) {
  constexpr auto from = -(length / 2);
  return std::ranges::views::iota(from) |
         std::ranges::views::transform(std::forward<Generator>(generator)) |
         ctdsp::to_array<length, T>;
}

template <size_t length, typename T = double>
constexpr inline auto boxcar = []() {
  auto generator = []([[maybe_unused]] auto n) { return T{1}; };
  return make<length>(generator);
};

template <size_t length, typename T = double>
constexpr inline auto bartlett = []() {
  auto generator = [](auto n) {
    return T{1} - std::abs((n - (T{length} / T{2})) / (T{length} / T{2}));
  };
  return make<length>(generator);
};
}  // namespace ctdsp::window
