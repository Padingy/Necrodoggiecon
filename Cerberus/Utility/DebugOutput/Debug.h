#pragma once
#include "UI/DebugOutput/DebugOutput.h"
#include <string>
#include <chrono>
#include <ctime>
#include <winerror.h>
#include <comdef.h>

class Debug
{

private:
	static DebugOutput* output;
	static void initOutput()
	{
		output = new DebugOutput();
	}

	// Helper function for getting the current system time into a std::string.
	static std::string getCurrentTimeString()
	{
		// Get the current time
		struct tm newtime;
		time_t now = time(0);
		localtime_s(&newtime, &now);

		char buffer[8];
		time(&now);

		strftime(buffer, sizeof(buffer), "%H:%M", &newtime);
		std::string timeString(buffer);

		return "[" + timeString + "] ";
	}

public:
	template<typename ... Args>
	// Logs a message to console. Supports arguments like printf.
	static void Log(const char* fmt, Args ... args)IM_FMTARGS(2)
	{
		if (output == nullptr)
			initOutput();

		std::string stringInput = std::string(fmt);
		
		stringInput = getCurrentTimeString() + stringInput;

		output->AddLog(stringInput.c_str(), args ...);
	};

	template<typename ... Args>
	static void LogError(const char* fmt, Args ... args)IM_FMTARGS(2)
	{
		if (output == nullptr)
			initOutput();

		std::string stringInput = std::string(fmt);

		stringInput = "[error] " + getCurrentTimeString() + stringInput;

		output->AddLog(stringInput.c_str(), args ...);
	};

	template<typename ... Args>
	static void LogHResult(HRESULT hr, const char* fmt,Args ... args)IM_FMTARGS(2)
	{
		if (output == nullptr)
			initOutput();

		std::string stringInput = "";

		char* convOutput = nullptr;

		if(FAILED(hr))
		{
			// Get the Error message out of the HResult.
			_com_error err(hr);
			LPCTSTR errMsg = err.ErrorMessage();
			convOutput = new char[256];
			size_t numConverted = 0;
			size_t size = 256;

			wcstombs_s(&numConverted, convOutput, size, errMsg, size-1);

			std::string errorString = std::string(convOutput);

			stringInput = "[HRESULT][error] " + getCurrentTimeString() + fmt + " " + errorString;
		}else
		{
			stringInput = "[HRESULT]" + getCurrentTimeString() + fmt + " Completed Sucessfully.";
		}
		output->AddLog(stringInput.c_str(), args ...);

		if (FAILED(hr))
			free(convOutput);
	}

	static DebugOutput* getOutput() 
	{
		if (!output)
			initOutput();

		return output;
	}


};