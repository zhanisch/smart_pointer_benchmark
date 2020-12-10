#include <memory>
#include "Dummy.h"
#include "timer.h"

const int ITEM_NUMBER = 1000000;
const int ITERATION_NUMBER = 1000;

int main(int argc, char *argv[])
{
    // Benchmark of stack access
    {
        Dummy dummyArray[ITEM_NUMBER];
        const auto ti = now();
        for (int itr = 0; itr < ITERATION_NUMBER; ++itr)
        {
            for (int idx = 0; idx < ITEM_NUMBER; ++idx)
            {
                dummyArray[idx].increase();
            }
        }
        const auto tf = now();
        std::cout << "Stack benchmark\n";
        print_duration(ti, tf);
    }

    // Benchmark of heap access
    {
        Dummy *dummyArray[ITEM_NUMBER];

        for (int idx = 0; idx < ITEM_NUMBER; ++idx)
        {
            dummyArray[idx] = new Dummy;
        }

        const auto ti = now();
        for (int itr = 0; itr < ITERATION_NUMBER; ++itr)
        {
            for (int idx = 0; idx < ITEM_NUMBER; ++idx)
            {
                dummyArray[idx]->increase();
            }
        }
        const auto tf = now();
        std::cout << "Heap benchmark\n";
        print_duration(ti, tf);
        for (int idx = 0; idx < ITEM_NUMBER; ++idx)
        {
            delete dummyArray[idx];
        }
    }



    // Benchmark of shared pointer access
    {

        std::shared_ptr<Dummy> dummyArray[ITEM_NUMBER];
        for (int idx = 0; idx < ITEM_NUMBER; ++idx)
        {
            dummyArray[idx] = std::make_shared<Dummy>();
        }

        const auto ti = now();
        for (int itr = 0; itr < ITERATION_NUMBER; ++itr)
        {
            for (int idx = 0; idx < ITEM_NUMBER; ++idx)
            {
                dummyArray[idx]->increase();
            }
        }
        const auto tf = now();
        std::cout << "Shared pointer benchmark\n";
        print_duration(ti, tf);
    }

    // Benchmark of unique pointer access
    {
        std::unique_ptr<Dummy> dummyArray[ITEM_NUMBER];
        for (int idx = 0; idx < ITEM_NUMBER; ++idx)
        {
            dummyArray[idx].reset(new Dummy);
        }

        const auto ti = now();
        for (int itr = 0; itr < ITERATION_NUMBER; ++itr)
        {
            for (int idx = 0; idx < ITEM_NUMBER; ++idx)
            {
                dummyArray[idx]->increase();
            }
        }
        const auto tf = now();
        std::cout << "Unique pointer benchmark\n";
        print_duration(ti, tf);
    }

    return 0;
}

