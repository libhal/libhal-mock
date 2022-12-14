#include <libhal-mock/timer.hpp>

#include <boost/ut.hpp>

namespace hal::mock {
void timer_mock_test()
{
  using namespace boost::ut;

  // Setup
  hal::mock::timer mock;
  bool callback_stored_successfully = false;
  const hal::callback<void(void)> expected_callback =
    [&callback_stored_successfully]() { callback_stored_successfully = true; };
  const std::chrono::nanoseconds expected_delay = {};

  // Exercise + Verify
  expect(false == mock.is_running().value());
  expect(true == std::get<0>(mock.spy_is_running.call_history().at(0)));
  expect(bool{ mock.schedule(expected_callback, expected_delay) });
  expect(bool{ std::get<0>(mock.spy_schedule.call_history().at(0)) });
  expect(expected_delay == std::get<1>(mock.spy_schedule.call_history().at(0)));
  expect(true == mock.is_running().value());
  expect(true == std::get<0>(mock.spy_is_running.call_history().at(1)));
  expect(bool{ mock.cancel() });
  expect(true == std::get<0>(mock.spy_cancel.call_history().at(0)));
};
}  // namespace hal::mock
