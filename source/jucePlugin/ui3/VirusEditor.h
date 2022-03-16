#pragma once

#include "../genericUI/editor.h"

#include "Parts.h"
#include "Tabs.h"
#include "FxPage.h"
#include "MidiPorts.h"
#include "PatchBrowser.h"

class AudioPluginAudioProcessor;

namespace genericVirusUI
{
	class VirusEditor : public genericUI::Editor
	{
	public:
		VirusEditor(VirusParameterBinding& _binding, Virus::Controller& _controller, AudioPluginAudioProcessor &_processorRef);

		void setPart(size_t _part);

		AudioPluginAudioProcessor& getProcessor() { return m_processor; }

	private:
		void onProgramChange();
		void onPlayModeChanged();
		void onCurrentPartChanged();

		void mouseDrag(const juce::MouseEvent& event) override;
		void mouseEnter(const juce::MouseEvent& event) override;
		void mouseExit(const juce::MouseEvent& event) override;
		void mouseUp(const juce::MouseEvent& event) override;

		void updateControlLabel(juce::Component* _component) const;
		void updatePresetName() const;
		void updatePlayModeButtons() const;

		void savePreset();
		void loadPreset();

		void setPlayMode(uint8_t _playMode);

		AudioPluginAudioProcessor& m_processor;

		Parts m_parts;
		Tabs m_tabs;

		juce::Label* m_presetName = nullptr;
		juce::Label* m_controlLabel = nullptr;
		juce::ComboBox* m_romSelector = nullptr;

		juce::Button* m_playModeSingle = nullptr;
		juce::Button* m_playModeMulti = nullptr;

		juce::TooltipWindow m_tooltipWindow;

		MidiPorts m_midiPorts;
		FxPage m_fxPage;
		PatchBrowser m_patchBrowser;

		std::unique_ptr<juce::FileChooser> m_fileChooser;
		juce::String m_previousPath;
	};
}