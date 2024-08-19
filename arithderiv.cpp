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

double arithmeticDerivative(int n)
{
    std::map<int, int> primefac = factorization(n);
    double quotient = 0;
    for (const auto &pair : primefac)
    {
        quotient = quotient + static_cast<double>(pair.second) / pair.first;
        ;
    }
    return (n * quotient);
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

// A function to print all prime factors of a given number n
// void primeFactors(int n)
// {
//     // Print the number of 2s that divide n
//     while (n % 2 == 0)
//     {
//         std::cout << 2 << " ";
//         n = n / 2;
//     }

//     // n must be odd at this point. So we can skip
//     // one element (Note i = i + 2)
//     for (int i = 3; i <= std::sqrt(n); i = i + 2)
//     {
//         // While i divides n, print i and divide n
//         while (n % i == 0)
//         {
//             std::cout << i << " ";
//             n = n / i;
//         }
//     }

//     // This condition is to handle the case when n
//     // is a prime number greater than 2
//     if (n > 2)
//         std::cout << n << " ";
// }
