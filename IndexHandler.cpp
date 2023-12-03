#include "IndexHandler.h"
std::map<std::string, int> IndexHandler::getWords(std::string word)
{
    return words.contains(word);
}
int IndexHandler::getWordCount(std::string title)
{
    return wordCount[title];
}
std::map<std::string, int> IndexHandler::getPeople(std::string person)
{
    return people.find(person);
}
std::map<std::string, int> IndexHandler::getOrgs(std::string org)
{
    return orgs.find(org);
}
std::string IndexHandler::getFilePath(std::string title)
{
    return docs[title];
}
void IndexHandler::addWordCount(std::string title, int count)
{
    wordCount[title] = count;
}
void IndexHandler::addWords(std::string word, std::string filepath)
{
    words.insert(word, filepath);
}
void IndexHandler::addPeople(std::string person, std::string filepath)
{
    people.insert(person, filepath);
}
void IndexHandler::addOrgs(std::string org, std::string filepath)
{
    orgs.insert(org, filepath);
}
void IndexHandler::addDocument(std::string filepath, std::string title)
{
    docs[title] = filepath;
}
int IndexHandler::getDocSize()
{
    return docs.size();
}
void IndexHandler::createPersistence()
{
    std::ofstream output("persistence.txt");
    if (!output.is_open())
    {
        std::cerr << "Error! File could not be opened!" << std::endl;
        exit(-1);
    }

    output << "//words" << std::endl;
    words.printTree(output);

    output << "//people" << std::endl;
    people.printHash(output);

    output << "//orgs" << std::endl;
    orgs.printHash(output);

    output << "//docs" << std::endl;
    for (const auto &itr : docs)
    {
        output << itr.first << "|" << itr.second << "," << std::endl;
    }

    output << "//wordCount" << std::endl;
    for (const auto &itr : wordCount)
    {
        output << itr.first << "|" << itr.second << "*" << std::endl;
    }
}
void IndexHandler::readPersistence()
{
    std::ifstream input("persistence.txt");
    std::string buffer;
    std::string answer;
    std::string node;
    std::string id;
    std::string freq;
    std::string title;
    std::string count;
    bool goIn = false;
    bool goIn2 = false;
    if (!input.is_open())
    {
        std::cerr << "Error! File could not be opened!" << std::endl;
        exit(-1);
    }
    while (getline(input, buffer))
    {
        int index = 0;
        for (size_t i = 0; i < buffer.length(); i++)
        {
            if (buffer[i] == '/' && buffer[i + 1] == '/')
            {
                answer = buffer.substr(2, buffer.length() - 1);
                goIn = false;
                goIn2 = false;
                break;
            }
            else if (buffer[i] == ':')
            {
                node = buffer.substr(index, i - index);
                index = i + 1;
            }
            else if (buffer[i] == ',')
            {
                id = buffer.substr(index, i - index);
                index = i + 1;
                goIn2 = true;
            }
            else if (buffer[i] == ';')
            {
                freq = buffer.substr(index, i - index);
                index = i + 1;
                goIn = true;
            }
            else if (buffer[i] == '|')
            {
                title = buffer.substr(index, i - index);
                index = i + 1;
            }
            else if (buffer[i] == '*')
            {
                count = buffer.substr(index, i - index);
                index = i + 1;
                goIn = true;
            }
        }
        if (answer == "words" && goIn)
            words.insert(node, id, stoi(freq));
        else if (answer == "people" && goIn)
            people.insert(node, id, stoi(freq));
        else if (answer == "orgs" && goIn)
            orgs.insert(node, id, stoi(freq));
        else if (answer == "docs" && goIn2)
            docs[title] = id;
        else if (answer == "wordCount" && goIn)
            wordCount[title] = stoi(count);
    }
    input.close();
}
int IndexHandler::returnSize()
{
    return words.getSize();
}