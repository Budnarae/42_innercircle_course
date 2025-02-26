#include "Span.hpp"

int main()
{
	{
		cout << endl << "-----Testing Error Output-----" << endl;
		
		try
		{
			Span	sp(10);
		
			for (int i = 0; i < 10; i++)
				sp.addNumber(i);
			
			sp.addNumber(42);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		try
		{
			Span	sp(10);
			vector<int>	vec(11);

			sp.addNumber(vec.begin(), vec.end());
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			Span	sp(0);
			sp.shortestSpan();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		try
		{
			Span	sp(0);
			sp.longestSpan();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			Span	sp(1);
			sp.addNumber(1);
			sp.shortestSpan();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			Span	sp(1);
			sp.addNumber(1);
			sp.longestSpan();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		cout << endl;
	}

	{
		cout << "-----Testing Span Function-----" << endl;

		Span	sp(10);

		sp.addNumber(1);
		sp.addNumber(10000);
		sp.addNumber(5);
		sp.addNumber(7);

		cout << "Shortest Span : " << sp.shortestSpan() << endl;
		cout << "Longest Span : " << sp.longestSpan() << endl;

	}

	{
		cout << "-----Testing Span Function 2-----" << endl;

		Span	sp(10000);

		vector<int>	vec;
		vec.reserve(5000);
		for (int i = 0; i < 5000; i++)
			vec.push_back(i);
		
		for (int i = 0; i < 2500; i++)
			sp.addNumber(i + 5000);
		sp.addNumber(vec.begin(), vec.end());
		for (int i = 0; i < 2500; i++)
			sp.addNumber(i + 7500);
		
		cout << "Shortest Span : " << sp.shortestSpan() << endl;
		cout << "Longest Span : " << sp.longestSpan() << endl;
	}

	return (0);
}