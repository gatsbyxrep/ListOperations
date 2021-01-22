#include <iostream>
#include <list>
#include <stack>

class ListOperations
{
public:
    // Удаление элемента из списка по индексу
    template <typename T>
    static void eraseElement(std::list<T> &list, int elementIndexToDelete)
    {
        auto iteratorToNeededElement = list.begin();
        std::advance(iteratorToNeededElement, elementIndexToDelete);
        list.erase(iteratorToNeededElement);
    }
    // Вывод списка на экран
    template <typename T>
    static void printList(const std::list<T> &list)
    {
        for(auto elem : list)
            std::cout << elem << " ";
        std::cout << std::endl;
    }
    // Поиск индекса элемента по значению
    template <typename T>
    static int findElementIndex(std::list<T> &list, const T& elemToFind)
    {
        auto findedElementIterator = std::find(list.begin(), list.end(), elemToFind);
        if(findedElementIterator != list.end())
            return std::distance(list.begin(), findedElementIterator);
        return -1;
    }
    template <typename T>
    static void changeElementByIndex(std::list<T> &list, size_t index, const T& elem)
    {
        auto iteratorToNeededElement = list.begin();
        std::advance(iteratorToNeededElement, index);
        *iteratorToNeededElement = elem;
    }
    static std::pair<std::stack<char>,std::stack<int>> diviedListToDigitsAndChars(const std::list<char> &list)
    {
        std::pair<std::stack<char>,std::stack<int>> result;
        for(auto it = list.begin(); it != list.end(); it++)
        {
            if(isdigit(*it))
                result.second.push(static_cast<int>(*it));
            else
                result.first.push(*it);
        }
        return result;
    }

};

int main()
{

    setlocale(LC_ALL, "RUS");
    // Добавление элементов в список
    std::list<char> charList;
    size_t charListSize = 0;
    std::cout << "Input size of first list" << std::endl;
    std::cin >> charListSize;
    char symbol = 0;
    for(size_t i = 0; i < charListSize; i++)
    {
        std::cout << "Input element:";
        std::cin >> symbol;
        charList.push_back(symbol);
    }
    // Поиск
    std::cout << "Input element value for find" << std::endl;
    char elemToFind = 0;
    std::cin >> elemToFind;
    auto findedIndex = ListOperations::findElementIndex(charList, elemToFind);
    if(findedIndex != -1)
        std::cout << "Finded element index:" << findedIndex << std::endl;
    else
        std::cout << "Element hasn't been found" << std::endl;
    std::cout << "List size:" << charList.size() << std::endl;
    // Удаление по индексу
    std::cout << "Input element index to delete" << std::endl;
    size_t index = 0;
    std::cin >> index;
    ListOperations::eraseElement(charList, index);
    std::cout << "List after erasing:";
    ListOperations::printList(charList);
    // Изменение элемента по индексу
    std::cout << "Input element to change" << std::endl;
    char elemToChange = 0;
    std::cin >> elemToChange;
    std::cout << "Input index to change" << std::endl;
    std::cin >> index;
    ListOperations::changeElementByIndex(charList, index, elemToChange);
    auto stacks = ListOperations::diviedListToDigitsAndChars(charList);
    std::cout << "Char stack:";
    while(!stacks.first.empty())
    {
         std::cout << stacks.first.top() << " ";
         stacks.first.pop();
    }
    std::cout << std::endl;
    std::cout << "Digits stack:";
    while(!stacks.second.empty())
    {
         std::cout << stacks.second.top() - '0' << " ";
         stacks.second.pop();
    }
    return 0;
}
