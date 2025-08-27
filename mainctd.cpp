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
    int progress; // NEW: Member variable to store progress percentage

public:
    // Updated constructor to initialize progress
    TodoItem() : id(0), title(""), completed(false), progress(0) {}
    ~TodoItem() = default;

    // Updated createItem to accept the sequential ID
    bool createItem(int new_id, std::string new_title)
    {
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

    // NEW: Method to update progress
    void setProgress(int new_progress) {
        if (new_progress >= 0 && new_progress <= 100) {
            progress = new_progress;
            // Mark as completed if progress reaches 100
            if (progress == 100) {
                completed = true;
            } else {
                completed = false;
            }
        }
    }
    
    // NEW: Getter for progress
    int getProgress() {
        return progress;
    }
};

int main()
{
    setGreenConsole();

    int counter = 1;

    char choice;
    std::string version = "2.0.0";
    std::list<TodoItem> items;
    std::list<TodoItem>::iterator it;

    srand(time(NULL));
    items.clear();

    while (1)
    {
        system("cls");
        std::cout << "Todo List v" << version << std::endl;
        std::cout << std::endl << std::endl;

        std::cout << "--- Incomplete Tasks ---" << std::endl;
        for (it = items.begin(); it != items.end(); it++)
        {
            if (!it->getCompleted()) {
                std::string completed_str = "Not Completed [ ]";
                std::string progress_bar = "[";
                int filled_blocks = it->getProgress() / 10;
                
                for (int i = 0; i < 10; ++i) {
                    if (i < filled_blocks) {
                        progress_bar += '#';
                    } else {
                        progress_bar += '-';
                    }
                }
                progress_bar += "] " + std::to_string(it->getProgress()) + "%";
                
                std::cout << it->getId() << "|" << it->getTitle() << "|" << completed_str << "|" << progress_bar << std::endl;
            }
        }

        std::cout << "\n--- Completed Tasks ---" << std::endl;
        for (it = items.begin(); it != items.end(); it++)
        {
            if (it->getCompleted()) {
                std::string completed_str = "Completed [x]";
                std::string progress_bar = "[##########] 100%";
                
                std::cout << it->getId() << "|" << it->getTitle() << "|" << completed_str << "|" << progress_bar << std::endl;
            }
        }

        if (items.empty())
        {
            std::cout << "No items to display" << std::endl;
        }

        std::cout << "\n\n";
        std::cout << "1. [A]dd Item" << std::endl;
        std::cout << "2. [M]ark Item as Completed" << std::endl;
        std::cout << "3. [P]rogress Item" << std::endl;
        std::cout << "4. [C]lear Memory" << std::endl;
        std::cout << "5. [E]xit" << std::endl;

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
            new_item.createItem(counter, title);
            items.push_back(new_item);
            counter++;
        }
        else if (choice == 'M' || choice == 'm')
        {
            std::cout << "Enter the id of the item to mark as completed: ";
            std::string input_str;
            std::getline(std::cin, input_str);
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
        else if (choice == 'P' || choice == 'p')
        {
            std::cout << "Enter the id of the item to update progress: ";
            std::string input_str;
            std::getline(std::cin, input_str);
            int input_id = std::stoi(input_str);

            std::cout << "Enter the new progress percentage (0-100): ";
            std::string progress_str;
            std::getline(std::cin, progress_str);
            int new_progress = std::stoi(progress_str);

            bool found = false;
            for (it = items.begin(); it != items.end(); it++)
            {
                if (input_id == it->getId())
                {
                    it->setProgress(new_progress);
                    found = true;
                    break;
                }
            }

            if (found) {
                std::cout << "Item " << input_id << " progress updated to " << new_progress << "%\n";
            } else {
                std::cout << "Error: Item with ID " << input_id << " not found.\n";
            }
            Sleep(2000);
        }
        else if (choice == 'C' || choice == 'c')
        {
            items.clear();
            std::cout << "Cleared Memory\n";
            Sleep(2000);
        }
        else if (choice == 'E' || choice == 'e')
        {
            std::cout << "Have a Great day Zuniga\n";
            break;
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