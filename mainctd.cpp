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

    bool createItem(std::string new_title)
    {
        // Generates a random integer ID between 1 and 100 to avoid ID 0.
        id = rand() % 100 + 1;
        title = new_title;
        completed = false;
        return true;
    }

    int getId() { return id; }
    std::string getTitle() { return title; }
    bool getCompleted() { return completed; }
    
    // FIX: Changed 'boolean' to the correct C++ type 'bool'.
    void setCompleted(bool val) {
        completed = val;
    }
};

int main()
{
    setGreenConsole();

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
            // IMPROVEMENT: Use [x] and [ ] for a cleaner display.
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
        // FIX: Clear the input buffer after reading a single character.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 'A' || choice == 'a')
        {
            std::cout << "Enter the title of the item: ";
            std::string title;
            // FIX: Use std::getline to read a title with spaces.
            std::getline(std::cin, title);
            TodoItem new_item;
            new_item.createItem(title);
            items.push_back(new_item);
        }
        else if (choice == 'M' || choice == 'm')
        {
            std::cout << "Enter the id of the item to mark as completed: ";
            // FIX: Declare the input_id variable.
            int input_id;
            std::cin >> input_id;
            // FIX: Clear the input buffer after reading the ID.
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
            // FIX: Add a flag to check if the item was found.
            bool found = false;
            for (it = items.begin(); it != items.end(); it++)
            {
                if (input_id == it->getId())
                {
                    it->setCompleted(true);
                    found = true; // Set flag to true
                    break;        // FIX: Exit the loop once the item is found.
                }
            }

            // FIX: Check the flag to inform the user of the result.
            if (found) {
                std::cout << "Item " << input_id << " marked as completed.\n";
            } else {
                std::cout << "Error: Item with ID " << input_id << " not found.\n";
            }
            Sleep(2000); // Pause to let the user see the message.
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
            // IMPROVEMENT: More descriptive error message.
            std::cout << "Invalid choice. Please try again.\n";
            Sleep(2000);
        }
    }

    std::cout << "\nPress Enter to exit...";
    std::cin.get();
    resetConsoleColor();
    return 0;
}