#include "String.h"
#include <cstring>
#include <cctype>
#include <iostream>

String::String() : m_str(nullptr), m_length(0), m_capacity(0)
{

}

String::String(const char* _str)
{
	m_length = strlen(_str);
	m_capacity = m_length + 1;
	m_str = new char[m_capacity];
	strcpy_s(m_str, m_capacity, _str);
}

String::String(const String& _other)
{
	m_length = _other.m_length;
	m_capacity = _other.m_capacity;
	m_str = new char[m_capacity];
	strcpy_s(m_str, m_capacity, _other.m_str);
}

String::~String()
{
	delete[] m_str;
}

size_t String::Length() const
{
	return m_length;
}

char String::CharacterAt(size_t _index)
{
	if (_index > 0 && _index < m_length) {
		return m_str[_index];
	}
	else {
		return '\0';
	}
}

const char String::CharacterAt(size_t _index) const
{
	if (_index > 0 && _index < m_length) {
		return m_str[_index];
	}
	else {
		return '\0';
	}
}

bool String::EqualTo(const String& _other) const
{
	return strcmp(_other.m_str, m_str) == 0;
}

String& String::Append(const String& _str)
{
	const size_t catLength = _str.m_length + m_length;
	char* temp = new char[catLength + 1];

	strcpy_s(temp, catLength + 1, m_str);
	strcat_s(temp, catLength + 1, _str.m_str);

	delete[] m_str;

	m_length = catLength;
	m_capacity = catLength + 1;
	m_str = new char[m_capacity];

	strcpy_s(m_str, m_capacity, temp);

	return *this;
}

String& String::Prepend(const String& _str)
{
	const size_t catLength = _str.m_length + m_length;
	char* temp = new char[catLength + 1];

	strcpy_s(temp, catLength + 1, _str.m_str);
	strcat_s(temp, catLength + 1, m_str);

	delete[] m_str;

	m_length = catLength;
	m_capacity = catLength + 1;
	m_str = new char[m_capacity];

	strcpy_s(m_str, m_capacity, temp);

	return *this;
}

const char* String::CStr() const
{
	return m_str;
}

String& String::ToLower()
{
	for (int i = 0; i < m_length; i++) {
		m_str[i] = tolower(m_str[i]);
	}

	return *this;
}

String& String::ToUpper()
{
	for (int i = 0; i < m_length; i++) {
		m_str[i] = toupper(m_str[i]);
	}

	return *this;
}

size_t String::Find(const String& _str)
{
	size_t result = strstr(m_str, _str.m_str) - m_str;

	return (result > m_capacity || result < 0 ? SIZE_MAX : result);
}

size_t String::Find(size_t _startIndex, const String& _str)
{
	for (size_t i = _startIndex; i < m_length - _str.m_length; i++) {
		if (strncmp(m_str + i, _str.m_str, _str.m_length) == 0) {
			return i;
		}
	}

	return -1;
}

String& String::Replace(const String& _find, const String& _replace)
{
	size_t subStrIndex = Find(_find);

	if (subStrIndex == SIZE_MAX) {
		return *this;
	}

	size_t concatLength = m_length - _find.m_length + _replace.m_length;
	char* concatResult = new char[concatLength + 1];

	// Copy m_str into the temporary array
	memcpy(concatResult, m_str, concatLength);
	// Copy the replacement string into the temp array at the index where the find string begins
	strcpy_s(concatResult + subStrIndex, concatLength + 1 - subStrIndex, _replace.m_str);
	// Copy the end of the original string into the temp array
	strcpy_s(concatResult + subStrIndex + _replace.m_length, concatLength + 1 - subStrIndex - _replace.m_length, m_str + subStrIndex + _find.m_length);

	delete[] m_str;

	m_length = concatLength;
	m_capacity = m_length + 1;
	m_str = new char[m_capacity];

	strcpy_s(m_str, m_capacity, concatResult);

	return *this;
}

String& String::ReadFromConsole()
{
	char buffer[256];
	delete[] m_str;

	std::cin.getline(buffer, 256);

	m_length = strlen(buffer);
	m_capacity = m_length + 1;
	m_str = new char[m_capacity];

	strcpy_s(m_str, (m_length + 1) * sizeof(char), buffer);

	return *this;
}

String& String::WriteToConsole()
{
	if (m_str == nullptr)
		return *this;

	std::cout << m_str << std::endl;

	return *this;
}

bool String::operator==(const String& _other)
{
	return EqualTo(_other);
}

bool String::operator!=(const String& _other)
{
	return !EqualTo(_other);
}

String& String::operator=(const String& _str)
{
	delete[] m_str;

	m_length = _str.m_length;
	m_capacity = _str.m_capacity;
	m_str = new char[m_capacity];

	strcpy_s(m_str, sizeof(char) * (_str.m_length + 1), _str.m_str);

	return *this;
}

String String::operator+(const String& _str)
{
	String result(m_str);
	result.Append(_str.CStr());

	return result;
}

String& String::operator+=(const String& _str)
{
	Append(_str);

	return *this;
}

char& String::operator[](size_t _index)
{
	char charResult = CharacterAt(_index);

	return charResult;
}

const char& String::operator[](size_t _index) const
{
	char charResult = CharacterAt(_index);

	return charResult;
}
