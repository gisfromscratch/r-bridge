#pragma once

SEXP R_AoInitialize();
SEXP error_Ret(const char* str_or_UTF8, SEXP retVal);
SEXP arc_error(SEXP e);
SEXP arc_warning(SEXP e);
//void arc_browsehelp(char ** url);
SEXP arc_progress_pos(SEXP arg);
SEXP arc_progress_label(SEXP arg);
SEXP extent2r(const std::vector<double> &ext);
bool r2variant(SEXP r, VARIANT &v);
SEXP R_getEnv();
SEXP R_fromWkt2P4(SEXP str);
SEXP R_fromP42Wkt(SEXP str);

///
/// Simple utility class accessing environment variables.
///
class EnvironmentVariable {

public:
	EnvironmentVariable()
	{
		_variable = (LPTSTR) malloc(STRINGBUFFERSIZE * sizeof(TCHAR));
		if (NULL == _variable)
		{
			OutputDebugStringW(L"Allocating memory for the environment variable failed!");
		}
	}

	void printValueOf(const wchar_t *variableName)
	{
		if (NULL == _variable)
		{
			return;
		}

		DWORD environmentResult = GetEnvironmentVariableW(variableName, _variable, STRINGBUFFERSIZE);
		if (0 == environmentResult)
		{
			switch (GetLastError())
			{
			case ERROR_ENVVAR_NOT_FOUND:
				OutputDebugStringW(L"Environment variable does not exists!");
				break;

			default:
				OutputDebugStringW(L"Accessing the environment variable failed!");
				break;
			}
		}
		else
		{
			OutputDebugStringW(_variable);
		}
	}

	~EnvironmentVariable()
	{
		if (NULL != _variable)
		{
			free(_variable);
			_variable = NULL;
		}
	}

private:
	const static int STRINGBUFFERSIZE = 4096;
	LPTSTR _variable;
};