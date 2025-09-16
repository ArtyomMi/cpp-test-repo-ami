// В этом файле определения функций.
// За основу возьмите решение предыдущей задачи.
#include "calculator.h"
using Number = double;

// Number definitions reading command.
enum class Commands
{
    Sum = 1,
    Sub,
    Mul,
    Div,
    Pow,
    Set,
    Get,
    Clear,
    Quit,
    Save,
    Load,
    Unknown = -1
};

// Number of the calculator
Number number;
Number summary = 0;
Number save = 0;
Number operand;
std::string command;
using Number = double;
bool is_save = false;
bool is_inf = false;

// Function definitions summing two numbers.
void Sum(Number a)
{
    summary = summary + a;
    return;
}

// Function definitions subtracting two numbers.
void Sub(Number a)
{
    summary = summary - a;
    return;
}

// Function definitions multiplying two numbers.
void Mul(Number a)
{
    summary = summary * a;
    return;
}

// Function definitions dividing two numbers.
void Div(Number a)
{
    if (a == 0)
    {
        is_inf = true;
    }
    else
    {
        summary = summary / a;
    }
    return;
}

// Function definitions powering two numbers.
void Pow(Number a)
{
    if (a == 0)
    {
        summary = 1;
    }
    else
    {
        summary = std::pow(summary, a);
    }
}

// Function definitions saving number.
void Set(Number a)
{
    summary = a;
    is_inf = false;
    return;
}

// Function definitions getting number.
void Get()
{
    if (is_inf)
    {
        std::cout << "inf" << std::endl;
    }else{
        std::cout << summary << std::endl;
    }
    return;
}
void Save()
{
    save = summary;
    is_save = true;
    return;
}
void Load()
{
    if (is_save)
    {
        summary = save;
    }
    else
    {
        std::cerr << "Error: Memory is empty" << std::endl;
    }
}

// Function definitions clearing memory.
void Clear()
{
    summary = 0;
    if (is_save)
    {
        is_save = false;
    }
}

// Function definitions reading number.
bool ReadNumber(Number &number)
{
    if (!(std::cin >> number))
    {
        // Вывод ошибки.
        std::cerr << "Error: Numeric operand expected" << std::endl;
        return false;
    }
    else
    {
        return true;
    }
}

// Function definitions reading command.
Commands Readcommand()
{
    std::cin >> command;
    if (command == "=")
    {
        return Commands::Get;
    }
    else if (command == "+")
    {
        return Commands::Sum;
    }
    else if (command == "-")
    {
        return Commands::Sub;
    }
    else if (command == "*")
    {
        return Commands::Mul;
    }
    else if (command == "/")
    {
        return Commands::Div;
    }
    else if (command == "**")
    {
        return Commands::Pow;
    }
    else if (command == ":")
    {
        return Commands::Set;
    }
    else if (command == "c")
    {
        return Commands::Clear;
    }
    else if (command == "q")
    {
        return Commands::Quit;
    }
    else if (command == "s")
    {
        return Commands::Save;
    }
    else if (command == "l")
    {
        return Commands::Load;
    }
    else
    {
        return Commands::Unknown;
    }
}

bool RunCalculatorCycle()
{
    // Чтение начального числа
    if (!ReadNumber(number))
    {
        return false;
    }
    summary = number;
    // Основной цикл.
    while (true)
    {
        Commands comm = Readcommand();
        switch (comm)
        {
        case Commands::Sum:
            if (!ReadNumber(number))
            {
                return false;
            }
            Sum(number);
            break;

        case Commands::Sub:
            if (!ReadNumber(number))
            {
                return false;
            }
            Sub(number);
            break;

        case Commands::Mul:
            if (!ReadNumber(number))
            {
                return false;
            }
            Mul(number);
            break;

        case Commands::Div:
            if (!ReadNumber(number))
            {
                return false;
            }
            Div(number);
            break;

        case Commands::Pow:
            if (!ReadNumber(number))
            {
                return false;
            }
            Pow(number);
            break;

        case Commands::Set:
            if (!ReadNumber(number))
            {
                return false;
            }
            Set(number);
            break;

        case Commands::Get:
            Get();
            break;

        case Commands::Clear:
            Clear();
            break;

        case Commands::Quit:
            return true;
            break;

        case Commands::Save:
            Save();
            break;

        case Commands::Load:
            Load();
            break;

        default:
            std::cerr << "Error: Unknown token " << command << std::endl;
            break;
        }
    }
}