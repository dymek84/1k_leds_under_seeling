#pragma once

#include "D_include.h"
int MatrixArrayFlip[8][32] = {
    {248, 247, 232, 231, 216, 215, 200, 199, 184, 183, 168, 167, 152, 151, 136, 135, 120, 119, 104, 103, 88, 87, 72, 71, 56, 55, 40, 39, 24, 23, 8, 7},
    {249, 246, 233, 230, 217, 214, 201, 198, 185, 182, 169, 166, 153, 150, 137, 134, 121, 118, 105, 102, 89, 86, 73, 70, 57, 54, 41, 38, 25, 22, 9, 6},
    {250, 245, 234, 229, 218, 213, 202, 197, 186, 181, 170, 165, 154, 149, 138, 133, 122, 117, 106, 101, 90, 85, 74, 69, 58, 53, 42, 37, 26, 21, 10, 5},
    {251, 244, 235, 228, 219, 212, 203, 196, 187, 180, 171, 164, 155, 148, 139, 132, 123, 116, 107, 100, 91, 84, 75, 68, 59, 52, 43, 36, 27, 20, 11, 4},
    {252, 243, 236, 227, 220, 211, 204, 195, 188, 179, 172, 163, 156, 147, 140, 131, 124, 115, 108, 99, 92, 83, 76, 67, 60, 51, 44, 35, 28, 19, 12, 3},
    {253, 242, 237, 226, 221, 210, 205, 194, 189, 178, 173, 162, 157, 146, 141, 130, 125, 114, 109, 98, 93, 82, 77, 66, 61, 50, 45, 34, 29, 18, 13, 2},
    {254, 241, 238, 225, 222, 209, 206, 193, 190, 177, 174, 161, 158, 145, 142, 129, 126, 113, 110, 97, 94, 81, 78, 65, 62, 49, 46, 33, 30, 17, 14, 1},
    {255, 240, 239, 224, 223, 208, 207, 192, 191, 176, 175, 160, 159, 144, 143, 128, 127, 112, 111, 96, 95, 80, 79, 64, 63, 48, 47, 32, 31, 16, 15, 0}};  ////
int MatrixArray[8][32] = {
    {0, 15, 16, 31, 32, 47, 48, 63, 64, 79, 80, 95, 96, 111, 112, 127, 128, 143, 144, 159, 160, 175, 176, 191, 192, 207, 208, 223, 224, 239, 240, 255},
    {1, 14, 17, 30, 33, 46, 49, 62, 65, 78, 81, 94, 97, 110, 113, 126, 129, 142, 145, 158, 161, 174, 177, 190, 193, 206, 209, 222, 225, 238, 241, 254},
    {2, 13, 18, 29, 34, 45, 50, 61, 66, 77, 82, 93, 98, 109, 114, 125, 130, 141, 146, 157, 162, 173, 178, 189, 194, 205, 210, 221, 226, 237, 242, 253},
    {3, 12, 19, 28, 35, 44, 51, 60, 67, 76, 83, 92, 99, 108, 115, 124, 131, 140, 147, 156, 163, 172, 179, 188, 195, 204, 211, 220, 227, 236, 243, 252},
    {4, 11, 20, 27, 36, 43, 52, 59, 68, 75, 84, 91, 100, 107, 116, 123, 132, 139, 148, 155, 164, 171, 180, 187, 196, 203, 212, 219, 228, 235, 244, 251},
    {5, 10, 21, 26, 37, 42, 53, 58, 69, 74, 85, 90, 101, 106, 117, 122, 133, 138, 149, 154, 165, 170, 181, 186, 197, 202, 213, 218, 229, 234, 245, 250},
    {6, 9, 22, 25, 38, 41, 54, 57, 70, 73, 86, 89, 102, 105, 118, 121, 134, 137, 150, 153, 166, 169, 182, 185, 198, 201, 214, 217, 230, 233, 246, 249},
    {7, 8, 23, 24, 39, 40, 55, 56, 71, 72, 87, 88, 103, 104, 119, 120, 135, 136, 151, 152, 167, 168, 183, 184, 199, 200, 215, 216, 231, 232, 247, 248}};
int MatrixArrayLeft[8][32] = {
    {7, 8, 23, 24, 39, 40, 55, 56, 71, 72, 87, 88, 103, 104, 119, 120, 135, 136, 151, 152, 167, 168, 183, 184, 199, 200, 215, 216, 231, 232, 247, 248},
    {6, 9, 22, 25, 38, 41, 54, 57, 70, 73, 86, 89, 102, 105, 118, 121, 134, 137, 150, 153, 166, 169, 182, 185, 198, 201, 214, 217, 230, 233, 246, 249},
    {5, 10, 21, 26, 37, 42, 53, 58, 69, 74, 85, 90, 101, 106, 117, 122, 133, 138, 149, 154, 165, 170, 181, 186, 197, 202, 213, 218, 229, 234, 245, 250},
    {4, 11, 20, 27, 36, 43, 52, 59, 68, 75, 84, 91, 100, 107, 116, 123, 132, 139, 148, 155, 164, 171, 180, 187, 196, 203, 212, 219, 228, 235, 244, 251},
    {3, 12, 19, 28, 35, 44, 51, 60, 67, 76, 83, 92, 99, 108, 115, 124, 131, 140, 147, 156, 163, 172, 179, 188, 195, 204, 211, 220, 227, 236, 243, 252},
    {2, 13, 18, 29, 34, 45, 50, 61, 66, 77, 82, 93, 98, 109, 114, 125, 130, 141, 146, 157, 162, 173, 178, 189, 194, 205, 210, 221, 226, 237, 242, 253},
    {1, 14, 17, 30, 33, 46, 49, 62, 65, 78, 81, 94, 97, 110, 113, 126, 129, 142, 145, 158, 161, 174, 177, 190, 193, 206, 209, 222, 225, 238, 241, 254},
    {0, 15, 16, 31, 32, 47, 48, 63, 64, 79, 80, 95, 96, 111, 112, 127, 128, 143, 144, 159, 160, 175, 176, 191, 192, 207, 208, 223, 224, 239, 240, 255}};
/*
 *x = width (max 32)
 *y = height (max 8)
 */

int letterMatrix[44][64] =  // THIS WILL HOLD (DURING SETUP) THE MATRIX CONTAINING ALL 8x8 LETTERS MAPPINGS
    {{                      // : (0)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// A (1)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0,
      0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// B (2)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0,
      0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// C (3)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0,
      0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// D (4)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0,
      0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// E (5)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0,
      0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// F (6)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0,
      0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// G (7)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0,
      0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// H (8)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0,
      0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// I (9)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0,
      0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// J (10)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0,
      0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// K (11)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0,
      0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// L (12)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
      0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// M (13)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0,
      0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// N (14)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0,
      0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// O (15)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0,
      0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// P (16)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0,
      0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// Q (17)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0,
      0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// R (18)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0,
      0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// S (19)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0,
      0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// T (20)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0,
      0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// U (21)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0,
      0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// V (22)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0,
      0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// W (23)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0,
      0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// X (24)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0,
      0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// Y (25)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0,
      0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// Z (26)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0,
      0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// . (27)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// - (28)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0,
      0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// 0 (29)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0,
      0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// 1 (30)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0,
      0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// 2 (31)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0,
      0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// 3 (32)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0,
      0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// 4 (33)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0,
      0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// 5 (34)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0,
      0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// 6 (34)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0,
      0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// 7 (36)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0,
      0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// 8 (37)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0,
      0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// 9 (38)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0,
      0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// heart (39)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// space (40)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// degree (41)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// arrow down (42)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
      0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// arrow up (43)
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0,
      0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

struct Letter {
   const char* aaaa;
   int dddd;
};
Letter letlist[] = {{"a", 1},  {"A", 1},  {"b", 2},  {"B", 2},  {"c", 3},  {"C", 3},  {"d", 4},  {"D", 4},  {"e", 5},  {"E", 5},  {"f", 6},
                    {"F", 6},  {"g", 7},  {"G", 7},  {"h", 8},  {"H", 8},  {"i", 9},  {"I", 9},  {"j", 10}, {"J", 10}, {"k", 11}, {"K", 11},
                    {"l", 12}, {"L", 12}, {"m", 13}, {"M", 13}, {"n", 14}, {"N", 14}, {"o", 15}, {"O", 15}, {"p", 16}, {"P", 16}, {"q", 17},
                    {"Q", 17}, {"R", 18}, {"r", 18}, {"S", 19}, {"s", 19}, {"T", 20}, {"t", 20}, {"U", 21}, {"u", 21}, {"V", 22}, {"v", 22},
                    {"W", 23}, {"w", 23}, {"X", 24}, {"x", 24}, {"Y", 25}, {"y", 25}, {"Z", 26}, {"z", 26}, {".", 27}, {"-", 28}, {"0", 29},
                    {"1", 30}, {"2", 31}, {"3", 32}, {"4", 33}, {"5", 34}, {"6", 35}, {"7", 36}, {"8", 37}, {"9", 38}, {"@", 39},  // will show a heart
                    {" ", 40}, {"'", 41},                                                                                          // will show a degree
                    {"%", 42},                                                                                                     // arrow down
                    {"^", 43},                                                                                                     // arrow up
                    {":", 0}};
int charToInt(char* c) {
   int temp;
   for (size_t i = 0; i < sizeof(letlist) / sizeof(Letter); i++) {
      if (c == letlist[i].aaaa) {
         temp = letlist[i].dddd;
      }
   }
   return temp;
}
// This function will return a 0 or 1 based on which pixel makes part of the 8x8 character for the time.
int xyToLedStatus(int x, int y, int* arr) {
   return arr[y * 8 + x];
}
int numberMatrix[12][64] PROGMEM =  // THIS WILL HOLD (DURING SETUP) THE MATRIX CONTAINING ALL 8x8 DIGIT MAPPINGS
    {{                              // 0
      0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0,
      0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0},
     {// 1
      0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0,
      0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0},
     {// 2
      0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0,
      0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0},
     {// 3
      0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0,
      0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0},
     {// 4
      0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0,
      0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
     {// 5
      0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0,
      0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0},
     {// 6
      0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0,
      0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0},
     {// 7
      0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0,
      0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
     {// 8
      0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0,
      0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0},
     {// 9
      0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0,
      0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0},
     {// :
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// empty block [11]
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int squaredNumberMatrix[11][64] =  // THIS WILL HOLD (DURING SETUP) THE MATRIX CONTAINING ALL 8x8 DIGIT MAPPINGS
    {{                             // 0
      0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0,
      0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// 1
      0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
      0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// 2
      0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0,
      0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// 3
      0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0,
      0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// 4
      0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0,
      0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// 5
      0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0,
      0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// 6
      0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0,
      0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// 7
      0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
      0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// 8
      0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0,
      0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// 9
      0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0,
      0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {// :
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

uint16_t toLedPos(uint8_t x, uint8_t y) {
   if (x >= MATRIX_WIDTH || y >= MATRIX_HEIGHT || x < 0 || y < 0) {
      Serial.print("Invalid led pos (toLedPos) ");
      Serial.print(" x:");
      Serial.print(x);
      Serial.print(" y:");
      Serial.println(y);

      return NUM_LED_MATRIX;
   }

   return MatrixArray[y][x];
}
/*
 *x = width (max 32)
 *y = height (max 8)
 */
uint16_t toLedPosFlip(uint8_t x, uint8_t y) {
   if (x >= MATRIX_WIDTH || y >= MATRIX_HEIGHT || x < 0 || y < 0)
      return NUM_LED_MATRIX;
   return MatrixArrayFlip[y][x];
}
/*
 *x = width (max 32)
 *y = height (max 8)
 */
uint16_t toLedPosLeft(uint8_t x, uint8_t y) {
   if (x >= MATRIX_WIDTH || y >= MATRIX_HEIGHT || x < 0 || y < 0)
      return NUM_LED_MATRIX;
   return MatrixArrayLeft[y][x];
}

int wrapAround2(int counter, int end) {
   if (counter < 0) {
      counter += end;
   }
   if (counter >= end) {
      counter -= end;
   }
   return counter;
}
uint8_t beatcos8(accum88 beats_per_minute, uint8_t lowest = 0, uint8_t highest = 255, uint32_t timebase = 0, uint8_t phase_offset = 0) {

   uint8_t beat = beat8(beats_per_minute, timebase);
   uint8_t beatcos = cos8(beat + phase_offset);
   uint8_t rangewidth = highest - lowest;
   uint8_t scaledbeat = scale8(beatcos, rangewidth);
   uint8_t result = lowest + scaledbeat;

   return result;
}

uint8_t mapsin8(uint8_t theta, uint8_t lowest = 0, uint8_t highest = 255) {

   uint8_t beatsin = sin8(theta);
   uint8_t rangewidth = highest - lowest;
   uint8_t scaledbeat = scale8(beatsin, rangewidth);
   uint8_t result = lowest + scaledbeat;

   return result;
}

uint8_t mapcos8(uint8_t theta, uint8_t lowest = 0, uint8_t highest = 255) {

   uint8_t beatcos = cos8(theta);
   uint8_t rangewidth = highest - lowest;
   uint8_t scaledbeat = scale8(beatcos, rangewidth);
   uint8_t result = lowest + scaledbeat;

   return result;
}
enum MatrixType_t { HORIZONTAL_MATRIX, VERTICAL_MATRIX, HORIZONTAL_ZIGZAG_MATRIX, VERTICAL_ZIGZAG_MATRIX };
MatrixType_t tMType = VERTICAL_ZIGZAG_MATRIX;

int16_t tHeight = 8;

int16_t tXMult = 0;
int16_t tYMult = 0;

static const int16_t m_absHeight = tHeight;

// x = width (max 32)
// y = height (max 8)
uint16_t mXY(uint16_t x, uint16_t y, bool fliped) {
   uint16_t result;
   if (x >= MATRIX_WIDTH || x < 0) {
      Serial.print("Invalid led pos (mXY) ");
      Serial.print(" x:");
      Serial.print(x);
      Serial.print(" ");
   }
   if (y >= MATRIX_HEIGHT || y < 0) {
      Serial.print("Invalid led pos (mXY) ");
      Serial.print(" y:");
      Serial.print(y);
      Serial.print(" ");
   }
   if (x < 0 || x >= MATRIX_WIDTH) {
      x = (MATRIX_WIDTH - 1) - x;
   }
   if (y < 0 || y >= tHeight) {
      y = (m_absHeight - 1) - y;
   }
   if (tMType == HORIZONTAL_MATRIX) {
      if ((tXMult == 0) && (tYMult == 0))
         result = ((y * MATRIX_WIDTH) + x);
      else
         result = ((y * MATRIX_WIDTH * tYMult) + (x * tXMult));
   } else if (tMType == VERTICAL_MATRIX) {
      if ((tXMult == 0) && (tYMult == 0))
         result = ((x * m_absHeight) + y);
      else
         result = ((x * m_absHeight * tXMult) + (y * tYMult));
   } else if (tMType == HORIZONTAL_ZIGZAG_MATRIX) {
      if (x % 2) {
         if ((tXMult == 0) && (tYMult == 0))
            result = ((((y + 1) * MATRIX_WIDTH) - 1) - x);
         else
            result = ((((y + 1) * MATRIX_WIDTH * tYMult) - tXMult) - (x * tXMult));
      } else {
         if ((tXMult == 0) && (tYMult == 0))
            result = ((y * MATRIX_WIDTH) + x);
         else
            result = ((y * MATRIX_WIDTH * tYMult) + (x * tXMult));
      }
   } else if (tMType == VERTICAL_ZIGZAG_MATRIX && !fliped) {
      if (x % 2) {
         if ((tXMult == 0) && (tYMult == 0))
            result = ((((x + 1) * m_absHeight) - 1) - y);
         else
            result = ((((x + 1) * m_absHeight * tXMult) - tYMult) - (y * tYMult));
      } else {
         if ((tXMult == 0) && (tYMult == 0))
            result = ((x * m_absHeight) + y);
         else
            result = ((x * m_absHeight * tXMult) + (y * tYMult));
      }
   }

   else if (tMType == VERTICAL_ZIGZAG_MATRIX && fliped) {
      if (x % 2) {
         if ((tXMult == 0) && (tYMult == 0))
            result = ((((x + 1) * m_absHeight) - 1) - m_absHeight - y);
         else
            result = ((((x + 1) * m_absHeight * tXMult) - tYMult) - (y * tYMult));
      } else {
         if ((tXMult == 0) && (tYMult == 0))
            result = ((x * m_absHeight) - m_absHeight + y);
         else
            result = ((x * m_absHeight * tXMult) + (y * tYMult));
      }
   }
   if (y >= MATRIX_HEIGHT || y < 0 || x >= MATRIX_WIDTH || x < 0) {
      Serial.println();
   }
   return result;
}
uint16_t mXY(uint16_t x, uint16_t y) {
   return mXY(x, y, false);
}
uint16_t XY(uint16_t x, uint16_t y) {
   return mXY(x, y, false);
}
uint16_t vertical_zigzag_flipped(uint16_t x, uint16_t y) {
   return mXY(x, y, true);
}
uint16_t vertical_zigzag_not_flipped(uint16_t x, uint16_t y) {
   return mXY(x, y, false);
}
// vertical_zigzag_flipped
uint16_t mXY_F(uint16_t x, uint16_t y) {
   return mXY(x, y, true);
}

void FillNoise() {

   for (uint16_t i = 0; i < MATRIX_WIDTH; i++) {

      uint32_t ioffset = noise_scale_x * (i - MATRIX_CENTER_Y);

      for (uint16_t j = 0; j < MATRIX_HEIGHT; j++) {

         uint32_t joffset = noise_scale_y * (j - MATRIX_CENTER_Y);

         byte data = inoise16(noise_x + ioffset, noise_y + joffset, noise_z) >> 8;

         uint8_t olddata = noise[i][j];
         uint8_t newdata = scale8(olddata, noisesmoothing) + scale8(data, 256 - noisesmoothing);
         data = newdata;

         noise[i][j] = data;
      }
   }
}

void setBrightMatrix(uint8_t bright) {
   preferences.begin("settings", false);
   matrixBrightness = map(bright, 0, 100, 0, 255);
   Serial.println(String(matrixBrightness));
   preferences.putInt("mBrightness", matrixBrightness);
   preferences.end();
}
void setBrightStripe(uint8_t bright) {
   preferences.begin("settings", false);
   stripBrightness = map(bright, 0, 100, 0, 255);
   Serial.println(String(stripBrightness));
   preferences.putInt("sBrightness", stripBrightness);
   preferences.end();
}
void setSpeedMatrix(uint16_t speed) {
   preferences.begin("settings", false);
   matrixSpeed = speed;
   Serial.println(String(matrixSpeed));
   preferences.putInt("matrixSpeed", matrixSpeed);
   preferences.end();
}
void setSpeedStripe(uint16_t speed) {
   preferences.begin("settings", false);
   stripeSpeed = speed;
   Serial.println(String(stripeSpeed));
   preferences.putInt("stripeSpeed", stripeSpeed);
   preferences.end();
}

CRGB stringToCRGB(String color) {
   // Serial.println(color);
   CRGB tempcolor;
   if (color == "white") {
      tempcolor = CRGB::White;
   } else if (color == "gray") {
      tempcolor = CRGB::Gray;
   } else if (color == "black") {
      tempcolor = CRGB::Black;
   } else {
      tempcolor = CHSV(map(color.toInt(), 0, 360, 0, 256), 255, 255);
   }
   return tempcolor;
}

void listDir(fs::FS& fs, const char* dirname, uint8_t levels) {
   Serial.printf("Listing directory: %s\r\n", dirname);

   File root = fs.open(dirname);
   if (!root) {
      Serial.println("- failed to open directory");
      return;
   }
   if (!root.isDirectory()) {
      Serial.println(" - not a directory");
      return;
   }

   File file = root.openNextFile();
   while (file) {
      if (file.isDirectory()) {
         Serial.print("  DIR : ");
         Serial.println(file.name());
         if (levels) {
            listDir(fs, file.path(), levels - 1);
         }
      } else {
         Serial.print("  FILE: ");
         Serial.print(file.name());
         Serial.print("\tSIZE: ");
         Serial.println(file.size());
      }
      file = root.openNextFile();
   }
}

void scrollArray(byte scrollDir) {

   byte scrollX = 0;
   for (byte x = 1; x < MATRIX_WIDTH; x++) {
      if (scrollDir == 0) {
         scrollX = MATRIX_WIDTH - x;
      } else if (scrollDir == 1) {
         scrollX = x - 1;
      }

      for (byte y = 0; y < MATRIX_HEIGHT; y++) {
         matrix_Array[mXY(scrollX, y)] = matrix_Array[mXY(scrollX + scrollDir * 2 - 1, y)];
      }
   }
}

int n1(int num)  // Function to isolate first digit of 2-digit integer
{
   num = num / 10;  // Integer division by 10 (discard remainder)
   return num;
}

int n2(int num)  // Function to isolate second digit of 2-digit integer
{
   num = num % 10;  // Modulo division by 10 (keep remainder only)
   return num;
}
int min(int a, int b) {
   return a < b ? a : b;
}

int max(int a, int b) {
   return a > b ? a : b;
}

int middleFingerSprite[][16] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0}, {1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0}, {0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0}, {0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};
const int ppplenght = sizeof(middleFingerSprite) / sizeof(middleFingerSprite[0]);
int cunt = -7;

void scrollMiddleFinger(uint8_t initial_x, uint8_t del, CRGB color, CRGB backround = CRGB::Black) {
   byte row;
   static int startCunt = (MATRIX_HEIGHT - 1) * -1;
   static int cunt = startCunt;
   for (int dy = cunt; dy < MATRIX_HEIGHT + cunt; dy++) {
      for (int dx = 0; dx < 16; dx++) {
         if (dy >= ppplenght || dy < 0) {
            row = 0;
         } else {
            row = middleFingerSprite[dy][dx];
         }
         if (row == 1) {
            clock_array[mXY(dx + initial_x, dy - cunt)] = color;
         } else {
            clock_array[mXY(dx + initial_x, dy - cunt)] = backround;
         }
      }
   }
   EVERY_N_MILLIS_I(inter, del) {
      inter.setPeriod(cunt > startCunt + 3 ? del : del * 3);
      if (++cunt >= ppplenght + 1) {
         cunt = startCunt;
      }
   }
}

void logical_and(int n, bool* mask, bool* wipe, bool* out) {
   int i;
   for (i = 0; i < n; i++) {
      out[i] = mask[i] && wipe[i];
   }
}

void logical_or(int n, bool* mask, bool* wipe, bool* out) {
   int i;
   for (i = 0; i < n; i++) {
      out[i] = mask[i] || wipe[i];
   }
}

void logical_copy(int n, bool* mask, bool* out) {
   int i;
   for (i = 0; i < n; i++) {
      out[i] = mask[i];
   }
}

void logical_not(int n, bool* mask, bool* out) {
   int i;
   for (i = 0; i < n; i++) {
      out[i] = !mask[i];
   }
}

bool logical_equal(int n, bool* mask, bool* wipe) {
   bool out;
   int i = 0;
   while (i < n && mask[i] == wipe[i]) {
      i++;
   }
   return i == n;
}
bool all_true(int n, bool* mask) {
   int i = 0;

   while (i < n && mask[i]) {
      i++;
   }
   return i == n;
}

bool any_false(int n, bool* mask) {
   return !all_true(n, mask);
}

bool all_false(int n, bool* mask) {
   int i = 0;

   while (i < n && !mask[i]) {
      i++;
   }
   return i == n;
}

bool any_true(int n, bool* mask) {
   return !all_false(n, mask);
}

uint32_t Now() {
   uint32_t out;
   return (out);
}

void blurRows_(CRGB* leds, uint8_t width, uint8_t height, fract8 blur_amount) {
   /*    for( uint8_t row = 0; row < height; row++) {
           CRGB* rowbase = leds + (row * width);
           blur1d( rowbase, width, blur_amount);
       }
   */
   // blur rows same as columns, for irregular matrix
   uint8_t keep = 255 - blur_amount;
   uint8_t seep = blur_amount >> 1;
   for (uint8_t row = 0; row < height; row++) {
      CRGB carryover = CRGB::Black;
      for (uint8_t i = 0; i < width; i++) {
         CRGB cur = leds[mXY(i, row)];
         CRGB part = cur;
         part.nscale8(seep);
         cur.nscale8(keep);
         cur += carryover;
         if (i)
            leds[mXY(i - 1, row)] += part;
         leds[mXY(i, row)] = cur;
         carryover = part;
      }
   }
}

// blurColumns: perform a blur1d on each column of a rectangular matrix
void blurColumns_(CRGB* leds, uint8_t width, uint8_t height, fract8 blur_amount) {
   // blur columns
   uint8_t keep = 255 - blur_amount;
   uint8_t seep = blur_amount >> 1;
   for (uint8_t col = 0; col < width; ++col) {
      CRGB carryover = CRGB::Black;
      for (uint8_t i = 0; i < height; ++i) {
         CRGB cur = leds[mXY(col, i)];
         CRGB part = cur;
         part.nscale8(seep);
         cur.nscale8(keep);
         cur += carryover;
         if (i)
            leds[mXY(col, i - 1)] += part;
         leds[mXY(col, i)] = cur;
         carryover = part;
      }
   }
}
void blurMatrix(uint8_t blur_amount) {
   blurRows_(matrix_Array, 32, 8, blur_amount);
   blurColumns_(matrix_Array, 32, 8, blur_amount);
}
void fadeMatrixToBlack(uint8_t fadeAmount) {
   fadeToBlackBy(matrix_Array, NUM_LED_MATRIX, fadeAmount);
}
void fadeLedStripeToBlack(uint8_t fadeAmount) {
   fadeToBlackBy(stripe_Array, STRIPE_LED_AMOUNT, fadeAmount);
}
CRGB invert(CRGB color) {
   CRGB temp = color;
   temp.r = 255 - color.r;
   temp.g = 255 - color.g;
   temp.b = 255 - color.b;
   return temp;
}

String RemoveChar(String str, char c) {
   String result;
   for (size_t i = 0; i < str.length(); i++) {
      char currentChar = str[i];
      if (currentChar != c)
         result += currentChar;
   }
   return result;
}

void lineVertHeight(int pos, int height, CRGB color) {
   for (int i = 0; i < height; i++) {
      matrix_Array[mXY(pos, i)] = color;
   }
}
void lineHorizHeight(int pos, int height, CRGB color) {
   for (int i = 0; i < height; i++) {
      matrix_Array[mXY(i, pos)] = color;
   }
}
void lineHoriz(int pos, CRGB color) {
   for (int i = 0; i < MATRIX_WIDTH; i++) {
      matrix_Array[mXY(i, pos)] = color;
   }
}

void lineVert(int pos, CRGB color) {
   for (int i = 0; i < MATRIX_HEIGHT; i++) {
      matrix_Array[mXY(pos, i)] = color;
   }
}

void addGradientToClock() {
   for (int i = 0; i < NUM_LED_MATRIX; i++) {
      clock_effect_Array[i] = ColorFromPalette(currentPaletteClock, i + color_hue, 255, LINEARBLEND);
   }
}