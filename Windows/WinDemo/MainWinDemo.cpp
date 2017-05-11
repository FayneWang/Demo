#include <gtest/gtest.h>
#include <Windows.h>

#pragma comment(lib,"googletest/gtest/v1.8.0/vc12_Debug_Unicode_MD_x86/gtestd.lib")
int wmain(int argc, wchar_t *argv[])
{
	{
		wchar_t wszFile[MAX_PATH] = { 0 };
		if (GetModuleFileName(GetModuleHandle(NULL), wszFile, MAX_PATH) != 0)
		{
			*wcsrchr(wszFile, L'\\') = L'\0';
			SetCurrentDirectory(wszFile);
		}
	}
	printf("Running wmain() from gtest_main.cc/n");
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
