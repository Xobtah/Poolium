//
// Created by xobtah on 06/02/17.
//

#include <iostream>

#include "../src/Thread.hpp"
#include "../src/Mutex.hpp"
#include "../src/ThreadPool.hpp"

void testFunc(int lol, char ptdr) { std::cout << lol << ptdr << std::endl; }

int main()
{
    Poolium::Thread thread;
    Poolium::Mutex  mutex;

    std::cout << "Mutex lock status: " << mutex.TryLock() << std::endl;
    std::cout << "Mutex lock status: " << mutex.TryLock() << std::endl;
    mutex.Unlock();
    std::cout << "Mutex lock status: " << mutex.TryLock() << std::endl;
    mutex.Unlock().Lock();
    std::cout << "Mutex lock status: " << mutex.TryLock() << std::endl;

    // Using pointers to function does not work yet
    //thread.Set(testFunc).Run(42, 'c').Join().Free();

    thread.Set([]() { std::cout << "It's working!!" << std::endl; }).Run().Join();
    thread.Set([](int first, char second) { std::cout << first << second << std::endl; }).Run(42, 'c').Join().Free();
    return (0);
}