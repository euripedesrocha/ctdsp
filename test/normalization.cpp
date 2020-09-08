
// TEST_CASE("Window normalization", "ctdsp") {
// using namespace ctdsp;
// constexpr auto boxcar = window::boxcar<32>();
// constexpr auto normalized = ctdsp::normalize(boxcar, by_value{5.0});
// constexpr auto normalized_value = 1. / 5.0;
// REQUIRE(all_equal_to(normalized, normalized_value));
// constexpr auto max_normalized = normalize(boxcar, by_max{});
// REQUIRE(all_equal_to(max_normalized, 1.0));
//[[maybe_unused]] constexpr auto rms_normalized = normalize(boxcar, by_rms{});
//}
