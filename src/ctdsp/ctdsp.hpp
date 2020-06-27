#pragma once

#include <algorithm>
#include <array>
#include <cmath>
#include <concepts>
#include <numeric>
#include <type_traits>

namespace ctdsp {

template <typename T, size_t length>
struct array {
  std::array<T, length> data;

  template <size_t size, typename Generator, typename... GenArgs>
  constexpr array([[maybe_unused]] std::integral_constant<size_t, size> s,
                  Generator generator, GenArgs... Args) {
    auto gen = [generator, Args...]() { return generator(Args...); };
    std::generate(data.begin(), data.end(), gen);
  }
};

template <size_t size, typename Generator, typename... GenArgs>
array(std::integral_constant<size_t, size> s, Generator generator,
      GenArgs... Args) -> array<std::invoke_result_t<Generator, GenArgs...>, s>;

template <size_t size, typename Generator, typename... GenArgs>
constexpr auto make_array(
    [[maybe_unused]] std::integral_constant<size_t, size> s,
    Generator generator, GenArgs... Args) {
  constexpr auto arr = array(s, generator, Args...);
  return arr.get();
}
// template <size_t size, typename Generator, typename... GenArgs>
// constexpr auto make_array(Generator generator, GenArgs... Args) {
// std::array<std::invoke_result_t<Generator, GenArgs...>, size> data;
// auto gen = [generator, Args...]() { return generator(Args...); };
// std::generate(data.begin(), data.end(), gen);
// return data;
//}

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
