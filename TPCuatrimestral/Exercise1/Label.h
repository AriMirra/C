#ifndef CFROMJAVA_LABEL_H
#define CFROMJAVA_LABEL_H

typedef struct  Label{
    char* name;
    char* id;
}Label;

//functions
Label* createLabel(char* name, char* id);

#endif //CFROMJAVA_LABEL_H