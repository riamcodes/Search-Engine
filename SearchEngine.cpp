#include "SearchEngine.h"

void SearchEngine::input(char** answer){
    if(answer[1] == "index"){
        dp->traverseSubdirectory(answer[2]);
        ih->createPersistence();
    }
    else if(answer[1] == "query"){
        ih->readPersistence();
        std::vector<std::string> final = qp->parsingAnswer(answer[2]);
        for(int i = 0; i<final.size(); i++){
            std::cout << final[i] << std::endl;
        }
    }
    else if(answer[1] == "ui"){
        ih->readPersistence();
        ui->initialQuestion();
    }
}