#pragma once
template<typename T>
class MySmartPointer{
public:
    MySmartPointer(T*ptr): ptr(ptr) {}
    ~MySmartPointer(){delete ptr;}
    T &operator*(){return *ptr;}
    T *operator->(){return ptr;}
private:
    T *ptr;
};