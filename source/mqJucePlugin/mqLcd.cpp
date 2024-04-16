#include "mqLcd.h"

#include "version.h"

#include "../wLib/lcdfonts.h"

// EW20290GLW display simulation (20*2)

MqLcd::MqLcd(Component& _parent) : Lcd(_parent, 20, 2)
{
	postConstruct();
}

MqLcd::~MqLcd() = default;

void MqLcd::setText(const std::array<uint8_t, 40>& _text)
{
	const std::vector<uint8_t> text{_text.begin(), _text.end()};
	Lcd::setText(text);
}

void MqLcd::setCgRam(std::array<uint8_t, 64>& _data)
{
	Lcd::setCgRam(_data);
}

bool MqLcd::getOverrideText(std::vector<std::vector<uint8_t>>& _lines)
{
	const std::string lineA(std::string("Vavra v") + g_pluginVersionString);
	const std::string lineB = __DATE__ " " __TIME__;

	_lines = 
	{
		std::vector<uint8_t>(lineA.begin(), lineA.end()),
		std::vector<uint8_t>(lineB.begin(), lineB.end())
	};

	return true;
}

const uint8_t* MqLcd::getCharacterData(uint8_t _character) const
{
	return wLib::getCharacterData(_character);
}
