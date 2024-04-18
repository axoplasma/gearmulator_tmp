#pragma once

#include <cstdint>

#include "../wLib/wMidiTypes.h"

namespace xt
{
	enum MidiHeaderByte : uint8_t
	{
		IdMw2 = 0x0e,
	};

	enum class SysexCommand : uint8_t
	{
		Invalid = 0xff,

		SingleRequest     = 0x00, SingleDump    = 0x10, SingleParameterChange    = 0x20, SingleStore    = 0x30, SingleRecall    = 0x40, SingleCompare    = 0x50,
		MultiRequest      = 0x01, MultiDump     = 0x11, MultiParameterChange     = 0x21, MultiStore     = 0x31, MultiRecall     = 0x41, MultiCompare     = 0x51,
		WaveRequest	      = 0x02, WaveDump      = 0x12, WaveParameterChange      = 0x22, WaveStore      = 0x32, WaveRecall      = 0x42, WaveCompare      = 0x52,
		WaveCtlRequest	  = 0x03, WaveCtlDump   = 0x13, WaveCtlParameterChange   = 0x23, WaveCtlStore   = 0x33, WaveCtlRecall   = 0x43, WaveCtlCompare   = 0x53,
		GlobalRequest     = 0x04, GlobalDump    = 0x14, GlobalParameterChange    = 0x24, GlobalStore    = 0x34, GlobalRecall    = 0x44, GlobalCompare    = 0x54,
		DisplayRequest    = 0x05, DisplayDump   = 0x15, DisplayParameterChange   = 0x25, DisplayStore   = 0x35, DisplayRecall   = 0x45, DisplayCompare   = 0x55,
		RemoteCtlRequest  = 0x06, RemoteCtlDump = 0x16, RemoteCtlParameterChange = 0x26, RemoteCtlStore = 0x36, RemoteCtlRecall = 0x46, RemoteCtlCompare = 0x56,
		ModeRequest       = 0x07, ModeDump      = 0x17, ModeParameterChange      = 0x27, ModeStore      = 0x37, ModeRecall      = 0x47, ModeCompare      = 0x57,
		InfoRequest       = 0x08, InfoDump      = 0x18, InfoParameterChange      = 0x28, InfoStore      = 0x38, InfoRecall      = 0x48, InfoCompare      = 0x58,

		EmuLCD = 0x60,
		EmuLEDs = 0x61,
		EmuButtons = 0x62,
		EmuRotaries = 0x63
	};

	enum class LocationH : uint8_t
	{
		// Single Dump
		SingleBankA = 0x00,
		SingleBankB = 0x01,
		AllSingles  = 0x10,
		SingleEditBufferSingleMode = 0x20,
		SingleEditBufferMultiMode = 0x30,

		// Multi Dump
		MultiBankA = 0x00,
		AllMultis = 0x10,
		MultiDumpMultiEditBuffer = 0x20,
	};

	enum SysexIndex
	{
		// first parameter of a dump
		IdxSingleParamFirst = 7,
		IdxSingleChecksumStart = IdxSingleParamFirst,
		IdxMultiParamFirst  = IdxSingleParamFirst,
		IdxGlobalParamFirst = wLib::IdxBuffer,
		IdxModeParamFirst = wLib::IdxBuffer,

		IdxSingleParamIndexH = wLib::IdxBuffer + 1,
		IdxSingleParamIndexL = IdxSingleParamIndexH + 1,
		IdxSingleParamValue  = IdxSingleParamIndexL + 1,

		IdxMultiParamIndexH = wLib::IdxBuffer,
		IdxMultiParamIndexL = IdxMultiParamIndexH + 1,
		IdxMultiParamValue  = IdxMultiParamIndexL + 1,

		IdxGlobalParamIndexH = wLib::IdxBuffer,
		IdxGlobalParamIndexL = IdxGlobalParamIndexH + 1,
		IdxGlobalParamValue  = IdxGlobalParamIndexL + 1,

		IdxModeParamIndexH = wLib::IdxBuffer,
		IdxModeParamIndexL = IdxModeParamIndexH,
		IdxModeParamValue  = wLib::IdxBuffer
	};

	enum class GlobalParameter
	{
		Reserved0,
		Version,
		StartupSoundbank,
		StartupSoundNum,
		MidiChannel,
		ProgramChangeMode,
		DeviceId,
		BendRange,
		ControllerW,
		ControllerX,
		ControllerY,
		ControllerZ,
		MainVolume,
		Reserved13,
		Reserved14,
		Transpose,
		MasterTune,
		DisplayTimeout,
		LcdContrast,
		Reserved19,
		Reserved20,
		Reserved21,
		Reserved22,
		StartupMultiNumber,
		ArpNoteOutChannel,
		MidiClockOutput,
		ParameterSend,
		ParameterReceive,
		InputGain,
		Reserved29,
		Reserved30,
		Reserved31
	};

	enum class ModeParameter
	{
		Mode = 0	// 0 = Single, 1 = Multi
	};
}