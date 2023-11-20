#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

std::unordered_set<std::string> includedFiles;

bool processFile(const std::string& filePath) 
{
    std::ifstream file(filePath);
    if (!file.is_open()) 
    {
        std::cerr << "Error opening file: " << filePath << std::endl;
        return false;
    }

    std::cout << "//=================================================================" << std::endl;
    std::cout << "//" << filePath << std::endl;
    std::cout << "//=================================================================" << std::endl;

    std::string line;
    while(std::getline(file, line)) 
    {
        if(line.find("#include \"") != std::string::npos) 
        {
            size_t start = line.find_first_of("\"") + 1;
            size_t end = line.find_last_of("\"");
            std::string includePath = line.substr(start, end - start);

            if(includedFiles.find(includePath) == includedFiles.end()) 
            {
                includedFiles.insert(includePath);

                if(includePath[0] == '.') 
                {
                    // It's a relative path
                    size_t lastSlash = filePath.find_last_of('/');
                    std::string basePath = filePath.substr(0, lastSlash + 1);
                    includePath = basePath + includePath;
                }

                if(!processFile(includePath))
                    return false;

                std::cout << std::endl;  // Leave an empty line for replaced header file
            }
            else
            {
                // Already included, Don't need to do anything
            }
        } 
        else 
            std::cout << line << std::endl;  // Not an #include line, leave as is
    }

    file.close();
    return true;
}


int main(int argc, char** argv) 
{
    if(argc != 2)
    {
        std::cout << "Usage: GenerateSingleHeader <Entry Header>" << std::endl;
        return 0;
    }
    
    std::string filePath = argv[1];
    processFile(filePath);

    return 0;
}
