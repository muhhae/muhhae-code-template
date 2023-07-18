#include <iostream>
#include <filesystem>
#include <fstream>

void list(std::string templatePath);
void commandList(std::string templatePath);

int main(int argc, char *argv[])
{
    std::string exePath = argv[0];
    std::string templatePath = exePath.substr(0, exePath.find_last_of("\\/")) + "\\Template\\";

    if (argc < 2)
    {
        commandList(templatePath);
        return 0;
    }

    if (static_cast<std::string>(argv[1]) == "list") 
    {
        list(templatePath);
        return 0;
    }

    if (argc < 3) 
    {
        commandList(templatePath);
        return 0;
    }

    std::string folderName = argv[1];
    std::string templateType = argv[2];

    templatePath += "/" + templateType;

    if (!std::filesystem::exists(templatePath)) 
    {
        std::cout << "Error : Template not found" << std::endl;
        list(templatePath);
        std::cout << "\n";
        return 0;
    }

    if (std::filesystem::exists(folderName))
    {
        std::cout << "Folder already exists" << std::endl;
        std::cout << "Overwrite it ? y : n" << std::endl;
        char c = 0;
        while (c != 'y' && c != 'n')
        {
            std::cin >> c;
        }

        if ( c == 'y') std::filesystem::remove_all(folderName);
        else return 0;
    }    

    std::filesystem::copy(templatePath, folderName, std::filesystem::copy_options::recursive | std::filesystem::copy_options::skip_existing);
    std::cout << folderName << " created" << std::endl;
    return 0;
}

void list(std::string templatePath)
{
    std::cout << "Available templates : " << std::endl;

    for (const auto & entry : std::filesystem::directory_iterator(templatePath))
    {
        std::cout << "\t" << entry.path().filename().string() << std::endl;
    }

    std::cout << "\nYou can add your own template by adding folder to "<< templatePath << std::endl;
}

void commandList(std::string templatePath)
{
    std::cout << "List of commands : " << std::endl;
    std::cout << "\tmuhhae <folderName> <templateType> to create project" << std::endl; 
    std::cout << "\tmuhhae list to see available templates" << std::endl;
    std::cout << "You can add your own template by adding folder to "<< templatePath << std::endl;
}
