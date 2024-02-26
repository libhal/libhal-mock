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

#include <libhal-mock/adc.hpp>

#include <deque>

#include <boost/ut.hpp>

namespace hal::mock {
void adc_mock_test()
{
  using namespace boost::ut;

  // Setup
  auto expected1 = 0.25f;
  auto expected2 = 0.5f;
  auto expected3 = 1.0f;
  hal::mock::adc mock;
  std::deque percentages{ expected1, expected2, expected3 };
  std::queue queue(percentages);

  // Exercise
  mock.set(queue);
  auto result1 = mock.read();
  auto result2 = mock.read();
  auto result3 = mock.read();

  // Verify
  expect(that % expected1 == result1);
  expect(that % expected2 == result2);
  expect(that % expected3 == result3);
};
}  // namespace hal::mock
