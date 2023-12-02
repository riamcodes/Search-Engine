#include "SearchEngine.h"
#include <iostream>
#include <cstdio>
#include <chrono>


void SearchEngine::input(){
   
  //  UserInterface ui;
  //  ui.initialQuestion();
//    std::chrono::duration<double> elapsedTrain;

QueryProcessor qp;
    //THESE NEXT 4 COMMANDS  WORK AND POPULATE CORRECTLY 
std::cout << "HIIIIIIIIIII";
DocumentParser dp;
// //---------------------------------------------------------------------------------------------------------------------------------------------------
//        // dp.traverseSubdirectory("/users7/cse/rmukherji/assignment-4-search-engine-exit-code-0/kaggleSample6000");//////////////////
       dp.parseDocument("/users7/cse/rmukherji/assignment-4-search-engine-exit-code-0/kaggleSample6000/2018_03_112b52537b67659ad3609a234388c50a/news_0022791.json");
       dp.parseDocument("/users7/cse/rmukherji/assignment-4-search-engine-exit-code-0/kaggleSample6000/2018_03_112b52537b67659ad3609a234388c50a/news_0022810.json");
     ih = dp.getIndex();//////////
     ih.createPersistence();/////////////////

// // ///////read persistence
 ih.readPersistence();
// // After creating the index
ih = dp.getIndex();
// qp.setIndexHandler(&ih);  // Assuming such a method exists

// Process the query
std::cout << "Please enter a query" << std::endl;
std::string answer3;
std::getline(std::cin, answer3);

// Get the relevant documents
std::vector<std::string> relevantDocs = qp.parsingAnswer(answer3);

std::cout << "Is printVector empty 1 means yes 0 means no " << std::endl;
std::cout << qp.printVector.empty();

// Print the relevant documents
// std::cout << "Top Relevant Documents:" << std::endl;
// for (const std::string& doc : printVector) {
//     std::cout << doc << std::endl;
// }
 std::cout << "Contents of printVector:" << std::endl;
            for (const auto& item : qp.printVector) {
                std::cout << item << std::endl;
            }
//---------------------------------------------------------------------------------------------------------------
// std::cout << "Please enter a query" << std::endl;
//             std::string answer3;
//             std::getline(std::cin, answer3);
            
//             std::vector<std::string> final = qp.parsingAnswer(answer3);
           
//          std::cout << "Top Relevant Documents:" << std::endl;
//         std::cout << qp.printVector.empty();

//     for (const std::string& doc : qp.printVector) {
//         std::cout << doc << std::endl;
//     }

//             std::string yesOrNo;
//             std::string fileName;
//             std::cout << "Would you like to see the contents of a file?" << std::endl;
//             std::cin >> yesOrNo;
//             for (size_t i = 0; i < yesOrNo.length(); i++)
//             {
//                 tolower(yesOrNo.at(i));
//             }
//             if (yesOrNo == "yes")
//             {
//                 std::cout << "Please enter in the title of the document that you would like to see." << std::endl;
//                 std::string titleDocument;
//                 std::getline(std::cin, titleDocument);
//                 dp.printDocument(ih.getFilePath(titleDocument));
//             }
            //auto finishTrain = std::chrono::high_resolution_clock::now();
          //  elapsedTrain = finishTrain - startTrain;
//------------------------------------------------------------------------------------------------------------------------------------------------------------
//the next command pulls up ui but theres an issue with 3 because of pointers which is why its commented out 
//ui.initialQuestion();
//--------------------------------------------------------------------------------------------------------------------------------
 //the next stuff doesnt work 

// while (true)
//     {
//         std::cout << "Hello! Welcome to our search engine" << std::endl;
//         std::cout << "Please enter a number 1-6 of the options below to continue" << std::endl;
//         std::cout << "----------------------------------------------------------" << std::endl;
//         std::cout << "1) Create an index from a directory with documents" << std::endl;
//         std::cout << "2) Write an index to the file" << std::endl;
//         std::cout << "3) Read an index from the file" << std::endl;
//         std::cout << "4) Enter a query" << std::endl;
//         std::cout << "5) See statistics" << std::endl;
//         std::cout << "6) Quit" << std::endl;

//       //  std::cin.clear(); // Clear any error flags
//     //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the leftover characters in the buffer
//         std::string answer;
//         std::getline(std::cin, answer);

//         if (!(answer == "1" || answer == "2" || answer == "3" || answer == "4" || answer == "5" || answer == "6"))
//          {
//            std::cout << "Error! This is an invalid answer. Please select numbers 1 through 6." << std::endl;
//            std::cin >> answer;
//         }
//        std::cout << " this is loading";
//          if (answer == "1") // Populates with documents
//         {
//             std::cout << "Please enter a directory filepath" << std::endl;
//             std::string answer2;
//             std::getline(std::cin, answer2);
//             auto startTrain = std::chrono::high_resolution_clock::now();
//             dp.traverseSubdirectory(answer2);
//             auto finishTrain = std::chrono::high_resolution_clock::now();
//             elapsedTrain = finishTrain - startTrain;
//         }
//         else if (answer == "2") // Create Persistence
//         {
//             auto startTrain = std::chrono::high_resolution_clock::now();
//             //  ih = dp.getIndex();
//             ih.createPersistence();
//             auto finishTrain = std::chrono::high_resolution_clock::now();
//             elapsedTrain = finishTrain - startTrain;
//         }
//         else if (answer == "3") // Read Persistence
//         {
//             auto startTrain = std::chrono::high_resolution_clock::now();
//             ih.readPersistence();
//             auto finishTrain = std::chrono::high_resolution_clock::now();
//             elapsedTrain = finishTrain - startTrain;
//         }
//         else if (answer == "4") // Enter a query
//         {
//             std::cout << "Please enter a query" << std::endl;
//             std::string answer3;
//             std::getline(std::cin, answer3);
//             auto startTrain = std::chrono::high_resolution_clock::now();
//             std::vector<std::string> final = qp.parsingAnswer(answer3);
//             std::string yesOrNo;
//             std::string fileName;
//             std::cout << "Would you like to see the contents of a file?" << std::endl;
//             std::cin >> yesOrNo;
//             for (size_t i = 0; i < yesOrNo.length(); i++)
//             {
//                 tolower(yesOrNo.at(i));
//             }
//             if (yesOrNo == "yes")
//             {
//                 std::cout << "Please enter in the title of the document that you would like to see." << std::endl;
//                 std::string titleDocument;
//                 std::getline(std::cin, titleDocument);
//                 dp.parseDocument(ih.getFilePath(titleDocument));
//             }
//             auto finishTrain = std::chrono::high_resolution_clock::now();
//             elapsedTrain = finishTrain - startTrain;
//         }
//         else if (answer == "5") // Statistics
//         {
//             std::cout << "Here are some of our runtime statistics:" << std::endl;
//             std::cout << "Runtime: " << elapsedTrain.count() << " seconds." << std::endl;
//             // std::cout << "Total number of individual articles in the current index: " << # << std::endl;
//             std::cout << "Total articles: " << ih.getDocSize();
//             // std::cout << "Total number of unique words indexed: " << (number of nodes in AVLTree) << std::endl;

//         }
//         else if (answer == "6")
//         {
//             std::cout << "Thank you for using our search engine." << std::endl;
//             break;
//         }
  }





//     }

    //------------------------------------------------------------------------------------------------------------------------------------------------





//     else if(strcmp(, "query")){
//         ih->readPersistence();
//         std::vector<std::string> final = qp->parsingAnswer();
//         for(size_t i = 0; i<final.size(); i++){
//             std::cout << final[i] << std::endl;
//         }
//     }
//     else if(strcmp(answer[1], "ui")){
//         ih->readPersistence();
//         ui->initialQuestion();
//     }
// }