// chrono helpers

#include <chrono>
#include <iostream>

using namespace std::chrono;
auto now() {
    return high_resolution_clock::now();
}

auto to_ms(const time_point<high_resolution_clock> ti, const time_point<high_resolution_clock> tf) {
    return duration_cast<milliseconds>(tf-ti).count();
}

auto to_us(const time_point<high_resolution_clock> ti, const time_point<high_resolution_clock> tf) {
    return duration_cast<microseconds>(tf-ti).count();
}

auto print_duration(const time_point<high_resolution_clock> ti, const time_point<high_resolution_clock> tf, const int iterations_number = 1) {
    std::cout
        << "Elasped time: "
        << to_us(ti, tf)
        << " us\n";
}