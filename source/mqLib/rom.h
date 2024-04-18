#pragma once

#include "../wLib/wRom.h"

namespace mqLib
{
	class ROM final : public wLib::ROM
	{
	public:
		static constexpr uint32_t g_romSize = 524288;

		explicit ROM(const std::string& _filename, const uint8_t* _data = nullptr) : wLib::ROM(_filename, g_romSize, _data)
		{
		}

		static constexpr uint32_t size() { return g_romSize; }

		uint32_t getSize() const override { return g_romSize; }
	};
}