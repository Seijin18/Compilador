// DFA

#define AC -9
#define ER -10

char simbolos[] = {'+', '-', '*', '/', '<', '>', '=', '!', ';', ',', '(', ')', '[', ']', '{', '}', '.'}; // Simbolos

int dfa[27][20] = {
    { 2,  1,  0,  3,  4,  5,  6, 12, 11,  7,  9, 15, 16, 17, 18, 19, 20, 21, 22, ER},// 0
    {ER,  1, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, ER},// 1
    { 2, ER, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, ER},// 2
    {AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, ER},// 3
    {AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, ER},// 4
    {AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, ER},// 5
    {AC, AC, AC, AC, AC, 23, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, ER},// 6
    {AC, AC, AC, AC, AC, AC, AC, AC, AC,  8, AC, AC, AC, AC, AC, AC, AC, AC, AC, ER},// 7
    {AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, ER},// 8
    {ER, ER, ER, ER, ER, ER, ER, ER, ER, 10, ER, ER, ER, ER, ER, ER, ER, ER, ER, ER},// 9
    {AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, ER},// 10
    {AC, AC, AC, AC, AC, AC, AC, AC, AC, 13, AC, AC, AC, AC, AC, AC, AC, AC, AC, ER},// 11
    {AC, AC, AC, AC, AC, AC, AC, AC, AC, 14, AC, AC, AC, AC, AC, AC, AC, AC, AC, ER},// 12
    {AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, ER},// 13
    {AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, ER},// 14
    {AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, ER},// 15
    {AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, ER},// 16
    {AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, ER},// 17
    {AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, ER},// 18
    {AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, ER},// 19
    {AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, ER},// 20
    {AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, ER},// 21
    {AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, ER},// 22
    {23, 23, 23, 23, 23, 25, 24, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23},// 23
    {23, 23, 23, 23, 23, ER, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23},// 24
    {23, 23, 23, 23, 23, 23, 26, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23},// 25
    {AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, AC, ER} // 26
};