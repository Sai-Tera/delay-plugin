/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DelayPluginAudioProcessorEditor::DelayPluginAudioProcessorEditor (DelayPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    addAndMakeVisible(peerNumTextBox);
    
    addAndMakeVisible(systemLatencyTextBox);
    systemLatencyTextBox.setInputRestrictions(3, "0123456789");
    
    addAndMakeVisible(systemLatencyButton);
    systemLatencyButton.setButtonText("Set");
    systemLatencyButton.onClick = [this]()
    {
        juce::String temp = systemLatencyTextBox.getText();
        audioProcessor.systemLatency = temp.getIntValue();
    };
                                    
    addAndMakeVisible(clearButton);
    clearButton.setButtonText("Clear");
    clearButton.onClick = [this]()
    {
        systemLatencyTextBox.clear();
        audioProcessor.systemLatency = 0;
    };
    
    addAndMakeVisible(lat10Button);
    lat10Button.setButtonText("10ms");
    lat10Button.onClick = [this](){audioProcessor.addLatency = 10;};
    
    addAndMakeVisible(lat15Button);
    lat15Button.setButtonText("15ms");
    lat15Button.onClick = [this](){audioProcessor.addLatency = 15;};
    
    addAndMakeVisible(lat20Button);
    lat20Button.setButtonText("20ms");
    lat20Button.onClick = [this](){audioProcessor.addLatency = 20;};
    
    addAndMakeVisible(lat25Button);
    lat25Button.setButtonText("25ms");
    lat25Button.onClick = [this](){audioProcessor.addLatency = 25;};
    
    addAndMakeVisible(lat30Button);
    lat30Button.setButtonText("30ms");
    lat30Button.onClick = [this](){audioProcessor.addLatency = 30;};

    setSize (400, 300);
}

DelayPluginAudioProcessorEditor::~DelayPluginAudioProcessorEditor()
{
}

//==============================================================================
void DelayPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));


}

void DelayPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    peerNumTextBox.setBounds(100, 40, 50, 23);
    systemLatencyTextBox.setBounds(100, 100, 50, 23);
    systemLatencyButton.setBounds(160, 100, 50, 23);
    clearButton.setBounds(220, 100, 50, 23);
    

    lat10Button.setBounds(40, 160, 50, 23);
    lat15Button.setBounds(100, 160, 50, 23);
    lat20Button.setBounds(160, 160, 50, 23);
    lat25Button.setBounds(220, 160, 50, 23);
    lat30Button.setBounds(280, 160, 50, 23);
}
