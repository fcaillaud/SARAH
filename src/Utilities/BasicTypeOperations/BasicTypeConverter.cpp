#include "BasicTypeConverter.hpp"

namespace gu
{
	//======================== char * to others ==========================

	char AtoChar(const char * pA)
	{
		return pA[0];
	}

	std::string AtoString(const char * pA)
	{
		return std::string(pA);
	}

	bool AtoBool(const char * pA)
	{
		if(strcmp(AtoLower(pA), "true") == 0)
			return true;
		if(strcmp(AtoLower(pA), "false") == 0)
			return false;

		std::cerr << "ERROR : In AtoBool, you can't convert a string different of 'true' or 'false' in boolean value" << std::endl;
		exit(-1);
	}

	int AtoInt(const char * pA)
	{
		return atoi(pA);
	}

	unsigned int AtoUInt(const char * pA)
	{
		return (unsigned int) atoi(pA);
	}

	short int AtoSInt(const char * pA)
	{
		return (short int) atoi(pA);
	}

	long int AtoLInt(const char * pA)
	{
		return atol(pA);
	}

	long long int AtoLLInt(const char * pA)
	{
		return atoll(pA);
	}

	double AtoDouble(const char * pA)
	{
		return atof(pA);
	}

	long double AtoLDouble(const char * pA)
	{
		return (long double) atof(pA);
	}

	float AtoFloat(const char * pA)
	{
		return (float) atof(pA);
	}

	char * AtoLower(const char * pA)
	{
		unsigned int i = 0;

		while(pA[i])
			i++;

		char * vStr = new char[i];
		for(unsigned int j = 0; j < i; ++j)
			vStr[j] = tolower(pA[j]);
			
		return vStr;
	}

	char * AtoUpper(const char * pA)
	{
		unsigned int i = 0;

		while(pA[i])
			i++;

		char * vStr = new char[i];
		for(unsigned int j = 0; j < i; ++j)
			vStr[j] = toupper(pA[j]);
			
		return vStr;
	}
}
