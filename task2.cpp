#include<iostream>
#include<string>

class Counter
{
public:
	void Inc()
	{
		value++;
	}
	void Dec()
	{
		value--;
	}
	int ShowValue()
	{
		return value;
	}
	Counter() { value = 1;}
	Counter(int value) { this->value = value; }
private:
	int value;
};


void Command(Counter& counter)
{
	char symbol = '0';
	while (symbol != 'x')
	{
		std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
		std::cin >> symbol;
		switch (symbol)
		{
		case '+': {counter.Inc(); break; }
		case '-': {counter.Dec(); break; }
		case '=':
		{
			std::cout << counter.ShowValue();
			std::cout << std::endl;
			break;
		}
		case 'x': {std::cout << "До свидания!"; break; }
		}
	}
}
int main(int argc, char** argv)
{
	system("chcp 1251");
	std::string answer;
	std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
	std::cin >> answer;
	if (answer == "да")
	{
		std::cout << "Введите начальное значение счётчика: ";
		int Init = 0;
		std::cin >> Init;
		Counter counter(Init);
		Command(counter);
	}
	else
	{
		Counter counter;
		Command(counter);
	}
	return 0;
}