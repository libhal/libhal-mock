// Copyright 2024 Khalil Estell
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <libhal-mock/steady_clock.hpp>

#include <deque>

#include <boost/ut.hpp>

namespace hal::mock {
void steady_clock_mock_test()
{
  using namespace boost::ut;

  // Setup
  std::uint64_t expected1 = 10;
  std::uint64_t expected2 = 50;
  std::uint64_t expected3 = 100;
  auto expected_frequency = 1.0_Hz;
  hal::mock::steady_clock mock;
  std::deque uptimes{ expected1, expected2, expected3 };
  std::queue queue(uptimes);

  // Exercise
  mock.set_frequency(expected_frequency);
  mock.set_uptimes(queue);
  auto result0 = mock.frequency();
  auto result1 = mock.uptime();
  auto result2 = mock.uptime();
  auto result3 = mock.uptime();

  // Verify
  expect(that % expected_frequency == result0);
  expect(that % expected1 == result1);
  expect(that % expected2 == result2);
  expect(that % expected3 == result3);
};
}  // namespace hal::mock
