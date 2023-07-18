#include <iostream>
#include <filesystem>
#include <fstream>

void list(std::string templatePath);
void commandList(std::string templatePath);

int main(int argc, char *argv[])
{
    std::cout << "\nMuhhae Template Generator\n" << std::endl;

    std::string exePath = argv[0];
    std::string templatePath = exePath.substr(0, exePath.find_last_of("\\/")) + "\\Template\\";

    if (argc < 2)
    {
        commandList(templatePath);
        return 0;
    }

    if (argc < 3) 
    {
        if (static_cast<std::string>(argv[1]) == "list") 
        {
            list(templatePath);
            return 0;
        }
        
        commandList(templatePath);
        return 0;
    }

    std::string folderName = argv[1];
    std::string templateType = argv[2];

    std::ifstream templateList;
    templateList.open(templatePath + "TemplateList.txt");

    std::string temp;
    bool templateExists = false;

    while (std::getline(templateList, temp))
    {
        if (temp == templateType) 
        {
            templateExists = true;
            templatePath += temp;
            break;
        }
    }

    if (!templateExists) 
    {
        std::cout << "Template not found" << std::endl;
        std::cout << "\"muhhae list\" to see available templates" << std::endl;
        return 0;
    }

    if (!std::filesystem::exists(templatePath)) 
    {
        std::cout << "Error : Template folder not found" << std::endl;
        std::cout << "Please check "<< templatePath << std::endl;
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
    std::ifstream templateList;
    templateList.open(templatePath + "TemplateList.txt");

    std::string temp;
    std::cout << "Available templates : " << std::endl;

    while(std::getline(templateList, temp))
    {
        std::cout << "\t" << temp << std::endl;
    }
    std::cout << "\nYou can add your own template by adding folder to "<< templatePath << " Then add it to TemplateList.txt\n" << std::endl;
}

void commandList(std::string templatePath)
{
    std::cout << "List of commands : " << std::endl;
    std::cout << "\tmuhhae <folderName> <templateType> to create project" << std::endl; 
    std::cout << "\tmuhhae list to see available templates" << std::endl;

    std::cout << "\nYou can add your own template by adding folder to "<< templatePath << " Then add it to TemplateList.txt\n" << std::endl;
}
