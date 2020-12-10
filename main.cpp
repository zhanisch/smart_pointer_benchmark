#include <memory>
#include "Dummy.h"
#include "timer.h"

const auto ITEM_NUMBER = 10000;
const auto ITERATION_NUMBER = 100000;

int main(int argc, char *argv[])
{
    // Benchmark of stack access
    {
        Dummy dummyArray[ITEM_NUMBER];
        const auto ti = now();
        for (int itr = 0; itr < ITERATION_NUMBER; ++itr)
        {
            for (auto & elm : dummyArray)
            {
                elm.increase();
            }
        }
        const auto tf = now();
        std::cout << "Stack benchmark\n";
        print_duration(ti, tf, ITERATION_NUMBER);
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
            for (auto & elm : dummyArray)
            {
                elm->increase();
            }
        }
        const auto tf = now();
        std::cout << "Heap benchmark using raw pointer\n";
        print_duration(ti, tf, ITERATION_NUMBER);
        for (auto & elm : dummyArray)
        {
            delete elm;
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
            for (auto & elm : dummyArray)
            {
                elm->increase();
            }
        }
        const auto tf = now();
        std::cout << "Shared pointer benchmark\n";
        print_duration(ti, tf, ITERATION_NUMBER);
    }

    // Benchmark of unique pointer access
    {
        std::unique_ptr<Dummy> dummyArray[ITEM_NUMBER];
        for (int idx = 0; idx < ITEM_NUMBER; ++idx)
        {
            dummyArray[idx] = std::make_unique<Dummy>();
        }

        const auto ti = now();
        for (int itr = 0; itr < ITERATION_NUMBER; ++itr)
        {
            for (auto & elm : dummyArray)
            {
                elm->increase();
            }
        }
        const auto tf = now();
        std::cout << "Unique pointer benchmark\n";
        print_duration(ti, tf, ITERATION_NUMBER);
    }

    return 0;
}

