#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct FreeSeg {
    int start, size;
};

struct Block {
    int start, size;
};

int main() {
    int t, m;
    cin >> t >> m;

    // 初始化内存数组全为0
    vector<int> memory(m, 0);
    // 块表：id -> Block(起始位置, 大小)
    unordered_map<int, Block> blocks;
    // 空闲区间列表
    vector<FreeSeg> free_list = {{0, m}};
    int next_id = 1;
    vector<string> outputs;

    while (t--) {
        string op;
        cin >> op;
        if (op == "alloc") {
            int n;
            cin >> n;
            // 按起始位置排序空闲区间
            sort(free_list.begin(), free_list.end(), [](const FreeSeg& a, const FreeSeg& b) {
                return a.start < b.start;
            });

            bool found = false;
            for (int i = 0; i < free_list.size(); i++) {
                if (free_list[i].size >= n) {
                    // 分配成功
                    int id = next_id++;
                    Block b{free_list[i].start, n};
                    blocks[id] = b;

                    // 更新内存数组
                    for (int j = 0; j < n; j++) {
                        memory[b.start + j] = id;
                    }

                    // 更新空闲区间列表
                    if (free_list[i].size == n) {
                        free_list.erase(free_list.begin() + i);
                    } else {
                        free_list[i].start += n;
                        free_list[i].size -= n;
                    }

                    outputs.push_back(to_string(id));
                    found = true;
                    break;
                }
            }
            if (!found) {
                outputs.push_back("NULL");
            }
        }
        else if (op == "erase") {
            int x;
            cin >> x;
            if (blocks.find(x) == blocks.end()) {
                outputs.push_back("ILLEGAL_ERASE_ARGUMENT");
            } else {
                Block b = blocks[x];
                blocks.erase(x);

                // 清空内存区域
                for (int j = 0; j < b.size; j++) {
                    memory[b.start + j] = 0;
                }

                // 添加新的空闲区间
                FreeSeg new_seg = {b.start, b.size};
                free_list.push_back(new_seg);

                // 按起始位置排序
                sort(free_list.begin(), free_list.end(), [](const FreeSeg& a, const FreeSeg& b) {
                    return a.start < b.start;
                });

                // 合并相邻空闲区间
                vector<FreeSeg> new_list;
                for (int i = 0; i < free_list.size(); i++) {
                    if (new_list.empty()) {
                        new_list.push_back(free_list[i]);
                    } else {
                        FreeSeg& last = new_list.back();
                        if (last.start + last.size == free_list[i].start) {
                            last.size += free_list[i].size;
                        } else {
                            new_list.push_back(free_list[i]);
                        }
                    }
                }
                free_list = new_list;
            }
        }
        else if (op == "defragment") {
            // 收集所有有效块并按起始位置排序
            vector<pair<int, Block>> valid_blocks;
            for (auto& kv : blocks) {
                valid_blocks.push_back({kv.first, kv.second});
            }
            sort(valid_blocks.begin(), valid_blocks.end(),
                [](const pair<int, Block>& a, const pair<int, Block>& b) {
                    return a.second.start < b.second.start;
                });

            // 创建新内存布局
            vector<int> new_mem(m, 0);
            int cur = 0;
            for (auto& p : valid_blocks) {
                int id = p.first;
                Block b = p.second;

                // 将块移动到新位置
                for (int j = 0; j < b.size; j++) {
                    new_mem[cur + j] = id;
                }

                // 更新块表
                blocks[id] = {cur, b.size};
                cur += b.size;
            }

            // 更新内存数组
            memory = new_mem;

            // 更新空闲区间
            free_list.clear();
            if (cur < m) {
                free_list.push_back({cur, m - cur});
            }
        }
    }

    // 输出结果
    for (string& s : outputs) {
        cout << s << endl;
    }
    return 0;
}