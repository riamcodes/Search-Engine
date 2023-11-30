#include "SearchEngine.h"

void SearchEngine::input(char** answer){
    if(answer[1] == "index"){
        dp->traverseSubdirectory(answer[2]);
        ih->createPersistence("words");
        ih->createPersistence("people");
        ih->createPersistence("orgs");
    }
    else if(answer[1] == "query"){
        ih->readPersistence("words");
        ih->readPersistence("people");
        ih->readPersistence("orgs");
        std::vector<std::string> final = qp->parsingAnswer(answer[2]);
        for(int i = 0; i<final.size(); i++){
            std::cout << final[i] << std::endl;
        }
    }
    else if(answer[1] == "ui"){
        ui->initialQuestion();
    }
}