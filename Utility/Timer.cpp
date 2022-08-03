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
bool Timer::IsIntervalExpired() const {
    return now() - lastCheck > interval;
}
void Timer::Reset() {
    lastCheck = now();
}
bool Timer::isExpiredAndReset() {
    if(IsIntervalExpired()) {
        Reset();
        return true;
    }
    return false;
}
std::chrono::milliseconds Timer::getInterval() const {
    return interval;
}
