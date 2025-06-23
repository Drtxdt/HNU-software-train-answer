#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 读取四个输入值
    long long nums[4];
    for (int i = 0; i < 4; i++) {
        cin >> nums[i];
    }
    
    // 对四个数进行排序
    sort(nums, nums + 4);
    
    // a+b+c 一定是最大的那个数
    long long total = nums[3];
    
    // 计算 a, b, c
    long long a = total - nums[2]; // 最大和减去第二大值（应为某个两数之和）
    long long b = total - nums[1]; // 最大和减去第二小值
    long long c = total - nums[0]; // 最大和减去最小值
    
    // 但这样得到的a,b,c大小顺序不确定，所以需要再次排序
    long long result[3] = {a, b, c};
    sort(result, result + 3);
    
    // 输出结果
    cout << result[0] << " " << result[1] << " " << result[2] << endl;
    
    return 0;
}