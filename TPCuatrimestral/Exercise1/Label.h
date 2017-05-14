//
// Created by arimi on 14-May-17.
//

#ifndef CFROMJAVA_LABEL_H
#define CFROMJAVA_LABEL_H

typedef struct label Label;

struct label{
    char* name;
    char* id;
};

//functions
Label* createLabel(char* name, char* id);

#endif //CFROMJAVA_LABEL_H
