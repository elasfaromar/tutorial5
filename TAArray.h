#ifndef TAARRAY_H
#define TAARRAY_H

#include "TextArea.h"

class TAArray {
    public:
        TAArray();
        ~TAArray();
        
        bool add(TextArea* ta);
        bool add(TextArea* ta, int index);
        
        TextArea* remove(const string& id);
        TextArea* remove(int index);
        
        TextArea* get(const string& id) const;
        TextArea* get(int index) const;
        
        int getSize() const;

    private:
        TextArea** arr;
        int count;
};

#endif