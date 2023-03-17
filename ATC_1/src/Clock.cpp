#include "Clock.h"

Clock::Clock() {
	// TODO Auto-generated constructor stub

}

Clock::~Clock() {
	// TODO Auto-generated destructor stub
}


void Clock::start() {
    m_running = true;
    m_startTime = std::chrono::steady_clock::now();
    m_thread = std::thread(&Clock::run, this);
}

void Clock::stop() {
    m_running = false;
    if (m_thread.joinable()) {
        m_thread.join();
    }
}

void Clock::run() {
    while (m_running) {
        auto elapsed = std::chrono::steady_clock::now() - m_startTime;
        std::cout << "\nTime elapsed: " << std::chrono::duration_cast<std::chrono::seconds>(elapsed).count() << " seconds" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
