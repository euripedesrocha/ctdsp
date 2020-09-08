#pragma once
#include <cmath>
#include <cstddef>

#include "array.hpp"
namespace ctdsp::especial_functions {
constexpr auto bessel_0rd(double value) { return value; };

}  // namespace ctdsp::especial_functions
namespace ctdsp::filter::design {

struct dB_value {
  double value;
};
auto kaiser_window(auto transition_band, dB_value attenuation) {
  constexpr double beta = [attenuation]() {
    if (attenuation.value > 50) {
      return 0.1102 * (attenuation.value - 8.7);
    }

    if (attenuation.value >= 21 and attenuation.value <= 50) {
      return 0.5842 * std::pow((attenuation.value - 21), 0.4) +
             0.07886 * (attenuation.value - 21);
    }

    return 0.0;
  }();
  constexpr auto M = (attenuation.value - 8) / (2.285 * transition_band);
  constexpr auto I0_beta = ctdsp::especial_functions::bessel_0rd(beta);
}

}  // namespace ctdsp::filter::design
