#include "SearchEngine.h"
#include <iostream>
#include <cstdio>
#include <chrono>

void SearchEngine::input(int num, char **answer)
{
 if (strcmp(answer[1], "index") == 0)
  {
    dp.traverseSubdirectory(answer[2]);
    ih = dp.getIndex();
    ih.createPersistence(); // CHANGE TO OBJECT
  }
  else if (strcmp(answer[1], "query") == 0)
  {
    ih.readPersistence(); // CHANGE TO OBJECT
    dp.setIndex(ih);
    qp.setIndexHandler(ih);
    std::string answer2 = answer[2];
    for (int i = 3; i < num; i++)
    {
      answer2 = answer2 + " " + answer[i];
    }
    std::map<std::string, int> relevantDocs = qp.parsingAnswer(answer2);

    int count = 1;

    std::cout << "Here are the most relevant documents" << std::endl;
    for (const auto &item : qp.printVector)
    {
      std::cout << count << ". ";
      dp.printInfo(item);
      std::cout << std::endl;
      ++count;
    }
    std::string yesOrNo;
    std::cout << "Would you like to see the contents of a file listed above?" << std::endl;
    std::getline(std::cin, yesOrNo);
    for (size_t i = 0; i < yesOrNo.length(); i++)
    {
      tolower(yesOrNo.at(i));
    }
    if (yesOrNo == "yes")
    {
      std::cout << "Please enter in the number of the corresponding document that you would like to see." << std::endl;
      std::string number;
      std::getline(std::cin, number);
      int num = stoi(number);
      dp.printDocument(qp.printVector[num - 1]);
    }
    qp.printVector.clear();
  }
  else if (strcmp(answer[1], "ui") == 0)
  {
    ih.readPersistence();
    ui.initialQuestion();
  }
}