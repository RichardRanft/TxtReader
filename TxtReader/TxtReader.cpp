// TxtReader.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <sapi.h>
#include <sperror.h>
#include <sphelper.h>
#include "SpeechSynthesizer.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CSpeechSynthesizer* synth = new CSpeechSynthesizer();

	synth->Initialize();

	synth->SpeakText(argv[1]);

	return 0;
}

