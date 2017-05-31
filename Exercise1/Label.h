#ifndef CFROMJAVA_LABEL_H
#define CFROMJAVA_LABEL_H

/*
 * Description: The Label structure has the information of an appliance, and is created only when an appliance is created.
 */
typedef struct  Label{
    char* name;
    char* id;
}Label;

//functions
Label* createLabel(char* name, char* id);
void destroyLabel(Label* label);
#endif //CFROMJAVA_LABEL_H