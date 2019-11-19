#include <iostream>
using namespace std;
struct stList
{
	int index;
	int data;
	stList * nextElem = nullptr;
	stList * prevElem = nullptr;
};
class clList
{
public:
	clList()
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	~clList()
	{
		stList * delRunner = head;
		while (delRunner != nullptr)
		{
			if (size == 0)
			{
				return;
			}
			head = head->nextElem;
			delete delRunner;
			delRunner = head;
		}
	}
	void write_back(int userData)
	{
		stList * newElem = new stList;
		newElem->data = userData;
		if (tail == nullptr)
		{
			head = newElem;
			tail = newElem;
		}
		else
		{
			tail->nextElem = newElem;
			newElem->prevElem = tail;
			tail = newElem;
		}
		addIndexHead();
	}
	void write_front(int userData)
	{
		stList * newElem = new stList;
		newElem->data = userData;
		newElem->nextElem = head;
		head = newElem;
		if (head == nullptr)
		{
			head = newElem;
			tail = newElem;
		}
		else
		{
			head->prevElem = newElem;
			head = newElem;
		}
		addIndexHead();
	}
	void printAll()
	{
		stList * counter = head;
		if (counter== nullptr)
		{
			return;
		}
		else if (size == 0)
		{
			cout << "В списке нет элементов" << endl;
		}
		else
		{
			while (counter != nullptr)
			{
 				cout << counter->index << "  --  " << counter->data << endl;
				counter = counter->nextElem;
			}
		}
	}
	void printByIndex(int userIndex) // Решил немного поэкспериментировать с этой функцией
	{
		if (userIndex <= size / 2) // Пробег по элементам с head
		{
			stList * printRunnerHead = head;
			int counter = 1;
			while (printRunnerHead != nullptr)
			{
				if (counter == userIndex)
				{
					cout << printRunnerHead->index << "  --  " << printRunnerHead->data << endl;
					break;
				}
				printRunnerHead = printRunnerHead->nextElem;
				counter++;
			}
		}
		else if (userIndex > size / 2) // Пробег по элементам с tail
		{
			stList * printRunnerTail = tail;
			int counter = size;
			while (printRunnerTail != nullptr)
			{
				if (counter == userIndex)
				{
					cout << printRunnerTail->index << "  --  " << printRunnerTail->data << endl;
					break;
				}
				printRunnerTail = printRunnerTail->prevElem;
				counter--;
			}
		}
	}
	void deleteAll()
	{
		stList * delRunner = head;
		while (delRunner != nullptr)
		{
			head = head->nextElem;
			delete delRunner;
			delRunner = head;
		}
	}
	void deleteByIndex(unsigned int userIndex)
	{
		stList * delRunner = head;
		
		if (userIndex == 0 || userIndex > size)
		{
			cout << "error 404 not found" << endl;
		}
		else if (size == 1)
		{
			delete delRunner;
			size--;
		}
		else if (userIndex == 1)
		{
			head = head->nextElem;
			delete delRunner;
			head->prevElem = nullptr;
			size--;
		}
		else if (userIndex == size)
		{
			delRunner = tail;
			tail = tail->prevElem;
			delete delRunner;
			tail->nextElem = nullptr;
			size--;
		}
		else
		{
			int counter = 1;
			while (delRunner != nullptr)
			{
				if (counter == userIndex - 1)
				{
					stList * remove = delRunner->nextElem;
					delRunner->nextElem = delRunner->nextElem->nextElem;
					delete remove;
					size--;
					break;
				}
				counter++;
				delRunner = delRunner->nextElem;
			}
		}
	}
	void changeByIndex(int userIndex, int userData)
	{
		stList * elemChanger = head;
		int counter = 1;
		while (elemChanger != nullptr)
		{
			if (counter == userIndex)
			{
				elemChanger->index = userIndex;
				elemChanger->data = userData;
				break;
			}
			counter++;
			elemChanger = elemChanger->nextElem;
		}
	}
	void writeSize()
	{
		cout << "Элементов в списке: " << size << endl;
	}
private:
	stList * head;
	stList * tail;
	int size;
	void addIndexHead()
	{
		stList * newElem_H = head;
		int counter = 1;
		while (newElem_H != nullptr)
		{
			newElem_H->index = counter;
			counter++;
			newElem_H = newElem_H->nextElem;
		}
		size++;
	}
};

/*
error 1: 
	desc: 
		tail не указывает на предыдущий элемент после удаления последнего элемента.
	example:
		void error_example_1(){
			clList Stratholm;
			Stratholm.write_back(1);
			Stratholm.write_back(2);
			Stratholm.deleteByIndex(2);
		}

error 2:
		void deleteByIndex(int userIndex{
		...
		if (userIndex == 1)
		{
			head = head->nextElem; <----------
			delete delRunner;
		}
		...
	desc:
		отсутствует проверка на то, что head == nullptr
	example:
		void error_example_2(){
			clList Stratholm;
			Stratholm.deleteByIndex(1);
		}

в чем разница между addIndexTail() и addIndexHead()
*/
int main()
{
	setlocale(LC_ALL, "russian");
	clList Stratholm;
	Stratholm.write_back(1);
	Stratholm.write_back(2);
	Stratholm.deleteByIndex(2);
	system("pause");
	return 0;
}