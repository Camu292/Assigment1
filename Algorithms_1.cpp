#include <iostream>
#include <string>
#include "Stack.h"

int main()
{
    std::cout << "Welcome to my REPL\n";

    Stack<int> stack(5); // Creating a stack of integers with an initial size of 5

    // Main loop
    while (true)
    {
        std::cout << "Options:\n"
            << "-- push\n"
            << "-- pop\n"
            << "-- count\n"
            << "-- peek\n"
            << "-- exit\n";
        std::cout << "Please Enter Option: ";

        std::string input;
        std::getline(std::cin, input);

        if (input == "exit")
        {
            break;
        }
        else if (input == "push")
        {
            std::cout << "Enter item: ";
            int item;
            std::cin >> item;
            std::cin.ignore(); // Ignore the newline character left in the input stream
            stack.Push(item);
        }
        else if (input == "pop")
        {
            try
            {
                int item = stack.Pop();
                std::cout << "Popped item: " << item << std::endl;
            }
            catch (const std::exception& e)
            {
                std::cout << "Error: " << e.what() << std::endl;
            }
        }
        else if (input == "count")
        {
            int count = stack.GetCount();
            std::cout << "Items on the stack: " << count << std::endl;
        }
        else if (input == "peek")
        {
            try
            {
                int item = stack.Peek();
                std::cout << "Top item: " << item << std::endl;
            }
            catch (const std::exception& e)
            {
                std::cout << "Error: " << e.what() << std::endl;
            }
        }
        else
        {
            std::cout << "Invalid option. Please try again.\n";
        }
    }

    std::cout << "Thanks and goodbye!\n";
    return 0;
}
