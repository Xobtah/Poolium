//
// Created by xobtah on 06/02/17.
//

#include <iostream>

#include "src/Thread.hpp"
#include "src/Mutex.hpp"
#include "src/IThreadRunner.hpp"

class   Test : public Poolium::IThreadRunner
{
public:
    Test() {}
    ~Test() {}

    void    ThreadRunner() { std::cout << "Hello World!" << std::endl; }
};

int main()
{
    Poolium::Thread thread;
    Test            test;
    Poolium::Mutex  mutex;

    std::cout << "Mutex lock status: " << mutex.TryLock() << std::endl;
    std::cout << "Mutex lock status: " << mutex.TryLock() << std::endl;
    mutex.Unlock();
    std::cout << "Mutex lock status: " << mutex.TryLock() << std::endl;
    mutex.Unlock().Lock();
    std::cout << "Mutex lock status: " << mutex.TryLock() << std::endl;
    thread.Free().Run(test).Join();
    return (0);
}