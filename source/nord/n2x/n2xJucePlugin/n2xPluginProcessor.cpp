#include "n2xPluginProcessor.h"

#include "n2xController.h"
#include "n2xPluginEditorState.h"

// ReSharper disable once CppUnusedIncludeDirective
#include "BinaryData.h"
#include "jucePluginLib/processorPropertiesInit.h"

#include "n2xLib/n2xdevice.h"
#include "n2xLib/n2xromloader.h"

#include "synthLib/deviceException.h"

namespace
{
	juce::PropertiesFile::Options getOptions()
	{
		juce::PropertiesFile::Options opts;
		opts.applicationName = "DSP56300EmulatorNodalRed";
		opts.filenameSuffix = ".settings";
		opts.folderName = "DSP56300EmulatorNodalRed";
		opts.osxLibrarySubFolder = "Application Support/DSP56300EmulatorNodalRed";
		return opts;
	}
}

namespace n2xJucePlugin
{
	class Controller;

	AudioPluginAudioProcessor::AudioPluginAudioProcessor() :
	    Processor(BusesProperties()
	                   .withOutput("Out AB", juce::AudioChannelSet::stereo(), true)
	                   .withOutput("Out CD", juce::AudioChannelSet::stereo(), true)
		, getOptions(), pluginLib::initProcessorProperties())
	{
		getController();
		const auto latencyBlocks = getConfig().getIntValue("latencyBlocks", static_cast<int>(getPlugin().getLatencyBlocks()));
		Processor::setLatencyBlocks(latencyBlocks);
	}

	AudioPluginAudioProcessor::~AudioPluginAudioProcessor()
	{
		destroyEditorState();
	}

	jucePluginEditorLib::PluginEditorState* AudioPluginAudioProcessor::createEditorState()
	{
		return new PluginEditorState(*this);
	}

	synthLib::Device* AudioPluginAudioProcessor::createDevice()
	{
		auto* d = new n2x::Device({});
		if(!d->isValid())
			throw synthLib::DeviceException(synthLib::DeviceError::FirmwareMissing, "A firmware rom (512k .bin) is required, but was not found.");
		return d;
	}

	void AudioPluginAudioProcessor::getRemoteDeviceParams(synthLib::DeviceCreateParams& _params) const
	{
		Processor::getRemoteDeviceParams(_params);

		auto rom = n2x::RomLoader::findROM();

		if(rom.isValid())
		{
			_params.romData.assign(rom.data().begin(), rom.data().end());
			_params.romName = rom.getFilename();
		}
	}

	pluginLib::Controller* AudioPluginAudioProcessor::createController()
	{
		return new n2xJucePlugin::Controller(*this);
	}
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new n2xJucePlugin::AudioPluginAudioProcessor();
}
