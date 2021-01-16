/* 762. Prime Number of Set Bits in Binary Representation

Given two integers L and R, find the count of numbers in the range [L, R] (inclusive) having a prime number of set bits in their binary representation.

(Recall that the number of set bits an integer has is the number of 1s present when written in binary. 
For example, 21 written in binary is 10101 which has 3 set bits. Also, 1 is not a prime.)
*/
#include <iostream>
int countPrimeSetBits(int L, int R);
//bool isPrime(int n);
//int countOnes(int n);

int main()
{
	int L = 10, R = 15;
	std::cout << countPrimeSetBits(L,R);
	return 0;
}
int countPrimeSetBits(int L, int R) {
int ans = 0;
	for (int i = L; i <= R; i++)
{
	int temp = i, cn = 0;
	while (temp)
	{
		temp = temp & (temp - 1);
		cn++;
	}
	if (cn == 2 || cn == 3 || cn == 5 || cn == 7 || cn == 11 || cn == 13 || cn == 17 || cn == 19)
		ans++;
}
	return ans;
}

/*int countPrimeSetBits(int L, int R) {
	int count = 0;
	for (int i = L; i <= R; i++) {
		if (isPrime(countOnes(i))) {
			count++;
		}
	}
	return count;
}

bool isPrime(int n) {
	if (n == 0 || n == 1) {
		return false;
	}
	else {
		for (int i = 2; i < n; i++) {
			if (n % i == 0) {
				return false;
			}
		}
	}
	return true;
}

int countOnes(int n) {
	int count = 0; 

	while (n != 0) {
		count++;
		n = n & (n - 1);
	}
	return count;
}*/
