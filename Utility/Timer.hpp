//
// Created by User on 7/17/2022.
//

#ifndef TESTGAME_TIMER_HPP
#define TESTGAME_TIMER_HPP

#include <chrono>
#include "EventDispatcher.hpp"

using namespace std::chrono_literals;

using hclock = std::chrono::steady_clock;

class Timer {
  public:
    Timer(std::chrono::milliseconds interval);
    
    bool IsIntervalExpired() const;
    
    void Reset();
    
    bool isExpiredAndReset();
    
    std::chrono::milliseconds getInterval() const;
  
  private:
    std::chrono::milliseconds interval;
    std::chrono::time_point<hclock, std::chrono::nanoseconds> lastCheck;
    static auto constexpr now = hclock::now;
};


#endif // TESTGAME_TIMER_HPP
