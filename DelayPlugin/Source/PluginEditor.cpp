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
    addAndMakeVisible(systemDelayGroup);
    systemDelayGroup.setText("System Delay");
    
    addAndMakeVisible(systemLatencyTextBox);
    systemLatencyTextBox.setInputRestrictions(3, "0123456789");
    systemLatencyTextBox.setTextToShowWhenEmpty("0", juce::Colours::grey);
    
    addAndMakeVisible(systemLatencyButton);
    systemLatencyButton.setButtonText("Set");
    systemLatencyButton.onClick = [this]()
    {
        juce::String temp = systemLatencyTextBox.getText();
        audioProcessor.systemLatency = temp.getIntValue();
        systemDelayValue.setText(juce::String(audioProcessor.systemLatency), juce::dontSendNotification);
    };
    
    addAndMakeVisible(clearButton);
    clearButton.setButtonText("Clear");
    clearButton.onClick = [this]()
    {
        systemLatencyTextBox.clear();
        audioProcessor.systemLatency = 0;
        systemDelayValue.setText(juce::String(audioProcessor.systemLatency), juce::dontSendNotification);
    };
    
    addAndMakeVisible(systemDelayValue);
    systemDelayValue.setText(juce::String(audioProcessor.systemLatency), juce::dontSendNotification);
    
    addAndMakeVisible(lat10Button);
    lat10Button.setButtonText("10ms");
    lat10Button.setClickingTogglesState(true);
    lat10Button.setColour(juce::TextButton::buttonOnColourId, juce::Colours::green);
    lat10Button.onClick = [this]()
    {
        audioProcessor.addLatency = 10;
        latencyValue.setText(juce::String(audioProcessor.addLatency), juce::dontSendNotification);
        lat15Button.setToggleState(false, juce::dontSendNotification);
        lat20Button.setToggleState(false, juce::dontSendNotification);
        lat25Button.setToggleState(false, juce::dontSendNotification);
        lat30Button.setToggleState(false, juce::dontSendNotification);
    };
    
    addAndMakeVisible(lat15Button);
    lat15Button.setButtonText("15ms");
    lat15Button.setClickingTogglesState(true);
    lat15Button.setColour(juce::TextButton::buttonOnColourId, juce::Colours::green);
    lat15Button.onClick = [this]()
    {
        audioProcessor.addLatency = 15;
        latencyValue.setText(juce::String(audioProcessor.addLatency), juce::dontSendNotification);
        lat10Button.setToggleState(false, juce::dontSendNotification);
        lat20Button.setToggleState(false, juce::dontSendNotification);
        lat25Button.setToggleState(false, juce::dontSendNotification);
        lat30Button.setToggleState(false, juce::dontSendNotification);
    };
    
    addAndMakeVisible(lat20Button);
    lat20Button.setButtonText("20ms");
    lat20Button.setClickingTogglesState(true);
    lat20Button.setColour(juce::TextButton::buttonOnColourId, juce::Colours::green);
    lat20Button.onClick = [this]()
    {
        audioProcessor.addLatency = 20;
        latencyValue.setText(juce::String(audioProcessor.addLatency), juce::dontSendNotification);
        lat10Button.setToggleState(false, juce::dontSendNotification);
        lat15Button.setToggleState(false, juce::dontSendNotification);
        lat25Button.setToggleState(false, juce::dontSendNotification);
        lat30Button.setToggleState(false, juce::dontSendNotification);
    };
    
    addAndMakeVisible(lat25Button);
    lat25Button.setButtonText("25ms");
    lat25Button.setClickingTogglesState(true);
    lat25Button.setColour(juce::TextButton::buttonOnColourId, juce::Colours::green);
    lat25Button.onClick = [this]()
    {
        audioProcessor.addLatency = 25;
        latencyValue.setText(juce::String(audioProcessor.addLatency), juce::dontSendNotification);
        lat10Button.setToggleState(false, juce::dontSendNotification);
        lat15Button.setToggleState(false, juce::dontSendNotification);
        lat20Button.setToggleState(false, juce::dontSendNotification);
        lat30Button.setToggleState(false, juce::dontSendNotification);
    };
    
    addAndMakeVisible(lat30Button);
    lat30Button.setButtonText("30ms");
    lat30Button.setClickingTogglesState(true);
    lat30Button.setColour(juce::TextButton::buttonOnColourId, juce::Colours::green);
    lat30Button.onClick = [this]()
    {
        audioProcessor.addLatency = 30;
        latencyValue.setText(juce::String(audioProcessor.addLatency), juce::dontSendNotification);
        lat10Button.setToggleState(false, juce::dontSendNotification);
        lat15Button.setToggleState(false, juce::dontSendNotification);
        lat20Button.setToggleState(false, juce::dontSendNotification);
        lat25Button.setToggleState(false, juce::dontSendNotification);
    };
    
    addAndMakeVisible(latencyValue);
    latencyValue.setText("n/a", juce::dontSendNotification);
    
    setSize (400, 150);
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
//    const auto X = 100 * JUCE_LIVE_CONSTANT(1.0);
//    const auto Y = 100 * JUCE_LIVE_CONSTANT(1.0);
//    const auto Width = 100 * JUCE_LIVE_CONSTANT(1.0);
//    const auto Hight = 100 * JUCE_LIVE_CONSTANT(1.0);
    
    int adj = 60;
    systemDelayGroup.setBounds(80, 80-adj, 245, 56);
    systemLatencyTextBox.setBounds(100, 100-adj, 50, 23);
    systemLatencyButton.setBounds(160, 100-adj, 50, 23);
    clearButton.setBounds(220, 100-adj, 50, 23);
    systemDelayValue.setBounds(280, 100-adj, 50, 23);
    
    lat10Button.setBounds(40, 160-adj, 50, 23);
    lat15Button.setBounds(100, 160-adj, 50, 23);
    lat20Button.setBounds(160, 160-adj, 50, 23);
    lat25Button.setBounds(220, 160-adj, 50, 23);
    lat30Button.setBounds(280, 160-adj, 50, 23);
    latencyValue.setBounds(340, 160-adj, 50, 23);
}
