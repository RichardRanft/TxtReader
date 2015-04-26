#pragma once
#include <Windows.h>
#include <sapi.h>
#include <sperror.h>
#include <sphelper.h>
#include <string>
#include <list>

class CSpeechSynthesizer
{
private:
	CComPtr<IEnumSpObjectTokens> cpIEnum;
	CComPtr<ISpObjectToken> cpToken;
	CComPtr<ISpVoice> cpVoice;
	bool m_initialized;
public:
	CSpeechSynthesizer();
	~CSpeechSynthesizer();

	bool IsInitialized();

	void Initialize();

	void SpeakText(_TCHAR*);

	void SetVoice(std::string* name);

	std::list<std::string*>* GetAvailableVoices();
};

