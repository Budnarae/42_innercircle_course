#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		cerr << "Error : There must be 1 file name as a parameter." << endl;
		return (1);
	}

	try
	{
		BitcoinExchange	bitcoinPrinter(argv[1]);
		bitcoinPrinter.printBitcoinTotalByDate();
	}
	catch(const std::exception& e)
	{
		cerr << e.what() << endl;
	}
	
	return (0);
}
