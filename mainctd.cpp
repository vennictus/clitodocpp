#include <iostream>
#include <string>
#include <list>
#include <ctime>
#include <windows.h>
#include <limits> // Required for std::numeric_limits

void setGreenConsole()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

void resetConsoleColor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

class TodoItem
{
private:
    int id;
    std::string title;
    bool completed;

public:
    TodoItem() : id(0), title(""), completed(false) {}
    ~TodoItem() = default;
    
    // FIX 1: Change the function signature to accept an integer 'new_id'
    bool createItem(int new_id, std::string new_title)
    {
        // Now we simply assign the ID that was passed in from main.
        id = new_id;

        title = new_title;
        completed = false;
        return true;
    }

    int getId() { return id; }
    std::string getTitle() { return title; }
    bool getCompleted() { return completed; }

    void setCompleted(bool val) {
        completed = val;
    }
};

int main()
{
    setGreenConsole();

    int counter = 1;

    char choice;
    std::string version = "1.0.0";
    std::list<TodoItem> items;
    std::list<TodoItem>::iterator it;

    srand(time(NULL));
    items.clear();

    while (1)
    {
        system("cls");
        std::cout << "Todo List v" << version << std::endl;
        std::cout << std::endl << std::endl;

        for (it = items.begin(); it != items.end(); it++)
        {
            std::string completed_str = it->getCompleted() ? "Completed [x] " : "Not Completed [ ] ";
            std::cout << it->getId() << "|" << it->getTitle() << "|" << completed_str << std::endl;
        }

        if (items.empty())
        {
            std::cout << "No items to display" << std::endl;
        }

        std::cout << "\n\n";
        std::cout << "1. [A]dd Item" << std::endl;
        std::cout << "2. [M]ark Item as Completed" << std::endl;
        std::cout << "3. [E]xit" << std::endl;
        std::cout << "4. [C]lear Memory" << std::endl;

        std::cout << "\n\n";
        std::cout << "Enter your choice: ";

        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 'A' || choice == 'a')
        {
            std::cout << "Enter the title of the item: ";
            std::string title;
            std::getline(std::cin, title);
            TodoItem new_item;
            
            // FIX 2: Pass the 'counter' value to the createItem method, and then increment it.
            new_item.createItem(counter, title);
            items.push_back(new_item);
            counter++;
        }
            else if (choice == 'M' || choice == 'm')
    {
        std::cout << "Enter the id of the item to mark as completed: ";
        
        // FIX: Read the input as a string first.
        std::string input_str;
        std::getline(std::cin, input_str);

        // This converts the string to an integer.
        // It's a safer way to handle input.
        int input_id = std::stoi(input_str);
        
        bool found = false;
        for (it = items.begin(); it != items.end(); it++)
        {
            if (input_id == it->getId())
            {
                it->setCompleted(true);
                found = true;
                break;
            }
        }

        if (found) {
            std::cout << "Item " << input_id << " marked as completed.\n";
        } else {
            std::cout << "Error: Item with ID " << input_id << " not found.\n";
        }
        Sleep(2000);
    }
        else if (choice == 'E' || choice == 'e')
        {
            std::cout << "Have a Great day Zuniga\n";
            break;
        }
        else if (choice == 'C' || choice == 'c')
        {
            items.clear();
            std::cout << "Cleared Memory\n";
            Sleep(2000);
        }
        else
        {
            std::cout << "Invalid choice. Please try again.\n";
            Sleep(2000);
        }
    }

    std::cout << "\nPress Enter to exit...";
    std::cin.get();
    resetConsoleColor();
    return 0;
}