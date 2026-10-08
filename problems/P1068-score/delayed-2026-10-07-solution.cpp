// 2026-10-07 学生订正后的函数体，按聊天原文保留。
// 教师仅补题目给定的结构体和函数签名。
struct Player {
    int score;
    int penalty;
    int id;
};

bool cmp(const Player& a, const Player& b)
{if(a.score == b.score){if(a.penalty==b.penalty)return a.id < b.id;else return a.penalty < b.penalty;}else return a.score > b.score;}
