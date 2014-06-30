
#include <iostream>
#include<string>
#include<cstdlib>
#ifndef BIGINTS_H
#define BIGINTS_H

using std::ostream;

class BigInt
{
private:
	unsigned short* number_;	//ptr to an array on the heap
	unsigned length_;			// size of array

	void checkformat( const BigInt& BI );				//placed in try block
	void err_handle(const unsigned short& err_id );		//placed in catch block

public:
	
	BigInt();
	BigInt( const BigInt& BI );
	BigInt( const int& n );
	BigInt( const long& n );
	BigInt( const long long& n );
	~BigInt();
	
	BigInt& operator = (const BigInt& BI);
	BigInt& operator = (const int& n);
	BigInt& operator = (const long& n);
	BigInt& operator = (const long long& n);
	// BigInt& operator + (const BigInt& BI); //To Do

	unsigned short* getnumaddress() const;		//for debuging
	ostream& tostream(ostream& os);				// ostream helper function

	unsigned length() const;					//return number of elements				
	unsigned short at( const unsigned& position ) const;	//element access at 'position'

};

ostream& operator << ( ostream& os, BigInt& BI );

#endif
//Constructors / Destructor
BigInt::BigInt():
length_(0),
number_(NULL)
{
}

BigInt::BigInt(const BigInt& BI)
{
	length_ = BI.length();
	number_ = new unsigned short[ length_ ];
	*this = BI;

	try { checkformat(*this); }
	catch(unsigned short err) { err_handle(err); }
}

BigInt::BigInt(const int& n)
{
	long long ncpy = n;
	std::string num = std::to_string(ncpy);
	length_ = num.length();
	number_ = new unsigned short [length_];

	for(unsigned i=0; i<length_; i++) number_[i] = (num[i] - '0');

	try { checkformat(*this); }
	catch(unsigned short err) { err_handle(err); }
}

BigInt::BigInt(const long& n)
{
	long long ncpy = n;
	std::string num = std::to_string(ncpy);
	length_ = num.length();
	number_ = new unsigned short [length_];

	for(unsigned i=0; i<length_; i++) number_[i] = (num[i] - '0');

	try { checkformat(*this); }
	catch(unsigned short err) { err_handle(err); }
}

BigInt::BigInt(const long long& n)
{
	long long ncpy = n;
	std::string num = std::to_string(ncpy);
	length_ = num.length();
	number_ = new unsigned short [length_];

	for(unsigned i=0; i<length_; i++) number_[i] = (num[i] - '0');

	try { checkformat(*this); }
	catch(unsigned short err) { err_handle(err); }
}

BigInt::~BigInt()
{
	if( number_ ) delete [] number_;
}

//Exception Handling
void BigInt::checkformat( const BigInt& BI )
{
	for(unsigned i=0; i<length_; i++)
	{
		if( number_[i]<0 || number_[i]>9 ) throw unsigned short(1);
	}
}

void BigInt::err_handle( const unsigned short& err_id )
{
	switch( err_id )
	{
	case 1:
		std::cerr << "Improperly formatted data, error " << err_id << std::endl;
		break;
	default:
		break;
	}
}

//Operator Overloads

BigInt& BigInt::operator = ( const BigInt& BI )
{
	if( this!=&BI )
	{
		delete [] number_;
		length_ = BI.length();
		new unsigned short [length_];

		for(unsigned i=0; i<length_; i++) number_[i] = BI.at(i);
	}
	return *this;
}

BigInt& BigInt::operator = (const int& n)
{
	BigInt temp(n);
	*this = temp;
	return *this;
}

BigInt& BigInt::operator = (const long& n)
{
	BigInt temp(n);
	*this = temp;
	return *this;
}

BigInt& BigInt::operator = (const long long& n)
{
	BigInt temp(n);
	*this = temp;
	return *this;
}

ostream& BigInt::tostream(ostream& os)
{
	for( unsigned i=0; i<length_; i++) os << number_[i];
	return os;
}

ostream& operator << ( ostream& os, BigInt& BI)
{
	return BI.tostream(os);
}


//other member functions
unsigned BigInt::length() const
{
	return length_;
}

unsigned short BigInt::at( const unsigned& position) const
{
	return position>length_ ? NULL : number_[position];
}

unsigned short* BigInt::getnumaddress() const
{
	return number_;
}
