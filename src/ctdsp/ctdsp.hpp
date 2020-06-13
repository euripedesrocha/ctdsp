#pragma once

#include <algorithm>

namespace ctdsp {

template <class Data>
struct by_max {
  auto operator()(Data const& /*data*/) { return 1.0; }
};

template <class Data>
struct by_rms {
  auto operator()(Data const& /*data*/) { return 1.0; }
};

template <class Data, typename T = Data::value_type>
constexpr auto normalize(Data data, T factor) {
  std::transform(data.begin(), data.end(), data.begin(),
                 [factor](T item) { return item / factor; });
  return data;
}

template <typename Container, typename Calculator>
concept FactorCalculator =
    std::invocable<Calculator, typename Container::value_type>;

template <class Data, FactorCalculator<Data> Calculator>
constexpr auto normalize(Data data, Calculator calculate_factor) {
  auto const factor = calculate_factor(data);
  normalize(data, factor);
}
}  // namespace ctdsp
