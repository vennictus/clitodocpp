#include <iostream>
#include <string>
#include <list>
#include <ctime>

class TodoItem {
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
    std::string version = "1.0.0";
    std::list<TodoItem> items;
    std::list<TodoItem>::iterator it;

    srand(time(NULL));

    items.clear();

    TodoItem test;
    test.createItem("test");
    items.push_back(test);



    while (1)
     {
        system("cls");
        std::cout << "Todo List v" << version << std::endl;
        std::cout << std::endl << std::endl;

        for (it = items.begin(); it != items.end(); it++)
        {
            std::cout << it->getId() << "|" << it->getTitle() << "|" << it->getCompleted() << std::endl;
            
        }

        break;
        
    
    }
    
    std::cout << "\nPress Enter to exit...";
    std::cin.get();
    return 0;
}