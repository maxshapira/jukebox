#pragma once
#include <codecvt>
#include <string>



namespace jukebox {
	inline std::string WstrToStr(const std::wstring& wstr){
		//setup converter
		using convert_type = std::codecvt_utf8<wchar_t>;
		std::wstring_convert<convert_type, wchar_t> converter;

		//use converter (.to_bytes: wstr->str, .from_bytes: str->wstr)
		std::string converted_str = converter.to_bytes(wstr);

		return converted_str;
	}
}