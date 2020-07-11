#include <bits/c++config.h>

#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdlib>
#include <iterator>

namespace ctdsp::window {

template <std::size_t length>
class window {
  std::array<double, length> data{};
  bool symmetric = false;
  double correction_factor = 1.0;

 public:
  using value_type = typename decltype(data)::value_type;
  template <class Generator>
  consteval window(Generator generator) {
    std::generate(data.begin(), data.end(), generator);
  }
  constexpr auto begin() noexcept { return data.begin(); }
  constexpr auto end() noexcept { return data.end(); }
  constexpr auto cbegin() const noexcept { return data.cbegin(); }
  constexpr auto cend() const noexcept { return data.cend(); }
  constexpr auto size() const noexcept { return data.size(); }
};

template <size_t length, typename T = double>
constexpr auto boxcar() {
  auto generator = []() { return T{1}; };
  return window<length>(generator);
}

template <size_t length, typename T = double>
constexpr auto bartlett() {
  size_t n = 0;
  auto generator = [n, half_length = (T{length} / T{2.0})]() mutable {
    auto const value = 1 - std::abs((n - half_length) / half_length);
    ++n;
  };
  return window<length>(generator);
}
}  // namespace ctdsp::window