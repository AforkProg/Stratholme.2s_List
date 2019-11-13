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
		addIndexTail();
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
		while (counter != nullptr)
		{
			cout << counter->index << "  --  " << counter->data << endl;
			counter = counter->nextElem;
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
	void deleteByIndex(int userIndex)
	{
		stList * delRunner = head;
		if (userIndex == 1)
		{
			head = head->nextElem;
			delete delRunner;
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
					break;
				}
				counter++;
				delRunner = delRunner->nextElem;
			}
		}
	}
	void changeIndex(int userIndex, int userData)
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
	void addIndexTail()
	{
		stList * newElem_T = head;
		int counter = 1;
		while (newElem_T != nullptr)
		{
			newElem_T->index = counter;
			++counter;
			newElem_T = newElem_T->nextElem;
		}
		size++;
	}
};
int main()
{
	setlocale(LC_ALL, "russian");
	clList Stratholm;
	Stratholm.write_back(1);
	Stratholm.write_back(2);
	Stratholm.write_back(3);
	Stratholm.write_back(4);
	Stratholm.write_back(5);
	Stratholm.changeIndex(2, 22);
	Stratholm.printAll();
	system("pause");
	return 0;
}