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

#include <libhal-util/input_pin.hpp>

#include <deque>

#include <libhal-mock/input_pin.hpp>

#include <boost/ut.hpp>
#include <libhal/error.hpp>

namespace hal::mock {
void input_pin_mock_test()
{
  using namespace boost::ut;

  "hal::mock::input_pin::configure()"_test = []() {
    // Setup
    constexpr hal::input_pin::settings mock_settings_default{};
    constexpr hal::input_pin::settings mock_settings_custom{
      .resistor = pin_resistor::pull_down,
    };
    hal::mock::input_pin mock;

    // Exercise
    mock.configure(mock_settings_default);
    mock.configure(mock_settings_custom);

    // Verify
    expect(mock_settings_default ==
           std::get<0>(mock.spy_configure.call_history().at(0)));
    expect(mock_settings_custom ==
           std::get<0>(mock.spy_configure.call_history().at(1)));
  };
  "hal::mock::input_pin::set() + level()"_test = []() {
    // Setup
    hal::mock::input_pin mock;
    std::deque inputs{
      true,
      false,
      true,
    };
    std::queue queue(inputs);

    // Exercise
    mock.set(queue);

    // Verify
    expect(that % true == mock.level());
    expect(that % false == mock.level());
    expect(that % true == mock.level());
    expect(throws<hal::operation_not_permitted>(
      [&]() { [[maybe_unused]] auto level = mock.level(); }));
  };
  "hal::mock::input_pin::reset()"_test = []() {
    // Setup
    constexpr hal::input_pin::settings mock_settings_default{};
    hal::mock::input_pin mock;
    mock.configure(mock_settings_default);
    expect(that % 1 == mock.spy_configure.call_history().size());

    // Exercise
    mock.reset();

    // Verify
    expect(that % 0 == mock.spy_configure.call_history().size());
  };
};
}  // namespace hal::mock
