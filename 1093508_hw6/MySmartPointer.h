#pragma once
template<typename T>
class MySmartPointer{
public:
    MySmartPointer(T*p): ptr(p){};
    ~MySmartPointer(){delete ptr;};
    T &operator*(){return *ptr;};
    T *operator->(){return ptr;};
private:
    T *ptr;
};