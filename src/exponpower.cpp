//============================================================================
// Name        : Test.cpp
// Author      : Serg
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
using namespace std;
typedef unsigned long long int U32;
typedef unsigned char U8;

typedef struct
{
	U32 b;
	U32 p;
	U32 m;
	U32 expected_answer;
}testStruct;

constexpr U32 exponmod(U32 b, U32 p, U32 m)
{
	U32 result = 1u;

	while(p != 0u)
	{
		if (p & 1u) /* handles odd number case */
		{
			result = (result * b) % m;
		}
		p >>= 1u;
		b = (b * b) % m;
	}

    return result;
}

static_assert(exponmod(1u, 1u, 1u) == 0u, "Failed test 1" );
static_assert(exponmod(999999999u, 999999u, 999999999u) == 0u, "Failed test 2" );
static_assert(exponmod(3u, 200u, 50u) == 1u, "Failed test 3");
static_assert(exponmod(4u, 13u, 497u) == 445u, "Failed test 4");
static_assert(exponmod(455u, 25890u, 3245u) == 375u, "Failed test 5");
static_assert(exponmod(2u, 35236u, 35237u) == 2286u, "Failed test 6");
static_assert(exponmod(999999500u, 999999u, 999999999u) == 307944260u, "Failed test 6");


int main(void)
{
    cout << exponmod(999999500u, 999999u, 999999999u) << endl;
}

