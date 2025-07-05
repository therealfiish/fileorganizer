
# File Organizer

## Description

A simple yet effective C++ utility for Windows that helps you declutter any folder by automatically organizing its files into subdirectories based on their file extensions.

When you run the application, it opens a native Windows dialog, allowing you to browse and select the folder you want to organize. The program then gets to work, creating new folders for each file type and moving the files into their new homes.

## Features

*   **Interactive Folder Selection:** Uses a native Windows dialog to let you browse and select the folder you want to organize.
*   **Automatic Sorting:** Scans all files in the selected directory.
*   **Smart Categorization:** Creates new subfolders for each unique file extension found (e.g., a `.pdf` file will be moved to a `pdf` folder).
*   **File Relocation:** Moves files into their corresponding extension-named folders.
*   **Error Handling:** Catches and reports errors that might occur during file operations.

## How It Works

The core logic resides in the `sortFiles` function. It iterates through every item in the user-selected directory. For each item that is a regular file, it extracts its extension (e.g., `.docx`). It then creates a new directory named `docx` inside the target directory (if it doesn't already exist) and moves the file into it. This process is repeated for all files, resulting in a neatly organized folder.

## How to Use

1.  **Compile the Program:** Compile `main.cpp` using a C++17 compliant compiler on a Windows environment. You will need to link against the necessary Windows libraries (`user32`, `shell32`, `ole32`).
2.  **Run the Executable:** Launch the compiled program.
3.  **Select a Folder:** A window will pop up. Navigate to and select the folder you wish to organize.
4.  **Done:** The program will automatically create subfolders and sort the files. A "Sorted" message will appear in the console upon completion.

## Testing

A separate `testing.cpp` file is included to help you quickly set up a test environment.

1.  Compile and run `testing.cpp`.
2.  This will create a new folder named `test_files` in the same directory as the executable.
3.  The `test_files` folder will be populated with numerous dummy files of various common types.
4.  You can then run the main file organizer program and select the `test_files` folder to see it in action.

## Dependencies

*   **Operating System:** Windows (due to the use of `windows.h` and `shlobj.h`)
*   **C++ Standard:** C++17 or later (for `std::filesystem`)
*   **Libraries:**
    *   Standard Library
    *   Windows Shell API (`shell32.lib`)
    *   OLE library (`ole32.lib`) for COM initialization
