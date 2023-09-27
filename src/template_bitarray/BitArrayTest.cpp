
#include <iostream>
#include "BitArray.hpp" 


static void PrintInBinary(BitArray<256UL> ba, size_t size);

int main()
{
	BitArray<256> ba;

	/* ba[62] = true;

	if (ba[62] != true)
	{
		std::cout << "Test Failed on line " << __LINE__ << std::endl;
	}

	ba[256] = ba[62];

	if(!(ba[256] == ba[62]))
	{
		std::cout << "Doest this works??" << __LINE__ << std::endl;
	}

	if (true != ba[256])
	{
		std::cout << "Test Failed on line " << __LINE__ << std::endl;
	}

	bool bul = ba[256];

	if (bul != true)
	{
		std::cout << "Test Failed on line " << __LINE__ << std::endl;
	}
	
	const BitArray<128> bb(ba);

	bul = bb[256];

	if (bul != true)
	{
		std::cout << "Test Failed on line " << __LINE__ << std::endl;
	}

	ba[256] = false;

	if (ba[256] != false)
	{
		std::cout << "Test Failed on line " << __LINE__ << std::endl;
	}

	// bb[2] = true; */

	/* for (size_t i = 0; i < 3 ; ++i)
	{
		ba[i] = true;
	} */
	/* for (size_t i = 64; i < 67 ; ++i)
	{
		ba[i] = true;
	}
 */
	ba[0]= true;
	ba[3]= true;
	ba[66]= true;
	ba[67]= true;

	std::cout << ba.GetLit() << std::endl;

	PrintInBinary(ba,256);


	
	ba <<= 5;
	std::cout << "This is after the first shift yay" << std::endl;
	std::cout << "there " << std::endl;


	PrintInBinary(ba,256);
	
	ba <<= 65;
	std::cout << "This is after second shift yay" << std::endl;
	
	PrintInBinary(ba,256);

	
	return 0;
}

static void PrintInBinary(BitArray<256UL> ba, size_t size)
{
	for (size_t i = size; 0 < i ; --i)
	{
		if(i%64 == 0)
		{
			std::cout << "Next Size_t" << std::endl;
		}
		std::cout << ba[i];
	}
	std::cout << std::endl;}
