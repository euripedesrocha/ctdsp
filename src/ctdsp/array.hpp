#pragma once
#include <bits/ranges_algobase.h>

#include <array>
#include <concepts>
#include <cstddef>
#include <utility>

namespace ctdsp {

template <std::size_t length, typename T = double>
class array {
  std::array<T, length> data;

 public:
  using value_type = typename decltype(data)::value_type;
  constexpr auto begin() noexcept { return data.begin(); }
  constexpr auto end() noexcept { return data.end(); }
  constexpr auto cbegin() const noexcept { return data.cbegin(); }
  constexpr auto cend() const noexcept { return data.cend(); }
  constexpr auto size() const noexcept { return data.size(); }
  friend constexpr auto operator|(array const&& arr,
                                  auto&& operation_to_apply) {
    auto cp_arr = std::forward<array>(arr);
    operation_to_apply(cp_arr);

    return cp_arr;
  }
  friend constexpr auto operator|(array&& arr, auto&& operation) {
    operation(arr);
    return arr;
  }
};

namespace detail {
template <std::size_t length, typename T = double>
struct to_array {
  constexpr auto operator()(auto&& r) const {
    array<length, T> arr;
    using std::begin;
    using std::end;
    using R = decltype(r);
    std::ranges::copy_n(begin(std::forward<R>(r)), length, begin(arr));
    return arr;
  }
  template <class R>
  friend constexpr auto operator|(R&& r, to_array self) {
    return self(std::forward<R>(r));
  }
};

}  // namespace detail

template <std::size_t length, typename T = double>
constexpr inline auto to_array = detail::to_array<length, T>{};

}  // namespace ctdsp
