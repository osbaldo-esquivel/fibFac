// Osbaldo Esquivel
// 09MAR2015

#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <string>
#include <vector>
#include <iomanip>

long fibIter(int);
long fibRec(int);
long facRec(int);
long tailRecHelper(int, int);
long facTailRec(int);

int main()
{
    using namespace std::chrono; // to use chrono timing
    std::cout.precision(5);

	int choice, fibNum, facNum, fibFac;
	char answer;

    do{
    std::cout << std::string(50, '\n'); // clear screen

	std::cout << "\n                            FibFac                          \n"
			  << "===========================================================\n"
			  << "\t1. Fibonacci\n"
			  << "\t2. Factorial\n"
			  << "\t3. Exit program\n"
			  << "Please enter your choice: ";
	std::cin >> fibFac;

    switch(fibFac)
    {
        case 1: {
                std::cout << "\nPlease enter a value n to calculate the nth\n"
                          << "Fibonacci number: ";
                std::cin >> fibNum;

                std::cout << "\n             Fibonacci          \n"
                          << "===============================\n"
                          << "\t1. Iteration\n"
                          << "\t2. Recursion\n"
                          << "Please enter a choice: ";
                std::cin >> choice;

                switch(choice)
                {
                  case 1: { high_resolution_clock::time_point begin =
                  high_resolution_clock::now(); // start timer
				  std::cout << "Iteration: " << std::fixed << fibIter(fibNum);
                  high_resolution_clock::time_point end =
                  high_resolution_clock::now(); // end timer
				  duration<double> time_span =
				  duration_cast<duration<double> >(end - begin); // calculate time
				  std::cout << "\nCalculation time: " << time_span.count()
							<< " seconds." << std::endl;
				  break; }
                  case 2: { high_resolution_clock::time_point begin =
                  high_resolution_clock::now();
				  std::cout << "Recursion: " << std::fixed
                            << fibRec(fibNum);
				  high_resolution_clock::time_point end =
                  high_resolution_clock::now();
				  duration<double> time_span =
				  duration_cast<duration<double> >(end - begin);
				  std::cout << "\nCalculation time: " << time_span.count()
							<< " seconds." << std::endl;
				  break; }
				  default: {std::cout << "\nThat is not an option\n";
				  break; }
                }
            break;
        }
        case 2: {
                std::cout << "\nPlease enter a value n to calculate the\n"
                          << "factorial of that value: ";
                std::cin >> facNum;

                std::cout << "\n             Factorial          \n"
                          << "===============================\n"
                          << "\t1. Recursion\n"
                          << "\t2. Tail Recursion\n"
                          << "Please enter a choice: ";
                std::cin >> choice;

                switch(choice)
                {
                  case 1: { high_resolution_clock::time_point begin =
                  high_resolution_clock::now();
				  std::cout << "\nRecursion: " << std::fixed << facRec(facNum);
				  high_resolution_clock::time_point end =
                  high_resolution_clock::now();
				  duration<double> time_span =
				  duration_cast<duration<double> >(end - begin);
				  std::cout << "\nCalculation time: " << time_span.count()
							<< " seconds." << std::endl;
				  break; }
                  case 2: { high_resolution_clock::time_point begin =
                  high_resolution_clock::now();
				  std::cout << "\nTail Recursion: " << std::fixed
                            << facTailRec(facNum);
				  high_resolution_clock::time_point end =
                  high_resolution_clock::now();
				  duration<double> time_span =
				  duration_cast<duration<double> >(end - begin);
				  std::cout << "\nCalculation time: " << time_span.count()
							<< " seconds." << std::endl;
				  break; }
                  default: { std::cout << "\nThat is not an option!\n";
                  break; }
                }
            break;
                }
        case 3: {return 0;}
        default: { std::cout << "\nThat is not an option!" << std::endl;
            break;}
    }

    std::cout << "\nWould you like to go back to the main menu (Y/N): ";
    std::cin >> answer;
    }while(answer == 'Y' || answer == 'y');

	return 0;
}

// this function will find the nth Fibonacci number using iteration
long fibIter(int num)
{
    int itOne = 0;
    int itTwo = 1;
    int it = 0;

    if(num == 0 || num == 1)
    {
        return num;
    }

    for(int i = 2; i <= num; i++)
    {
        it = itOne + itTwo;
        itOne = itTwo;
        itTwo = it;
    }

    return it;
}

// this function will find the nth Fibonacci number using recursion
long fibRec(int num)
{
	if (num <= 0)
	{
		return 0;
	}
	else if (num == 1)
	{
		return 1;
	}
	else
	{
		return fibRec(num - 2) + fibRec(num - 1);
	}
}

// this function will find the factorial of a value using recursion
long facRec(int num)
{
    if(num == 1)
    {
        return 1;
    }
    else
    {
        return num * facRec(num - 1);
    }
}

// this function uses tail recursion to find the factorial of a value
long tailRecHelper(int n, int result)
{
	if (n == 1)
	{
		return result;
	}
	else
	{
		return tailRecHelper(n - 1, n * result);
	}
}

// calls function to calculate factorial using tail recursion
long facTailRec(int n)
{
	return tailRecHelper(n, 1);
}
