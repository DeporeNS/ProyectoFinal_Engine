#include "UTFManager.h"
#include <codecvt>
#include <io.h>
#include <fcntl.h>
#include <comdef.h>

namespace ProyectoFinal {
	UTFManager::UTFManager() {
		_setmode(_fileno(stdout), _O_U8TEXT);
		string = L"";
	}

	UTFManager::UTFManager(const char* s) {
		_setmode(_fileno(stdout), _O_U8TEXT);
		string = convert(s);

	}

	UTFManager::UTFManager(const wchar_t* s) {
		_setmode(_fileno(stdout), _O_U8TEXT);
		string = s;
	}

	UTFManager::UTFManager(std::string s) {
		_setmode(_fileno(stdout), _O_U8TEXT);
		string = convert(s);
	}

	UTFManager::UTFManager(std::wstring& s) {
		_setmode(_fileno(stdout), _O_U8TEXT);
		string = s;
	}

	void UTFManager::Set(std::string s) {
		string = convert(s);
	}

	std::wstring UTFManager::Get() {
		return string;
	}
	//
	const char* UTFManager::GetChar() {
		return toString().c_str();
	}

	void UTFManager::Print() {
		std::wcout << string << std::endl;
	}

	bool UTFManager::operator==(std::string& s) {
		return string == convert(s);
	}

	bool UTFManager::operator==(UTFManager s) {
		return string == s.Get();
	}

	void UTFManager::operator=(UTFManager s) {
		string = s.Get();
	}

	void UTFManager::operator=(std::string& s) {
		string = convert(s);
	}

	UTFManager UTFManager::operator+(UTFManager& s) {
		return UTFManager(string += s.Get());
	}

	UTFManager UTFManager::operator+(const char* s) {
		if (s != NULL)
			return UTFManager(string += convert(s));
		else
			return UTFManager(string);
	}

	UTFManager UTFManager::operator+(const char s) {
		return UTFManager(string += convert(&s));
	}

	UTFManager UTFManager::operator+(std::string& s) {
		return UTFManager(string += convert(s));
	}

	void UTFManager::operator+=(std::string& s) {
		string += convert(s);
	}

	void UTFManager::operator+=(UTFManager& s) {
		string += s.string;
	}

	void UTFManager::operator+=(const char* s) {
		if (s != NULL)
			string += convert(s);
	}

	void UTFManager::operator+=(const char s) {
		if (s != NULL)
			string += convert(&s);
	}

	void UTFManager::operator+=(wchar_t* s) {
		if (s != NULL)
			string += s;
	}

	bool UTFManager::operator>(UTFManager s) {
		return string > s.Get();
	}

	bool UTFManager::operator<(UTFManager s) {
		return string < s.Get();
	}

	bool UTFManager::operator!=(UTFManager& s) {
		return string != s.Get();
	}

	std::wstring UTFManager::convert(const std::string& input) {
		try
		{
			std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
			std::wstring temp = converter.from_bytes(input);
			return temp;
		}
		catch (std::range_error & e)
		{
			size_t length = input.length();
			std::wstring result;
			result.reserve(length);
			for (size_t i = 0; i < length; i++)
			{
				result.push_back(input[i] & 0xFF);
			}
			return result;
		}
		catch (...) {

		}
	}

	std::string UTFManager::toString() {
		using convert_typeX = std::codecvt_utf8<wchar_t>;
		std::wstring_convert<convert_typeX, wchar_t> converterX;

		return converterX.to_bytes(string);
	}
}