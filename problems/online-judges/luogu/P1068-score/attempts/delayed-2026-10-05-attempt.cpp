// 2026-10-05 延迟复查：学生在聊天中提交的原始函数体。
// 教师仅补上题目给定的结构体和函数签名，未修改比较表达式。
// 规则：score 降序，penalty 升序，id 升序。
struct Player {
    int score;
    int penalty;
    int id;
};

bool cmp(const Player& a, const Player& b)
{if(a.score == b.score){if(a.penalty==b.penalty)return a.id > b.id;else return a.penalty > b.penalty;}else return a.score < b.score;}
