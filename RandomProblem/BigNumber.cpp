#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN = 1000;

class BigNumber{
public:
	int len, s[MAXN];
public:
	void cleanLeadZero();
	void multiplyTen(int n);
	void divisionTen(int n);
	string str() const;
	BigNumber();
	BigNumber(int n);
	BigNumber(const char *);
	~BigNumber();
	BigNumber getSub(int n)const;
	BigNumber operator=(const char *);
	BigNumber operator=(int num);
	BigNumber operator + (const BigNumber &) const;
	BigNumber operator - (const BigNumber &) const;
	BigNumber operator * (const BigNumber &) const;
	BigNumber operator / (const BigNumber &) const;
	BigNumber operator % (const BigNumber &) const;
	BigNumber operator -= (const BigNumber &);
	BigNumber operator += (const BigNumber &);
	BigNumber operator *= (const BigNumber &);
	BigNumber operator /= (const BigNumber &);
	// 重载比较运算符      
	bool operator < (const BigNumber &) const;
	bool operator > (const BigNumber &) const;
	bool operator <= (const BigNumber &) const;
	bool operator >= (const BigNumber &) const;
	bool operator == (const BigNumber &) const;

	friend istream & operator >> (istream &, BigNumber &);
	friend ostream &operator << (ostream &, BigNumber &);
};


//清楚前导0
void BigNumber::cleanLeadZero(){
	while (len>1 && !s[len - 1])len--;
}

BigNumber::~BigNumber(){
	this->len = 0;
}
//
void BigNumber::divisionTen(int n){
	int i;
	if (n>len){
		while (len >= 1)s[len--] = 0;
	}
	else{
		for (i = 0; i<len - n; i++)s[i] = s[i + n];
		len -= n;
	}
}


void BigNumber::multiplyTen(int n){
	if (n>0){
		int i;
		for (i = len - 1; i >= 0; i--)s[i + n] = s[i];
		for (i = 0; i<n; i++)s[i] = 0;
		len += n;
	}
}



string BigNumber::str()const{
	string res = "";
	for (int i = 0; i<len; i++){
		res = (char)(s[i] + '0') + res;
	}
	if (res == "")res = "0";
	return res;
}

BigNumber::BigNumber(){
	memset(s, 0, sizeof(s));
	len = 1;
}

BigNumber::BigNumber(int num){
	*this = num;
}

BigNumber::BigNumber(const char*num){
	*this = num;
}

BigNumber BigNumber::getSub(int n)const{
	BigNumber c;
	c.len = 0;
	for (int i = 0; i<n; i++)c.s[c.len++] = s[len - n + i];
	return c;
}

BigNumber BigNumber::operator =(const char *num){
	len = strlen(num);
	for (int i = 0; i<len; i++)s[i] = num[len - i - 1] - '0';
	return *this;
}

BigNumber BigNumber::operator=(int num){
	char s[MAXN];
	sprintf(s, "%d", num);
	*this = s;
	return *this;
}

BigNumber BigNumber::operator+(const BigNumber & x)const{
	BigNumber r;
	r.len = 0;
	int i, up;
	int maxlen = max(len, x.len);
	for (i = 0, up = 0; up || i<maxlen; i++){
		int temp = up;
		if (i<len)temp += s[i];
		if (i<x.len)temp += x.s[i];
		up = temp / 10;
		r.s[r.len++] = temp % 10;
	}
	r.cleanLeadZero();
	return r;
}

BigNumber BigNumber::operator -(const BigNumber & b)const{
	BigNumber c;
	c.len = 0;
	int down;
	for (int i = 0, down = 0; i<len; i++){
		int temp = s[i] - down;
		if (i<b.len)temp -= b.s[i];
		if (temp >= 0)down = 0;
		else{
			down = 1;
			temp += 10;
		}
		c.s[c.len++] = temp;
	}
	c.cleanLeadZero();
	return c;
}

BigNumber BigNumber::operator*(const BigNumber & b)const{
	int i, j;
	BigNumber c;
	c.len = len + b.len;
	for (i = 0; i<len; i++){
		for (j = 0; j<b.len; j++)
			c.s[i + j] += s[i] * b.s[j];
	}
	for (i = 0; i<c.len; i++){
		c.s[i + 1] += c.s[i] / 10;
		c.s[i] %= 10;
	}
	c.cleanLeadZero();
	return c;
}


BigNumber BigNumber::operator/(const BigNumber &b)const{
	int i, j;
	BigNumber r;
	r.len = 0;
	BigNumber temp = this->getSub(b.len - 1);
	for (i = len - b.len; i >= 0; i--){
		temp = temp * 10 + s[i];
		if (temp<b)r.s[r.len++] = 0;
		else{
			for (j = 1; j <= 10; j++){
				if (b*j>temp)break;
			}
			r.s[r.len++] = j - 1;
			temp = temp - (b*(j - 1));
		}
	}
	for (i = 0; i<r.len / 2; i++){
		int temp = r.s[i];
		r.s[i] = r.s[r.len - i - 1];
		r.s[r.len - 1 - i] = temp;
	}
	r.cleanLeadZero();
	return r;
}


BigNumber BigNumber::operator%(const BigNumber &b)const{
	BigNumber r;
	r = *this / b;
	r = *this - r*b;
	return r;
}

BigNumber BigNumber::operator+=(const BigNumber &b){
	*this = *this + b;
	return *this;
}


BigNumber BigNumber::operator -= (const BigNumber & b){
	*this = *this - b;
	return *this;
}
BigNumber BigNumber::operator *= (const BigNumber & b){
	*this = *this * b;
	return *this;
}

BigNumber BigNumber::operator /= (const BigNumber & b){
	*this = *this / b;
	return *this;
}

bool BigNumber::operator<(const BigNumber &b) const{
	if (len != b.len)return len<b.len;
	else{
		for (int i = len - 1; i>-0; i--)
		if (s[i] != b.s[i])return s[i]<b.s[i];
	}
	return false;
}


bool BigNumber::operator > (const BigNumber & b) const{
	return b < *this;
}

bool BigNumber::operator <= (const BigNumber & b) const{
	return !(b > *this);
}

bool BigNumber::operator >= (const BigNumber & b) const{
	return !(*this < b);
}

bool BigNumber::operator == (const BigNumber & b) const{
	return !(b < *this) && !(b > *this);
}

istream & operator >>(istream & in, BigNumber & x){
	string s;
	in >> s;
	x = s.c_str();
	return in;
}

ostream & operator<<(ostream & out, BigNumber & x){
	out << x.str();
	return out;
}