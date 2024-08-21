#include <iostream>
#include <cmath>
#include <map>

std::map<int, int> factorization(int n)
{
    std::map<int, int> temp;

    // Check for factor 2
    while (n % 2 == 0)
    {
        temp[2]++;
        n = n / 2;
    }

    // Check for odd factors from 3 onwards
    for (int i = 3; i <= std::sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            temp[i]++;
            n = n / i;
        }
    }

    // If n is a prime number greater than 2
    if (n > 2)
    {
        temp[n]++;
    }

    return temp;
}

int arithmeticDerivative(int n)
{
    std::map<int, int> primefac = factorization(n);
    float quotient = 0;
    for (const auto [p, e] : primefac)
    {
        quotient = quotient + static_cast<float>(e) / p;
    }
    return int(n * quotient);
}

int main()
{
    std::string input;

    while (true)
    {
        std::cout << "Enter an integer (or type 'quit' to exit): ";
        std::getline(std::cin, input);

        if (input == "quit")
        {
            break;
        }

        try
        {
            int x = std::stoi(input);
            float result = arithmeticDerivative(x);
            std::cout << "The arithmetic derivative of " << x << " is " << result << std::endl;
        }
        catch (const std::invalid_argument &e)
        {
            std::cout << "Invalid input. Please enter an integer or 'quit' to exit." << std::endl;
        }
        catch (const std::out_of_range &e)
        {
            std::cout << "The number is out of range. Please enter a valid integer." << std::endl;
        }
    }

    std::cout << "Exiting the program." << std::endl;

    return 0;
}