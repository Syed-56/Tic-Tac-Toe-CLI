#include "colors.h"

const Color darkGrey = {30, 30, 30, 255};         // darker background
const Color green = {144, 238, 144, 255};          // pastel green
const Color red = {255, 105, 97, 255};             // soft red
const Color orange = {255, 179, 71, 255};          // light orange
const Color yellow = {255, 255, 153, 255};         // lemon yellow
const Color purple = {216, 191, 216, 255};         // thistle purple
const Color cyan = {173, 216, 230, 255};           // light cyan
const Color blue = {135, 206, 250, 255};           // sky blue
const Color lightBlue = {200, 220, 255, 255};      // gentle UI color
const Color darkBlue = {24, 24, 48, 255};          // dark blue background

std::vector<Color> GetCellColors()
{
    return {darkGrey, green, red, orange, yellow, purple, cyan, blue};
}