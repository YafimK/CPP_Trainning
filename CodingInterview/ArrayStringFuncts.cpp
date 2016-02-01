#include "ArrayStringFuncts.h"
#include <string>
#include <complex>

ArrayStringFuncts::ArrayStringFuncts()
{
}

/*
	reverses a string in-place iteravly.
*/
void ArrayStringFuncts::stringReverse(std::string &trgString)
{
	int endRunner = trgString.size();
	int runner = 0;
	char tempChar;

	while (runner != endRunner)
	{
		tempChar = trgString[runner];
		trgString[runner] = trgString[endRunner];
		trgString[endRunner] = tempChar;

		endRunner--;
		runner++;
	}
}


/*
Implementation of an algo' that checks if a string has only unique chars.
possible methods: 
	tree (test by ascii till you get equal)
	simple hash
	bucket sort (large memory allocation , o(n) for insert afterwards)
Sanity checks:
	empty input, 
	more than 256 chars can't use the bucket method, will be not uniqe chars)
	
This one will implement the similier to bucket sort method, using a 256 array to indicate if a char had been already found.
	*/
bool ArrayStringFuncts::uniqueStringCharCheck(std::string testString)
{
	try
	{
		size_t testStringLength = testString.length();
		if (testStringLength == 0 || testString == "")
		{
			throw new std::exception("empty string");
		}  
		else if(testStringLength > 256)
		{
			return false;
		}

		bool charArr[256];
		int currCharAscii = 0;

		for(std::string::iterator i = testString.begin(); i!=testString.end(); ++i)
		{
			currCharAscii = int(*i);
			
			if(charArr[currCharAscii] == true)
			{
				return false;
			}
			else
			{
				charArr[currCharAscii] = true;
			}
		}
	}
	catch (std::exception e)
	{
		
	}

	return true;
}