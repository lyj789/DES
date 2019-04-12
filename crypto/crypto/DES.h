#pragma once
#include<iostream>
#include <bitset>
#define  b64 bitset<64>
#define b56 bitset<56>
#define b28 bitset<28>
#define b48 bitset<48>
#define b32 bitset<32>
using namespace std;

class DES
{
	b64 k;
	b64 m;

public:
	DES( b64 k);
	b64 E_DES(b64 m);
	b64 D_DES(b64 c);

	template <int P,int Q>
	bitset<Q> Reverse(bitset<P> k, int table[Q]);

	template<int P>
	bitset<P> movemove(bitset<P> k,int shift);

	b32 f(b32 R, int E[48], b48 Key, int S_Box[8][4][16]);
};

template<int P, int Q>
inline bitset<Q> DES::Reverse(bitset<P> k, int table[Q])
{
	bitset<Q> temp;

	for (int i = 0; i < Q; i++)
	{
		temp[Q - i - 1] = k[P - table[i]];
	}

	return temp;
}

template<int P>
inline bitset<P> DES::movemove(bitset<P> k, int shift)
{
	bitset<P> temp;
	temp =( k << shift)|(k >> P-shift);
	return temp;
}
