#include "IndexHandler.h"

// Function to retrieve words and their frequencies for a given word
std::map<std::string, int> IndexHandler::getWords(std::string word)
{
    return words.contains(word);
}

// Function to retrieve the word count for a given document title
int IndexHandler::getWordCount(std::string title)
{
    return wordCount[title];
}

// Function to retrieve people and their frequencies for a given person
std::map<std::string, int> IndexHandler::getPeople(std::string person)
{
    return people.find(person);
}

// Function to retrieve organizations and their frequencies for a given organization
std::map<std::string, int> IndexHandler::getOrgs(std::string org)
{
    return orgs.find(org);
}

// Function to update or add word count for a document title
void IndexHandler::addWordCount(std::string title, int count)
{
    wordCount[title] = count;
}

// Function to add words and their associated file paths
void IndexHandler::addWords(std::string word, std::string filepath)
{
    words.insert(word, filepath);
}

// Function to add people and their associated file paths
void IndexHandler::addPeople(std::string person, std::string filepath)
{
    people.insert(person, filepath);
}

// Function to add organizations and their associated file paths
void IndexHandler::addOrgs(std::string org, std::string filepath)
{
    orgs.insert(org, filepath);
}

// Function to add a document to the list of documents
void IndexHandler::addDocument(std::string filepath)
{
    docs.push_back(filepath);
}

// Function to get the size of the document list
int IndexHandler::getDocSize()
{
    return docs.size();
}

// Function to create persistence by writing the data to a file
void IndexHandler::createPersistence()
{
    std::ofstream output("persistence.txt");
    if (!output.is_open())
    {
        std::cerr << "Error! File could not be opened!" << std::endl;
        exit(-1);
    }

    // Writing words and their frequencies
    output << "//words" << std::endl;
    words.printTree(output);

    // Writing people and their frequencies
    output << "//people" << std::endl;
    people.printHash(output);

    // Writing organizations and their frequencies
    output << "//orgs" << std::endl;
    orgs.printHash(output);

    // Writing document file paths
    output << "//docs" << std::endl;
    for (const auto &itr : docs)
    {
        output << itr << "$" << std::endl;
    }

    // Writing word count for each document
    output << "//wordCount" << std::endl;
    for (const auto &itr : wordCount)
    {
        output << itr.first << "|" << itr.second << "*" << std::endl;
    }
}

// Function to read persistence by reading data from a file
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
            // Parsing comment lines
            if (buffer[i] == '/' && buffer[i + 1] == '/')
            {
                answer = buffer.substr(2, buffer.length());
                break;
            }
            // Parsing lines with ':' separator
            else if (buffer[i] == ':')
            {
                node = buffer.substr(index, i - index);
                index = i + 1;
            }
            // Parsing lines with ',' separator
            else if (buffer[i] == ',')
            {
                id = buffer.substr(index, i - index);
                index = i + 1;
            }
            // Parsing lines with ';' separator
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
            // Parsing lines with '|' separator
            else if (buffer[i] == '|')
            {
                title = buffer.substr(index, i - index);
                index = i + 1;
            }
            // Parsing lines with '$' separator
            else if (buffer[i] == '$')
            {
                path = buffer.substr(index, i - index);
                docs.push_back(path);
            }
            // Parsing lines with '*' separator
            else if (buffer[i] == '*')
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

// Function to return the size of the words container
int IndexHandler::returnSize()
{
    return words.getSize();
}