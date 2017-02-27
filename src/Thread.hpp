//
// Created by xobtah on 06/02/17.
//

#ifndef POOLIUM_THREAD_HPP
#define POOLIUM_THREAD_HPP

#include <thread>
#include <functional>

namespace Poolium
{
    class Thread
    {
    public:
        Thread();
        ~Thread();

        Thread  &Free();
        Thread  &Join();

        template <typename ...ArgsT>
        Thread  &Run(ArgsT ...args)
        {
            _thread = new std::thread(reinterpret_cast<Listener<ArgsT...>*>(_func.get())->cb, args...);
            return (*this);
        }

        template <typename... Args>
        Thread  &Set(std::function<void (Args...)> cb)
        {
            _func = std::make_shared<Listener<Args...>>(cb);
            return (*this);
        }

        template<typename LambdaType>
        Thread  &Set(LambdaType lambda)
        { return (this->Set(make_function(lambda))); }

    private:
        std::thread *_thread;

        struct ListenerBase
        {
            ListenerBase() {}
            virtual ~ListenerBase() {}
        };

        template <typename... Args>
        struct Listener : public ListenerBase
        {
            Listener() {}
            Listener(std::function<void (Args...)> c) : cb(c) {}

            std::function<void (Args...)> cb;
        };

        template <typename T>
        struct function_traits : public function_traits<decltype(&T::operator())> {};

        template <typename ClassType, typename ReturnType, typename... Args>
        struct function_traits<ReturnType(ClassType::*)(Args...) const>
        { typedef std::function<ReturnType (Args...)> f_type; };

        template <typename L>
        typename function_traits<L>::f_type make_function(L l)
        { return ((typename function_traits<L>::f_type)(l)); }

        std::shared_ptr<ListenerBase>   _func;
    };
}

#endif //POOLIUM_THREAD_HPP
