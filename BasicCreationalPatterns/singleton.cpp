#include <iostream>
//==========
//Example 1:
//Heap allocated the SingletonHeap(the SingletonHeap object lives on heap)

//Pros:

//  -Allows more control over the object's lifetime, as you can create and destroy it dynamically when needed.
//  -Can be more flexible in scenarios where the object's lifetime is not tied to the program's lifetime.
//  -More suitable for large objects or objects with significant resource requirements, as you can free the memory when the object is no longer needed.

//Cons:

//  -Introduces the overhead of dynamic memory allocation and deallocation, which can impact performance.
//  -Increases the risk of memory leaks if not managed properly.

class SingletonHeap {
private:
    static SingletonHeap* instance;

    // Private constructor to prevent direct instantiation.
    SingletonHeap() {}

public:
    static SingletonHeap* getInstance() {
        if (instance == nullptr) {
            instance = new SingletonHeap();
        }
        return instance;
    }

    void showMessage() {
        std::cout << "Hello, I am the SingletonHeap instance!" << std::endl;
    }
};


//===============================================================================================
//===============================================================================================
//===============================================================================================

//Example 2 
//Stack living singleton (Object in Stack):

//Pros:

//  -Avoids the overhead of dynamic memory allocation (heap allocation) and deallocation.
//  -Guarantees that there is only one instance of the object throughout the program's lifetime.
//  -Avoids potential memory leaks, as there is no need to deallocate memory explicitly.
//  -Typically faster and more efficient due to stack allocation.

//Cons:

//  -The object is created at program startup and persists until program termination, which might not be desirable if the object is not always needed.
//  -If the singleton object is large and resource-intensive, it might lead to increased memory consumption during the entire program's runtime.
//  -Not suitable for scenarios where the object's lifetime needs to be controlled dynamically (e.g., if you need to destroy and recreate the object multiple times during runtime).


#include <iostream>

class SingletonStack {
private:
    static SingletonStack instance;

    // Private constructor to prevent direct instantiation.
    SingletonStack() {}

public:
    // Delete copy constructor and copy assignment operator
    SingletonStack(const SingletonStack&) = delete;
    SingletonStack& operator=(const SingletonStack&) = delete;

    static SingletonStack& getInstance() {
        return instance;
    }

    void showMessage() {
        std::cout << "Hello, I am the SingletonStack instance!" << std::endl;
    }
};



//======================== try them below =============================================

// Static member initialization of stack living singleton.
SingletonStack SingletonStack::instance;

// Static member initialization.
SingletonHeap* SingletonHeap::instance = nullptr;

int main() {
    // Get the SingletonHeap instance.
    SingletonHeap* SingletonHeapInstance1 = SingletonHeap::getInstance();
    SingletonHeapInstance1->showMessage();

    // Try to copy the SingletonHeap instance (will not compile due to deleted copy constructor).
    // SingletonHeap* SingletonHeapInstance2 = SingletonHeapInstance1; // The objects point to one instance for sure !! 


    // Get the Singleton instance on stack.
    SingletonStack& singletonStackInstance1 = SingletonStack::getInstance();
    singletonStackInstance1.showMessage();

    // Try to copy the Singleton instance (will not compile due to deleted copy constructor).
    // Singleton singletonInstance2 = singletonInstance1; // Error: use of deleted function

    return 0;
}




