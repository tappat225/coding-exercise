/**
 * Title: 1054 The Dominant Color
 * 
 * Behind the scenes in the computer's memory, color is always talked about as a series of 24 bits of information for each pixel.
 * In an image, the color with the largest proportional area is called the dominant color.
 * A strictly dominant color takes more than half of the total area.
 * Now given an image of resolution M by N (for example, 800×600), you are supposed to point out the strictly dominant color.
 * 
 * Input:
 * Each input file contains one test case. For each case,
 * the first line contains 2 positive numbers: M (≤800) and N (≤600) which are the resolutions of the image.
 * Then N lines follow, each contains M digital colors in the range [0,2^24).
 * It is guaranteed that the strictly dominant color exists for each input image.
 * All the numbers in a line are separated by a space.
 * 
 * Output:
 * For each test case, simply print the dominant color in a line.
 * 
 * Input case:
 * 5 3
 * 0 0 255 16777215 24
 * 24 24 0 0 24
 * 24 0 24 24 24
 * 
 * Output case:
 * 24
 * 
 * Link: https://pintia.cn/problem-sets/994805342720868352/problems/994805422639136768
 * 
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> a;
    int colmn, raw;
    int i;
    std::cin >> raw >> colmn;

}

