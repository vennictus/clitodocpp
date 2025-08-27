#include <iostream>
#include <string>
#include <list>
#include <ctime>
#include <windows.h>

void setGreenConsole() 
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // Set green background (BACKGROUND_GREEN) and bright green text (FOREGROUND_GREEN | FOREGROUND_INTENSITY)
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

}


void resetConsoleColor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Default gray
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
        //generates a random number between 0 and 100
        id = rand() % 100;  
        title = new_title;
        completed = false;
        return true;

    }

    int getId() { return id; }
    std::string getTitle() { return title; }
    bool getCompleted() { return completed; }
};




int main() 
{
    // Set green background and text
    setGreenConsole();
    
    char choice;
    std::string version = "1.0.0";
    std::list<TodoItem> items;
    std::list<TodoItem>::iterator it;

    srand(time(NULL));

    items.clear();

  //TodoItem test;
  //test.createItem("test");
  //items.push_back(test);



    while (1)
     {
        system("cls");
        std::cout << "Todo List v" << version << std::endl;
        std::cout << std::endl << std::endl;

        for (it = items.begin(); it != items.end(); it++)
        {
            std::string completed_str = it->getCompleted() ? "Completed" : "Not Completed";

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
        
        std::cout << "\n\n";
        std::cout << "Enter your choice: ";


        std::cin >> choice;

        if (choice == 'A' || choice == 'a')
        {
            std::cout << "Enter the title of the item: ";
            std::string title;
            std::cin >> title;
            TodoItem new_item;
            new_item.createItem(title);
            items.push_back(new_item);
        }
        else if (choice == 'M' || choice == 'm')
        {
            std::cout << "Enter the id of the item to mark as completed: ";
        }
        
        
       
         break;
        
    
    }
    
    std::cout << "\nPress Enter to exit...";
    std::cin.get(); 
    resetConsoleColor();
    return 0;
}