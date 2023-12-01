#include "SearchEngine.h"

void SearchEngine::input(char** answer){

    if(strcmp(answer[1], "index")){
        dp->traverseSubdirectory(answer[2]);
        ih->createPersistence();
    }
    else if(strcmp(answer[1], "query")){
        ih->readPersistence();
        std::vector<std::string> final = qp->parsingAnswer(answer[2]);
        for(size_t i = 0; i<final.size(); i++){
            std::cout << final[i] << std::endl;
        }
    }
    else if(strcmp(answer[1], "ui")){
        ih->readPersistence();
        ui->initialQuestion();
    }
}