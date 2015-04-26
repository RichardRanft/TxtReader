#include "SpeechSynthesizer.h"
#include <Windows.h>
#include <sapi.h>
#include <sperror.h>
#include <sphelper.h>
#include <string>
#include <list>

CSpeechSynthesizer::CSpeechSynthesizer()
{
	m_initialized = false;
}

CSpeechSynthesizer::~CSpeechSynthesizer()
{
}

bool CSpeechSynthesizer::IsInitialized()
{
	return m_initialized;
}

void CSpeechSynthesizer::Initialize()
{
	CoInitialize(cpIEnum);

	// Enumerate voice tokens that speak US English in a female voice.
	HRESULT hr = SpEnumTokens(SPCAT_VOICES, L"Language=409", L"Gender=Female;", &cpIEnum);

	// Get the best matching token.
	if (SUCCEEDED(hr))
	{
		hr = cpIEnum->Next(1, &cpToken, NULL);
	}

	// Create a voice and set its token to the one we just found.
	if (SUCCEEDED(hr))
	{
		hr = cpVoice.CoCreateInstance(CLSID_SpVoice);
	}

	// Set the voice.
	if (SUCCEEDED(hr))
	{
		hr = cpVoice->SetVoice(cpToken);
	}

	// Set the output to the default audio device.
	if (SUCCEEDED(hr))
	{
		hr = cpVoice->SetOutput(NULL, TRUE);
	}

	m_initialized = true;
}

void CSpeechSynthesizer::SpeakText(_TCHAR* text)
{
	// Speak a string directly.
	if (m_initialized && text != NULL)
	{
		cpVoice->Speak(text, SPF_DEFAULT, 0);
	}
}

void CSpeechSynthesizer::SetVoice(std::string* name)
{}

std::list<std::string*>* CSpeechSynthesizer::GetAvailableVoices()
{
	std::list<std::string*>* namelist = new std::list<std::string*>();

	return namelist;
}
