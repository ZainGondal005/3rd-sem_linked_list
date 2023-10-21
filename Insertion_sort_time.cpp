#include <iostream>
#include <chrono>
#include <thread>
class Insertion_sort
{
private:
    int *array;
    int size;

public:
    void setvalues(int n)
    {
        size = n;
        array = new int[size];
        for (int i = 0; i < size; i++)
        {
            array[i] = i + 1;
        }
        std::cout << std::endl;
    }
    void insertion_sort()
    {
        int key = 0, temp = 0, count;
        for (int i = 1; i <= size - 1; i++)
        {
            key = array[i];
            temp = i - 1;

            while (array[temp] > key && temp >= 0)
            {
                array[temp + 1] = array[temp];
                temp--;
                count++;
            }
            array[temp + 1] = key;
        }
        if (count == 0)
        {
            std::cout << "Array is already sorted\n";
            return;
        }
    }
    void random_number(int n)
    {
        size = n;
        array = new int[size];
        int num;
        srand(time(NULL));
        for (int i = 0; i < size; i++)
        {
            num = (rand() % 10 + 1);
            array[i] = num;
        }
    }
    void print()
    {
        std::cout << "value are : ";
        for (int i = 0; i < size; i++)
        {
            std::cout << array[i] << "   ";
        }
        std::cout << "----------------------------------\n";
    }
    ~Insertion_sort()
    {

        delete[] array;
    }
};

int main()
{
    Insertion_sort obj_1, obj_2;
    int n = 6;

    obj_1.setvalues(n);
    std::cout << "Simple Array is:" << std::endl;
    obj_1.print();

    auto start = std::chrono::steady_clock::now();

    obj_1.insertion_sort();

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    float ms = elapsed_seconds.count() * 1000;
    std::cout << "Sorting took " << ms << " ms" << std::endl;

    obj_2.random_number(n);

    std::cout << "Array of random numbers before sort:" << std::endl;
    obj_2.print();

    start = std::chrono::steady_clock::now();

    obj_2.insertion_sort();
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end - start;

    ms = elapsed_seconds.count() * 1000;

    std::cout << "Array of random numbers after sort:" << std::endl;
    obj_2.print();

    std::cout << "Sorting took " << ms << " ms" << std::endl;

    return 0;
}
