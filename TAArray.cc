#include "TAArray.h"

TAArray::TAArray() {
    arr = new TextArea*[MAX_COMPONENTS];
    count = 0;
}

TAArray::~TAArray() {
    for (int i = 0; i < count; i++) {
        delete arr[i];
    }
    delete[] arr;
}

bool TAArray::add(TextArea* ta) {
   if (count >= MAX_COMPONENTS) return false;
   
   arr[count++] = ta;
   return true;
}

bool TAArray::add(TextArea* ta, int index) {
    if (count >= MAX_COMPONENTS || index < 0 || index > count) return false;
    
    for (int i = count; i > index; i--) {
        arr[i] = arr[i-1];
    }

    arr[index] = ta;
    count++;

    return true;
}

TextArea* TAArray::get(const string& id) const {
    for (int i = 0; i < count; i++) {
        if (arr[i]->equals(id)) {
            return arr[i];
        }
    }
    return nullptr;
}

TextArea* TAArray::get(int index) const {
    if (index < 0 || index >= count || count == 0) return nullptr;
    return arr[index];
}

TextArea* TAArray::remove(const string& id) {
    for (int i = 0; i < count; i++) {
        if (arr[i]->equals(id)) {
            TextArea* goner = arr[i];
            for (int j = i; j < count-1; j++) {
                arr[j] = arr[j+1];
            }
            count--;
            return goner;
        }
    }

    return nullptr;
}

TextArea* TAArray::remove(int index) {
    if (index < 0 || index >= count || count == 0) return nullptr;

    TextArea* goner = arr[index];
    for (int i = index; i < count-1; i++) {
        arr[i] = arr[i+1];
    }
    count--;
    return goner;
}

int TAArray::getSize() const {
    return count;
}