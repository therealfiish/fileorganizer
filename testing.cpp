#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <random>

namespace fs = std::filesystem;

int main() {
    // Create test directory
    fs::path testDir = "test_files";

    try {
        // Remove old test directory if it exists
        fs::remove_all(testDir);
        // Create fresh directory
        fs::create_directory(testDir);

        // Define different types of files to create
        std::vector<std::string> extensions = {
            ".txt", ".pdf", ".doc", ".docx",
            ".jpg", ".png", ".gif",
            ".mp3", ".wav", ".mp4", ".avi",
            ".zip", ".rar",
            ".cpp", ".h", ".py", ".java",
            ".xlsx", ".pptx",
            ".json", ".xml", ".html", ".css"
        };

        // Create multiple files for each extension
        int fileCount = 0;
        for (const auto& ext : extensions) {
            // Create 3 files for each extension
            for (int i = 1; i <= 3; i++) {
                std::string filename = "file" + std::to_string(++fileCount) + ext;
                fs::path filePath = testDir / filename;
                std::ofstream outFile(filePath);
                outFile << "This is a dummy " << ext << " file." << std::endl;
                outFile.close();
                std::cout << "Created: " << filename << std::endl;
            }
        }

        std::cout << "\nTotal files created: " << fileCount << std::endl;
        std::cout << "Files are in: " << fs::absolute(testDir) << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}