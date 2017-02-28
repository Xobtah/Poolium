# Poolium
This is a wrapping of the std::thread class in order to make it the easiest to use.

### What's the point?
Making C++ threads easy to use.

### How to use it?
Make sure you compile the Thread.cpp file and include the Thread.hpp one.
Once it's done, you can create a thread object:
```markdown
// Default constructor, empty thread
Poolium::Thread	emptyThread;
// Canonical form handled
Poolium::Thread	canonThread(thread);
// Creation of the thread and execution
Poolium::Thread	runningThread([]() { while (42) std::cout << "Hello World!" << std::endl; });
```
When you have a functional thread, you can use this set of functions:
```markdown
template <typename LambdaType>
Thread	 &Set(LambdaType);
// e.g.: thread.Set([](int lol) { if (lol == 42) std::cout << "Wow well done" << std::endl; });

template <typename ...ArgsT>
Thread	 &Run(ArgsT...);
// e.g.: thread.Run(42);

Thead	 &Join();
// Joins the thread

Thread	 &Free();
// Frees the thread
```
The Set() function takes only lambda functions (you can't pass function pointers (but you can call your functions from the lambda ;) ;) )), you can pass any parameters to your lambda as long as when you Run() it, you give the correct parameters, otherwise your code will fail.
Note that they all return a Thread& type, meaning that you can chain them:
```markdown
thread.Set(...).Run(...).Join().Free();
```

std::mutex is also wrapped (compile Mutex.cpp, include Mutex.hpp):
```markdown
Poolium::Mutex	mutex;

mutex.Lock();
mutex.Unlock();
mutex.TryLock(); // Returns a bool (false = failed, true = success)
mutex.Lock().Unlock().TryLock();
```
This was made for integrity, nothing really changed.