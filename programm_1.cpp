#include <iostream>

int main(int argc, char * argv[])
{
    int size {0};
    std::cout << "Input array size ";
    std::cin >> size;

    if(size < 0)
    {
        std::cout << "Value is not correct.\n";
        return 0;
    }

    int * array = new int[size];
    if(array == nullptr)
    {
        return -1;
    }

    for(int index = 0; index < size; index++)
    {
        std::cout << "array[" << index << "] = ";
        std::cin >> array[index];
    }

    std::cout << "array = [";
    for(int index = 0; index < size; index++)
    {
        std::cout << array[index] << ((index == (size - 1)) ? "" : ", ");
    }
    std::cout << "]" << std::endl;

    delete [] array, array = nullptr;

    return 0;
}