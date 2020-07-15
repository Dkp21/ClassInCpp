#include <iostream>

struct A
{
    int data[2];

    A(int x, int y) : data{x, y} {}
#ifdef VPTR_MEMORY
    /* 
     * Virtual memober function will create a vptr
     * It will hold 4 byts of memory in 32 bit system
     * and 8 bytes in 64 bit system
     *
     */
    virtual void f() {}
#else
    /*
     * In this case memory will not be allocated for vptr
     * as there is no virtual function within a struct
     *
     */
    void f() {}
#endif
};

int main(int argc, char **argv)
{
    A a(22, 33);

    int *arr = (int *) &a;

    std::cout << "size of struct A - " << sizeof(A) << std::endl;

    /*
     * Following line could lead to segementation fault
     * or undefined behaviour if VPTR_MEMORY flag is not
     * specified at compile time
     *
     */
#ifdef VPTR_MEMORY
    std::cout << "arr[2] with VPTR_MEMORY flag - " << arr[2] << std::endl;
#else
    /*
     * Program may crash
     */
    std::cout << "arr[2] without VPTR_MEMORY flag (undefined) - " << arr[2] << std::endl;
#endif

    return 0;
}
