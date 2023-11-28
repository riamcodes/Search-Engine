#include "IndexHandler.h"
std::map<std::string, int> IndexHandler::getWords(std::string word)
{
    return words.contains(word);
}
int IndexHandler ::getWordCount(std::string title)
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
    if(!output.is_open()){
        std::cerr << "Error! File could not be opened!" << std::endl;
        exit(-1);
    }

    output << "WORDS" << std::endl;
    words.printTree(output);
    
    output << "PEOPLE" << std::endl;
    people.printHash(output);

    output << "ORGS" << std::endl;
    orgs.printHash(output);

    output << "DOCUMENTS" << std::endl;
        for(const auto itr : docs){
            output << itr.first << "," << itr.second;
        }
    
    output << "WORDCOUNTS" << std::endl;
    for(const auto itr : wordCount){
        output << itr.first << "," << itr.second;
    }

    // if (tree == "words")
    // {
    //     std::ofstream output("words.txt");
    //     if (!output.is_open())
    //     {
    //         std::cerr << "Error! File could not be opened!" << std::endl;
    //         exit(-1);
    //     }
    //     words.printTree(output);
    //     output.close();
    // }
    // else if (tree == "people")
    // {
    //     std::ofstream output("people.txt");
    //     if (!output.is_open())
    //     {
    //         std::cerr << "Error! File could not be opened!" << std::endl;
    //         exit(-1);
    //     }
    //     people.printHash(output);
    //     output.close();
    // }
    // else if (tree == "orgs")
    // {
    //     std::ofstream output("orgs.txt");
    //     if (!output.is_open())
    //     {
    //         std::cerr << "Error! File could not be opened!" << std::endl;
    //         exit(-1);
    //     }
    //     orgs.printHash(output);
    //     output.close();
    // }
}
void IndexHandler::readPersistence(std::string tree)
{
    if (tree == "words")
    {
        std::ifstream input("words.txt");
        std::string temp;
        std::string node;
        std::string id;
        std::string freq;
        if (!input.is_open())
        {
            std::cerr << "Error! File could not be opened!" << std::endl;
            exit(-1);
        }
        while (getline(input, temp))
        {
            int index = 0;
            for (int i = 0; i < temp.length(); i++)
            {
                if (temp[i] == ':')
                {
                    node = temp.substr(index, i - index);
                    index = i + 1;
                }
                else if (temp[i] == ',')
                {
                    id = temp.substr(index, i - index);
                    index = i + 1;
                }
                else if (temp[i] == ';')
                {
                    freq = temp.substr(index, i - index);
                    index = i + 1;
                }
            }
            words.insert(node, id, stoi(freq));
        }
        input.close();
    }
    else if (tree == "people")
    {
        std::ifstream input("people.txt");
        std::string temp;
        std::string node;
        std::string id;
        std::string freq;
        if (!input.is_open())
        {
            std::cerr << "Error! File could not be opened!" << std::endl;
            exit(-1);
        }
        while (getline(input, temp))
        {
            int index = 0;
            for (int i = 0; i < temp.length(); i++)
            {
                if (temp[i] == ':')
                {
                    node = temp.substr(index, i - index);
                    index = i + 1;
                }
                else if (temp[i] == ',')
                {
                    id = temp.substr(index, i - index);
                    index = i + 1;
                }
                else if (temp[i] == ';')
                {
                    freq = temp.substr(index, i - index);
                    index = i + 1;
                }
            }
            people.insert(node, id, stoi(freq));
        }
        input.close();
    }
    else if (tree == "orgs")
    {
        std::ifstream input("orgs.txt");
        std::string temp;
        std::string node;
        std::string id;
        std::string freq;
        if (!input.is_open())
        {
            std::cerr << "Error! File could not be opened!" << std::endl;
            exit(-1);
        }
        while (getline(input, temp))
        {
            int index = 0;
            for (int i = 0; i < temp.length(); i++)
            {
                if (temp[i] == ':')
                {
                    node = temp.substr(index, i - index);
                    index = i + 1;
                }
                else if (temp[i] == ',')
                {
                    id = temp.substr(index, i - index);
                    index = i + 1;
                }
                else if (temp[i] == ';')
                {
                    freq = temp.substr(index, i - index);
                    index = i + 1;
                }
            }
            orgs.insert(node, id, stoi(freq));
        }
    }
}

int IndexHandler::returnNumArticles(std::string index, std::string tree)
{
    std::map<std::string, int> temp;
    if (tree == "words")
    {
        temp = words.contains(index);
        return temp.size();
    }
    else if (tree == "orgs")
    {
        temp = orgs.find(index);
        return temp.size();
    }
    else if (tree == "people")
    {
        temp = people.find(index);
        return temp.size();
    }
    return -1;
}
int IndexHandler::returnSize(std::string tree)
{
    if (tree == "words")
    {
        return words.getSize();
    }
    else if (tree == "orgs")
    {
        return orgs.getSize();
    }
    else if (tree == "people")
    {
        return people.getSize();
    }
    return -1;
}