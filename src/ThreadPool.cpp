//
// Created by xobtah on 06/02/17.
//

#include <string>
#include <vector>

#include "ThreadPool.hpp"

namespace Poolium
{
    /*
     *  Ctor & Dtor
     */

    ThreadPool::ThreadPool() : _db([](Thread *&t) { t->Free(); }) {}

    ThreadPool::~ThreadPool() {}

    /*
     *  Public member functions
     */

    unsigned int    ThreadPool::Add(void (*funcPtr)()) { return (_db.Insert(new Thread(funcPtr))); }

    Thread          &ThreadPool::Get(unsigned int id)
    try { return (*_db.FindOne(id)); }
    catch (Basium::DataBaseException const &dbe) { throw ThreadPoolException("ThreadPoolException: " + std::string(dbe.what())); }

    IThreadPool     &ThreadPool::Remove(unsigned int id)
    try { _db.Remove(id); return (*this); }
    catch (Basium::DataBaseException const &dbe) { throw ThreadPoolException("ThreadPoolException: " + std::string(dbe.what())); }

    unsigned int    ThreadPool::GetSize() const { return (_db.Size()); }
}