#include "Parameter.hpp"

namespace optg
{

	Parameter::Parameter(const char * pValue, PType pType):
		mValue(),
		mStrValue(pValue),
		mType(pType)
	{
		switch(pType)
		{	
			case CHAR:
				{
					char * vPChar = new char;
					*vPChar = gu::AtoChar(pValue);
					mValue = vPChar;
				}
				break;
			case PCHAR:
				{
					unsigned int i = 0;

					while(pValue[i])
						i++;

					char ** vStr = new char*;
					vStr[0] = new char[i];
					for(unsigned int j = 0; j < i; ++j)
						vStr[0][j] = tolower(pValue[j]);
				
					mValue = vStr;
				}
				break;
			case STRING:
				{
					std::string * vPStr = new std::string(pValue);
					mValue = vPStr;
				}
				break;
			case BOOL:
				{
					bool * vPBool = new bool;
					*vPBool = gu::AtoBool(pValue);
					mValue = vPBool;
				}
				break;
			case INT:
				{
					int * vPInt = new int;
					*vPInt = gu::AtoInt(pValue);
					mValue = vPInt;
				}
				break;
			case UINT:
				{
					unsigned int * vPUInt = new unsigned int;
					*vPUInt = gu::AtoUInt(pValue);
					mValue = vPUInt;
				}
				break;
			case SINT:
				{
					short int * vPSInt = new short int;
					*vPSInt = gu::AtoSInt(pValue);
					mValue = vPSInt;
				}
				break;
			case LINT:
				{
					long int * vPLInt = new long int;
					*vPLInt = gu::AtoLInt(pValue);
					mValue = vPLInt;
				}
				break;
			case LLINT:
				{
					long long int * vPLLInt = new long long int;
					*vPLLInt = gu::AtoLLInt(pValue);
					mValue = vPLLInt;
				}
				break;
			case DOUBLE:
				{
					double * vPDouble = new double;
					*vPDouble = gu::AtoDouble(pValue);
					mValue = vPDouble;
				}
				break;
			case LDOUBLE:
				{
					long double * vPLDouble = new long double;
					*vPLDouble = gu::AtoLDouble(pValue);
					mValue = vPLDouble;
				}
				break;
			case FLOAT:
				{
					float * vPFloat = new float;
					*vPFloat = gu::AtoFloat(pValue);
					mValue = vPFloat;
				}
				break;
			default:
				break;
		}
	}
	
	Parameter::~Parameter()
	{
		switch(mType)
		{	
			case CHAR:
				{
					char * vDel = (char *)mValue;
					delete vDel;
				}
				break;
			case PCHAR:
				{
					char ** vDel = (char **)mValue;
					delete vDel;
				}
				break;
			case STRING:
				{
					std::string * vDel = (std::string *)mValue;
					delete vDel;
				}
				break;
			case BOOL:
				{
					bool * vDel = (bool *)mValue;
					delete vDel;
				}
				break;
			case INT:
				{
					int * vDel = (int *)mValue;
					delete vDel;
				}
				break;
			case UINT:
				{
					unsigned int * vDel = (unsigned int *)mValue;
					delete vDel;
				}
				break;
			case SINT:
				{
					short int * vDel = (short int *)mValue;
					delete vDel;
				}
				break;
			case LINT:
				{
					long int * vDel = (long int *)mValue;
					delete vDel;
				}
				break;
			case LLINT:
				{
					long long int * vDel = (long long int *)mValue;
					delete vDel;
				}
				break;
			case DOUBLE:
				{
					double * vDel = (double *)mValue;
					delete vDel;
				}
				break;
			case LDOUBLE:
				{
					long double * vDel = (long double *)mValue;
					delete vDel;
				}
				break;
			case FLOAT:
				{
					float * vDel = (float *)mValue;
					delete vDel;
				}
				break;
			default:
				break;
		}
	}

	std::string Parameter::GetStrValue()
	{
		return mStrValue;
	}

	PType Parameter::GetType()
	{
		return mType;
	}

	std::string GetTypeName(PType pType)
	{
		std::string vStr;

		switch(pType)
		{	
			case CHAR:
				vStr = "char";
				break;
			case PCHAR:
				vStr = "char *";
				break;
			case STRING:
				vStr = "string";
				break;
			case BOOL:
				vStr = "bool";			
				break;
			case INT:
				vStr = "int";
				break;
			case UINT:
				vStr = "unsigned int";
				break;
			case SINT:
				vStr = "short int";
				break;
			case LINT:
				vStr = "long int";
				break;
			case LLINT:
				vStr = "long long int";
				break;
			case DOUBLE:
				vStr = "double";
				break;
			case LDOUBLE:
				vStr = "long double";
				break;
			case FLOAT:
				vStr = "float";
				break;
			default:
				break;
		}
		return vStr;
	}

}
