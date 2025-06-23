#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <unordered_map>

using namespace std;

const int MAX_N = 100000; // 最大申请人数
const int DATE_LEN = 11;  // 日期字符串长度

struct Applicant {
    char id[19];          // 身份证号码 (18+1)
    int social;           // 社保缴纳月数
    int area;             // 现有住房面积
    char date[DATE_LEN];  // 申报日期 (10+1)
};

struct SortedApplicant {
    string id;         // 身份证号
    int type;          // 0:刚性需求, 1:改善性需求
    int social;        // 社保月数
    int area;          // 住房面积
    int date_int;      // 日期转换为整数(YYYYMMDD)
    int rank_group;    // 组内排名标识
    int group_start;   // 组起始索引
    int group_size;    // 组大小
};

Applicant persons[MAX_N];   // 静态申请者数组
SortedApplicant sorted[MAX_N]; // 排序后的数组
unordered_map<string, SortedApplicant> map; // 快速查询映射

// 比较函数：先类型(刚性>改善)，然后按规则排序
bool cmp(const SortedApplicant& a, const SortedApplicant& b) {
    if (a.type != b.type) return a.type < b.type;
    if (a.type == 0) {
        if (a.social != b.social) return a.social > b.social;
        return a.date_int < b.date_int;
    } else {
        if (a.area != b.area) return a.area < b.area;
        return a.date_int < b.date_int;
    }
}

// 从二进制文件读取数据
void readData(int& n) {
    FILE* fp = fopen("house.bin", "rb");
    if (!fp) {
        cerr << "Error: Cannot open house.bin" << endl;
        exit(1);
    }

    fseek(fp, -4, SEEK_END);
    fread(&n, 4, 1, fp);
    if (n > MAX_N) {
        cerr << "Error: n exceeds maximum size" << endl;
        exit(1);
    }

    rewind(fp);
    fread(persons, sizeof(Applicant), n, fp);
    fclose(fp);
}

// 将日期字符串转换为整数
int convertDate(const char* dateStr) {
    char buffer[DATE_LEN];
    strncpy(buffer, dateStr, DATE_LEN-1);
    buffer[DATE_LEN-1] = '\0';

    int year, month, day;
    if (sscanf(buffer, "%02d-%02d-%04d", &month, &day, &year) == 3) {
        return year * 10000 + month * 100 + day;
    }
    return 0; // 转换失败返回0
}

int main() {
    int n = 0;
    readData(n);  // 从文件读取数据

    int validCount = 0; // 合格申请人计数

    // 处理原始数据，筛选合格申请人
    for (int i = 0; i < n; i++) {
        // 设置默认值
        int type = -1;
        bool qualified = false;

        // 判断申请类型
        if (persons[i].area == 0 && persons[i].social > 24) {
            type = 0;       // 刚性需求
            qualified = true;
        } else if (persons[i].area > 0) {
            type = 1;       // 改善性需求
            qualified = true;
        }

        // 为合格申请人创建排序条目
        if (qualified) {
            sorted[validCount] = {
                string(persons[i].id),
                type,
                persons[i].social,
                persons[i].area,
                convertDate(persons[i].date),
                -1, // rank_group 暂未设置
                -1, // group_start 暂未设置
                0   // group_size 暂未设置
            };
            map[string(persons[i].id)] = sorted[validCount];
            validCount++;
        }
        // 不合格申请人直接加入映射表
        else {
            map[string(persons[i].id)] = {
                string(persons[i].id),
                -1, // type
                persons[i].social,
                persons[i].area,
                0,  // date_int
                -1, // rank_group
                -1, // group_start
                0   // group_size
            };
        }
    }

    // 对合格申请人排序
    sort(sorted, sorted + validCount, cmp);

    // 分配组信息
    for (int i = 0; i < validCount;) {
        int j = i;
        // 查找相同条件的组
        while (j < validCount) {
            bool same = (sorted[i].type == sorted[j].type);
            if (sorted[i].type == 0) {
                same &= (sorted[i].social == sorted[j].social);
            } else {
                same &= (sorted[i].area == sorted[j].area);
            }
            same &= (sorted[i].date_int == sorted[j].date_int);

            if (!same) break;
            j++;
        }

        // 更新组信息
        int group_size = j - i;
        for (int k = i; k < j; k++) {
            sorted[k].group_start = i;
            sorted[k].group_size = group_size;
            sorted[k].rank_group = i + 1; // 排名从1开始
        }

        // 更新映射
        for (int k = i; k < j; k++) {
            map[sorted[k].id] = sorted[k];
        }

        i = j; // 移动到下一组
    }

    int m, T;
    cin >> m >> T;

    vector<string> queries(T);
    for (int i = 0; i < T; i++) {
        cin >> queries[i];
    }

    // 处理查询
    for (const string& id : queries) {
        if (map.find(id) == map.end()) {
            cout << "Sorry" << endl;
            continue;
        }

        const SortedApplicant& app = map[id];

        // 检查资格
        if (app.type == -1 ||         // 未识别类型
            app.rank_group > m ||     // 排名超出房源数
            app.group_size == 0) {    // 无组信息
            cout << "Sorry" << endl;
            continue;
        }

        // 计算该组之前的房源占用
        int prev_used = app.group_start;
        int remaining = m - prev_used;

        // 该组一套都分不到
        if (remaining <= 0) {
            cout << "Sorry" << endl;
            continue;
        }

        // 根据组大小输出不同结果
        if (app.group_size == 1) {
            cout << prev_used + 1 << endl;
        }
        else {
            // 该组可以全部分到房子
            if (remaining >= app.group_size) {
                cout << (prev_used + 1) << " " << (prev_used + app.group_size) << endl;
            }
            // 只能分到部分房子
            else {
                cout << remaining << "/" << app.group_size << endl;
            }
        }
    }

    return 0;
}