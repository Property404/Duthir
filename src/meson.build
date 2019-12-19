project('Duthir', ['cpp'], default_options : ['cpp_std=c++17'])
add_project_link_arguments(['-lgmpxx','-lgmp'], language: 'cpp')
test_includes = include_directories('Catch2/single_include/catch2')

add_global_arguments('-fmax-errors=1', language:'cpp')
add_global_arguments('-Werror', language:'cpp')

common_sources = ['primatives.cpp', 'RSA.cpp']

release_sources = common_sources + ['main.cpp']

test_sources = common_sources + ['tests/main.cpp','tests/primatives.cpp']

executable('duthir', release_sources)

unit_tests_executable = executable('unit_tests', test_sources, include_directories: test_includes)

test('unit_tests', unit_tests_executable)
