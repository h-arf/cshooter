#include <thread>
#include <chrono>
extern "C" void sleep_for(long milli){
    std::this_thread::sleep_for(std::chrono::milliseconds(milli));
}