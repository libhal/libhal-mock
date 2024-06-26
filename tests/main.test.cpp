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

namespace hal::mock {
extern void adc_mock_test();
extern void can_mock_test();
extern void dac_mock_test();
extern void input_pin_mock_test();
extern void interrupt_pin_mock_test();
extern void motor_mock_test();
extern void output_pin_mock_test();
extern void pwm_mock_test();
extern void spi_mock_test();
extern void steady_clock_mock_test();
extern void testing_utilities_test();
extern void timer_mock_test();
extern void servo_mock_test();
}  // namespace hal::mock

int main()
{
  hal::mock::adc_mock_test();
  hal::mock::can_mock_test();
  hal::mock::dac_mock_test();
  hal::mock::input_pin_mock_test();
  hal::mock::interrupt_pin_mock_test();
  hal::mock::motor_mock_test();
  hal::mock::output_pin_mock_test();
  hal::mock::pwm_mock_test();
  hal::mock::spi_mock_test();
  hal::mock::steady_clock_mock_test();
  hal::mock::testing_utilities_test();
  hal::mock::timer_mock_test();
  hal::mock::servo_mock_test();
}
