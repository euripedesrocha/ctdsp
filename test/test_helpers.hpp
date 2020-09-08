#pragma once
#include <algorithm>

namespace test {

template <class Data>
bool all_equal(Data& data) {
  return std::adjacent_find(data.cbegin(), data.cend(), std::not_equal_to{}) ==
         data.cend();
}
// template <class Data>
// bool all_equal_to(Data& data, double value) {
// auto target = Approx(value).epsilon(0.001);
// return std::all_of(data.cbegin(), data.cend(),
//[target](double item) { return item == target; });
//}
}  // namespace test
