#ifndef __MEASURE_TIME_d5beb26b0b3d496fa5f2926a3d01118a
#define __MEASURE_TIME_d5beb26b0b3d496fa5f2926a3d01118a

#include <chrono>
#include <iostream>

using Duration = std::chrono::nanoseconds;

template<typename Task>
Duration MeasureRuntime(Task task)
{
    auto t0 = std::chrono::high_resolution_clock::now();
    task();
    auto t1 = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0);
}

void PrintDuration(std::ostream& os, Duration d)
{
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(d).count();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(d).count();
    auto ns = d.count();
    if (ms > 1)
    {
        os << ms << " ms";
    }
    else if (us > 1)
    {
        os << us << " us";
    }
    else
    {
        os << ns << " ns";
    }
}

#endif
