# automatically enable catch2 to generate ctest targets
if(CONAN_CATCH2_ROOT_DEBUG)
  include(${CONAN_CATCH2_ROOT_DEBUG}/lib/cmake/Catch2/Catch.cmake)
else()
  include(${CONAN_CATCH2_ROOT}/lib/cmake/Catch2/Catch.cmake)
endif()


add_library(catch_main STATIC catch_main.cpp)
target_link_libraries(catch_main PUBLIC CONAN_PKG::catch2)
target_link_libraries(catch_main PRIVATE project_options)

add_executable(window test_window.cpp)
target_link_libraries(window PRIVATE project_warnings project_options
                                    catch_main ctdsp)

catch_discover_tests(
  window
  TEST_PREFIX
  "window."
  EXTRA_ARGS
  -s
  --reporter=xml
  --out=window.xml)

add_executable(array test_array.cpp)
target_link_libraries(array PRIVATE project_warnings project_options
                                    catch_main ctdsp)

catch_discover_tests(
  array
  TEST_PREFIX
  "array."
  EXTRA_ARGS
  -s
  --reporter=xml
  --out=tests.xml)

# Disable the constexpr portion of the test, and build again this allows us to
# have an executable that we can debug when things go wrong with the constexpr
# testing
#add_executable(relaxed_constexpr_tests constexpr_tests.cpp)
#target_link_libraries(
  #relaxed_constexpr_tests PRIVATE project_options project_warnings
                                  #catch_main)
#target_compile_definitions(
  #relaxed_constexpr_tests PRIVATE
                                  #-DCATCH_CONFIG_RUNTIME_STATIC_REQUIRE)


#catch_discover_tests(
  #relaxed_constexpr_tests
  #TEST_PREFIX
  #"relaxed_constexpr."
  #EXTRA_ARGS
  #-s
  #--reporter=xml
  #--out=relaxed_constexpr.xml)
