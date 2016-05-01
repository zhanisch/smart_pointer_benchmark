#include <memory>
#include "Dummy.h"
#include <QTime>
#include <QDebug>

const int ITEM_NUMBER = 1000000;
const int ITERATION_NUMBER = 1000;

int main(int argc, char *argv[])
{
    // Benchmark of stack access
    {
        Dummy dummyArray[ITEM_NUMBER];
        QTime time;
        int elaspedTime = 0;

        time.start();
        for (int itr = 0; itr < ITERATION_NUMBER; ++itr)
        {
            for (int idx = 0; idx < ITEM_NUMBER; ++idx)
            {
                dummyArray[idx].increase();
            }
        }
        elaspedTime = time.elapsed();

        qDebug() << "Stack benchmark";
        qDebug() << "Elasped time in ms: " << elaspedTime;
    }

    // Benchmark of heap access
    {
        Dummy *dummyArray[ITEM_NUMBER];

        for (int idx = 0; idx < ITEM_NUMBER; ++idx)
        {
            dummyArray[idx] = new Dummy;
        }

        QTime time;
        int elaspedTime = 0;

        time.start();
        for (int itr = 0; itr < ITERATION_NUMBER; ++itr)
        {
            for (int idx = 0; idx < ITEM_NUMBER; ++idx)
            {
                dummyArray[idx]->increase();
            }
        }
        elaspedTime = time.elapsed();

        qDebug() << "Heap benchmark";
        qDebug() << "Elasped time in ms: " << elaspedTime;
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

        QTime time;
        int elaspedTime = 0;

        time.start();
        for (int itr = 0; itr < ITERATION_NUMBER; ++itr)
        {
            for (int idx = 0; idx < ITEM_NUMBER; ++idx)
            {
                dummyArray[idx]->increase();
            }
        }
        elaspedTime = time.elapsed();

        qDebug() << "Shared pointer benchmark";
        qDebug() << "Elasped time in ms: " << elaspedTime;
    }

    // Benchmark of unique pointer access
    {
        std::unique_ptr<Dummy> dummyArray[ITEM_NUMBER];
        for (int idx = 0; idx < ITEM_NUMBER; ++idx)
        {
            dummyArray[idx].reset(new Dummy);
        }

        QTime time;
        int elaspedTime = 0;

        time.start();
        for (int itr = 0; itr < ITERATION_NUMBER; ++itr)
        {
            for (int idx = 0; idx < ITEM_NUMBER; ++idx)
            {
                dummyArray[idx]->increase();
            }
        }
        elaspedTime = time.elapsed();

        qDebug() << "Unique pointer benchmark";
        qDebug() << "Elasped time in ms: " << elaspedTime;
    }

    return 0;
}

