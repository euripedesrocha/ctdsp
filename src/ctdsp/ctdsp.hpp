#pragma once

#include <algorithm>
#include <cmath>
#include <concepts>
#include <numeric>

namespace ctdsp {

template <class Data, typename T = typename Data::value_type>
constexpr auto norm(Data const& data) {
  return static_cast<T>(std::sqrt(
      std::inner_product(data.cbegin(), data.cend(), data.cbegin(), T{0})));
}

constexpr auto normalize(auto data,
                         std::invocable<decltype(data)> auto calculate_factor) {
  auto const factor = calculate_factor(data);
  std::transform(data.begin(), data.end(), data.begin(),
                 [factor](auto item) { return item / factor; });
  return data;
}

struct by_value {
  double value;
  constexpr auto operator()([[maybe_unused]] auto const& data) const noexcept {
    return value;
  }
};

struct by_max {
  constexpr auto operator()(auto const& data) noexcept {
    return *std::max_element(data.cbegin(), data.cend());
  }
};

struct by_rms {
  constexpr auto operator()(auto const& data) noexcept {
    // using T = typename decltype(data)::value_type;
    return norm(data) / std::sqrt(data.size());
  }
};

}  // namespace ctdsp
