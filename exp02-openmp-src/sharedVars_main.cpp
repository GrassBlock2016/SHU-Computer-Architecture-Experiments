#include "TimeCounter.hpp"
#include <format>
#include <iostream>
#include <omp.h>

template <typename T>
concept Addable = requires(T a, T b) {
    {
        a + b
    } -> std::convertible_to<T>;
};

enum class ExecutionPolicy
{
    seq,
    par,
    atomic,
    critical,
    par_reduce,
};

template <typename T, ExecutionPolicy policy>
    requires Addable<T>
T accumulate(const T& start, const T& end)
{
    T sum = 0;
    if constexpr (ExecutionPolicy::seq == policy) {
        for (T i = start; i < end; ++i) {
            sum += i;
        }
    } else if constexpr (ExecutionPolicy::par == policy) {
#pragma omp parallel for
        for (T i = start; i < end; ++i) {
            sum += i;
        }
    } else if constexpr (ExecutionPolicy::atomic == policy) {
#pragma omp parallel for
        for (T i = start; i < end; ++i) {
#pragma omp atomic
            sum += i;
        }
    } else if constexpr (ExecutionPolicy::critical == policy) {
#pragma omp parallel for
        for (T i = start; i < end; ++i) {
#pragma omp critical
            {
                sum += i;
            }
        }
    } else if constexpr (ExecutionPolicy::par_reduce == policy) {
#pragma omp parallel for reduction(+ : sum)
        for (T i = start; i < end; ++i) {
            sum += i;
        }
    }
    return sum;
}

int main()
{
    TimeCounter timeCounter;
    constexpr int n = std::numeric_limits<int>::max() >> 3;

    auto accRatio = [](auto&& originTime, auto&& targetTime) -> double {
        return static_cast<double>(originTime) / targetTime;
    };

    // Serial.
    timeCounter.init();
    timeCounter.startCounting();
    int sum = accumulate<int, ExecutionPolicy::seq>(0, n);
    timeCounter.endCounting();
    std::cout << std::format("Serial:          {:>5} ms, sum = {}\n", timeCounter.msecond(), sum);
    auto serialTime = timeCounter.msecond();

    // OpenMP.
    timeCounter.init();
    timeCounter.startCounting();
    sum = accumulate<int, ExecutionPolicy::par>(0, n);
    timeCounter.endCounting();
    std::cout << std::format("OpenMP:          {:>5} ms, sum = {}\n", timeCounter.msecond(), sum);
    std::cout << std::format("Speedup:         {:>5.3e}\n",
                             accRatio(serialTime, timeCounter.msecond()));

    // OpenMP atomic.
    timeCounter.init();
    timeCounter.startCounting();
    sum = accumulate<int, ExecutionPolicy::atomic>(0, n);
    timeCounter.endCounting();
    std::cout << std::format("OpenMP atomic:   {:>5} ms, sum = {}\n", timeCounter.msecond(), sum);
    std::cout << std::format("Speedup:         {:>5.3e}\n",
                             accRatio(serialTime, timeCounter.msecond()));

    // OpenMP critical.
    timeCounter.init();
    timeCounter.startCounting();
    sum = accumulate<int, ExecutionPolicy::critical>(0, n);
    timeCounter.endCounting();
    std::cout << std::format("OpenMP critical: {:>5} ms, sum = {}\n", timeCounter.msecond(), sum);
    std::cout << std::format("Speedup:         {:>5.3e}\n",
                             accRatio(serialTime, timeCounter.msecond()));

    // OpenMP reduce.
    timeCounter.init();
    timeCounter.startCounting();
    sum = accumulate<int, ExecutionPolicy::par_reduce>(0, n);
    timeCounter.endCounting();
    std::cout << std::format("OpenMP reduce:   {:>5} ms, sum = {}\n", timeCounter.msecond(), sum);
    std::cout << std::format("Speedup:         {:>5.3e}\n",
                             accRatio(serialTime, timeCounter.msecond()));

    return 0;
}