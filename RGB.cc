#include "RGB.h"

RGB::RGB(int r, int g, int b) {
    this->r = validRGB(r);
    this->g = validRGB(g);
    this->b = validRGB(b);
}

RGB::RGB() {
    this->r = MIN_RGB;
    this->g = MIN_RGB;
    this->b = MIN_RGB;
}

int RGB::getR() const {
    return this->r;
}

int RGB::getG() const {
    return this->g;
}

int RGB::getB() const {
    return this->b;
}

void RGB::setR(int val) {
    this->r = validRGB(val);
}

void RGB::setG(int val) {
    this->g = validRGB(val);
}

void RGB::setB(int val) {
    this->b = validRGB(val);
}

CuColour RGB::getColour() const {
    return (this->r << 16) | (this->g << 8) | this->b;
}

void RGB::setColour(CuColour col) {
    this->r = (col >> 16) & BLUE().getColour();
    this->g = (col >> 8) & BLUE().getColour();
    this->b = col & BLUE().getColour();
}

int RGB::validRGB(int val) const {
    return (val >= MIN_RGB) && (val <= MAX_RGB) ? val : MIN_RGB;
}

void RGB::print() const {
    std::cout << "R: " << r << " G: " << g << " B: " << b << " - Hex: " << getColour() << std::endl;
}

RGB RGB::BLACK() {
    return RGB(0,0,0);
}

RGB RGB::WHITE() {
    return RGB(255,255,255);
}

RGB RGB::RED() {
    return RGB(255,0,0);
}

RGB RGB::GREEN() {
    return RGB(0,255,0);
}

RGB RGB::BLUE() {
    return RGB(0,0,255);
}