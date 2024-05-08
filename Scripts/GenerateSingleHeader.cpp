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
    
    //Check if we have already included this file
    {
        if(includedFiles.find(filePath) != includedFiles.end())
            return true;
        
        includedFiles.insert(filePath);
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
                //If it is a relative path
                if(includePath.size() >= 2 && includePath[0] == '.' && includePath[1] == '/')
                    includePath = includePath.substr(2);
                
                //Handle recursive parent paths
                int backCounter = 0;
                while(  includePath.size() >= 3 && 
                        includePath[0] == '.' && 
                        includePath[1] == '.' &&
                        includePath[2] == '/')
                {
                    includePath = includePath.substr(3);
                    ++backCounter;
                }
                
                {
                    size_t lastSlash = filePath.find_last_of('/');
                    
                    if(lastSlash == std::string::npos)
                    {
                        std::cerr << "Failed to find base path" << std::endl;
                        return false;
                    }
                    
                    std::string basePath = filePath.substr(0, lastSlash);
                    
                    for(int i = 0; i < backCounter; ++i)
                    {
                        lastSlash = basePath.find_last_of('/');
                        
                        if(lastSlash == std::string::npos)
                        {
                            std::cerr << "Failed to find base path" << std::endl;
                            return false;
                        }
                        
                        basePath = basePath.substr(0, lastSlash);
                        std::cerr << "Trimming to base: " << basePath << std::endl;
                    }
                    
                    includePath = basePath + "/" + includePath;
                }
                
                std::cerr << "Including: " << includePath << std::endl;
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
