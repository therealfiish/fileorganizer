#include <algorithm>
#include <filesystem>
#include <windows.h>
#include <string>
#include <shlobj.h>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
namespace fs = std::filesystem;
filesystem::path BrowseFolder()
{
    BROWSEINFO window = {0};

    window.lpszTitle = "Select Folder for Sorting";
    window.ulFlags = BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE;

    LPITEMIDLIST pidl = SHBrowseForFolder(&window);
    if (pidl)
    {
        char path[MAX_PATH];
        if (SHGetPathFromIDList(pidl, path))
        {
            CoTaskMemFree(pidl);
            return filesystem::path(path);
        }
        CoTaskMemFree(pidl);
    }
    return filesystem::path();
}
void sortFiles(const string& sourcePath)
{
    if (sourcePath.empty())
    {
        cout << "No path provided" << endl;
        return;
    }
    map<string, vector<fs::path>> fileMap;

    for (const auto& entry : fs::directory_iterator(sourcePath))
    {
        if (entry.is_regular_file())
        {
            string extension = entry.path().extension().string();
            transform(extension.begin(), extension.end(), extension.begin(), ::tolower);
            fileMap[extension].push_back(entry.path());
        }
    }
    for (const auto& [extension, files] : fileMap)
    {
        if (extension.empty()) continue;
        fs::path subDir = fs::path(sourcePath) / extension.substr(1);

        try
        {
            fs::create_directory(subDir);
            for (const auto& file : files)
            {
                fs::path destPath = subDir / file.filename();
                fs::rename(file, destPath);
            }
        } catch (const fs::filesystem_error& e)
        {
            cout << "ERROR FOUND: " << endl;
            cout << e.what() << endl;
        }
    }
}
int main()
{
    HRESULT hr = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);
    if (FAILED(hr)) {
        cout << "Failed to initialize COM" << endl;
        return 1;
    }

    fs::path sourcePath = BrowseFolder();
    if (!sourcePath.empty())
    {
        sortFiles(sourcePath.string());
        cout << "Sorted";
    }
    CoUninitialize();
    return 0;
}
// pull directory from a window popup
// categorize the most common files in their respective folders, then the non-important ones in a different folder.
// in that different folder make subfolders for their extensions.