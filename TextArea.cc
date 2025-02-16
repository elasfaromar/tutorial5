#include "TextArea.h"

TextArea::TextArea(int x, int y, int width, int height, std::string id, std::string label, RGB fill, RGB border): 
    dimensions((Rectangle){.x = x, .y = y, .width = width, .height = height}), id(id), text(label), fill(fill), border(border) {}
    
TextArea::TextArea(Rectangle rect, std::string id, std::string label, RGB fill, RGB border): 
    dimensions(rect), id(id), text(label), fill(fill), border(border) {}

TextArea::TextArea(): 
    dimensions((Rectangle){.x = 0, .y = 0, .width = 25, .height = 25}), id("Default"), text("Default"), fill(RGB::WHITE()), border(RGB::BLACK()) {}

TextArea::TextArea(const TextArea& ta): 
    dimensions(ta.dimensions), id(ta.id), text("DUPLICATE"), fill(ta.fill), border(ta.border) {}

void TextArea::draw(Display *display, Window win, GC gc, int x, int y) {}

bool TextArea::overlaps(const TextArea& ta) const {
    return dimensions.overlaps((Rectangle&)(ta.dimensions));
}

void TextArea::print() const {
    std::cout << "TextArea id:\t" << id << std::endl;
    std::cout << "Preferred Location:\t" << dimensions.x << ", " << dimensions.y << std::endl;
    std::cout << "Size:\t" << dimensions.width << ", " << dimensions.height << std::endl;
    std::cout << "Text:\t" << text << std::endl;
}

void TextArea::setFill(RGB col) {
    fill = col;
}

void TextArea::setBorder(RGB col) {
    border = col;
}

bool TextArea::equals(const string& id) const {
    return this->id == id;
}
