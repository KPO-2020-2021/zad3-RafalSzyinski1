#include <iostream>
#include "GNUPlot.h"
#include "Transform.h"

#include <atomic>
#include <thread>
#include <chrono>

//TODO menu
std::atomic<bool> wait;

void waiting()
{
    std::cin.get();
    wait.store(true);
}


int main()
{
    GNUPlot plot;
    Rectangle<double> a(0, 0, 1, 0, 1, 1, 0, 1);
    Transform t1;
    t1.rotate(1);

    wait.store(false);
    std::thread t(waiting);
    while(true)
    {
        t1.transform(a);
        plot.draw(a);
        for (int i = 0; i < 4; ++i)
            t1.transform(a[i]);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        if (wait.load())
            break;
    }
    t.join();
}