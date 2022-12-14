// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
//
// Created by User on 7/17/2022.
//

#include "Timer.hpp"

Timer::Timer(std::chrono::milliseconds interval)
: interval(interval)
{

}
bool Timer::isIntervalExpired() const {
    return now() - lastCheck > interval;
}
void Timer::reset() {
    lastCheck = now();
}
bool Timer::isExpiredAndReset() {
    if(isIntervalExpired()) {
        reset();
        return true;
    }
    return false;
}
std::chrono::milliseconds Timer::getInterval() const {
    return interval;
}
