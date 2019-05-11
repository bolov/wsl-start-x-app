#include <Windows.h>
#include <string>

template <class T, std::size_t N>
auto array_length(const T (&)[N])
{
    return N / sizeof(T);
}

template <std::size_t N>
auto string_size(const wchar_t (&str)[N])
{
    return array_length(str) - 1;
}

int wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR lpCmdLine, int nCmdShow)
{
    STARTUPINFOW si{};
    PROCESS_INFORMATION pi{};
    si.cb = sizeof(si);

    const auto cmd_len = std::char_traits<wchar_t>::length(lpCmdLine);
    if (cmd_len == 0)
        return -1;

    const wchar_t wsl_cmd_prefix[] = LR"(ubuntu run bash -lc \")";
    const wchar_t wsl_cmd_suffix[] = LR"(\")";

    std::wstring wsl_cmd;
    wsl_cmd.reserve(string_size(wsl_cmd_prefix) + cmd_len + string_size(wsl_cmd_suffix));

    wsl_cmd.append(wsl_cmd_prefix);
    wsl_cmd.append(lpCmdLine);
    wsl_cmd.append(LR"(\")");

    CreateProcessW(nullptr, wsl_cmd.data(), nullptr, nullptr, false, CREATE_NO_WINDOW, nullptr, nullptr, &si, &pi);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
