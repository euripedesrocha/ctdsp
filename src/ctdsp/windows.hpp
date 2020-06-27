#pragma once

namespace ctdsp::window {

class boxcar {
 public:
  constexpr auto operator()() const noexcept { return 1; }
};

// template <size_t length, typename T = double>
// constexpr auto boxcar() {
// auto generator = []() { return T{1}; };
// return <length>(generator);
//}

// class bartlett {
// size_t n = 0;

// public:
// constexpr auto operator()(size_t size) noexcept {}
//};

// template <size_t length, typename T = double>
// constexpr auto bartlett() {
// size_t n = 0;
// auto generator = [n, half_length = (T{length} / T{2.0})]() mutable {
// auto const value = 1 - std::abs((n - half_length) / half_length);
//++n;
//};
// return window<length>(generator);
//}
}  // namespace ctdsp::window
