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

void IndexHandler::addDocument(std::string filepath)
{
    docs.push_back(filepath);
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
        output << itr << "$" << std::endl;
    }

    output << "//wordCount" << std::endl;
    for (const auto &itr : wordCount)
    {
        output << itr.first << "^" << itr.second << "#" << std::endl;
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
    std::string path;
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
                answer = buffer.substr(2, buffer.length());
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
            }
            else if (buffer[i] == ';')
            {
                freq = buffer.substr(index, i - index);
                index = i + 1;
                int num = stoi(freq);
                if (answer == "words")
                    words.insert(node, id, num);
                else if (answer == "people")
                    people.insert(node, id, num);
                else if (answer == "orgs")
                    orgs.insert(node, id, num);
            }
            else if (buffer[i] == '^')
            {
                title = buffer.substr(index, i - index);
                index = i + 1;
            }
            else if (buffer[i] == '$')
            {
                path = buffer.substr(index, i - index);
                docs.push_back(path);
            }
            else if (buffer[i] == '#')
            {
                count = buffer.substr(index, i - index);
                index = i + 1;
                int num2 = stoi(count);
                wordCount[title] = num2;
            }
        }
    }
    input.close();
}

int IndexHandler::returnSize()
{
    return words.getSize();
}