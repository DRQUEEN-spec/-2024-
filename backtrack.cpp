// 回溯模板
// void backtacking(参数)
// {
//     if (终止条件)
//     {
//         存放结果;
//         return;
//     }
//     for(选择本层的所有元素/树中节点的子节点的数量){
//         处理节点;
//         backtacking();
//         撤销处理;
//     }
// }

// n皇后
vector<vector<string>> result;

void backtacking(int n, int row, vector<string> &chessboard)
{
    if (row == n)
    {
        result.push_back(chessboard);
        return;
    }
    for (int col = 0; col < n; col++)
    {
        if (isValid(row, col, chessboard, n))
        {
            // 用Q表示皇后，用.表示空
            chessboard[row][col] = 'Q';
            backtacking(n, row + 1, chessboard);
            chessboard[row][col] = '.';
        }
    }
}

// 不能同行、不能同列、不能同对角线
bool isValid(int row, int col, vector<string> &chessboard, int n)
{
    // 检查列
    for (int i = 0; i < row; i++)
    {
        if (chessboard[i][col] == 'Q')
        {
            return false;
        }
    }
    // 检查45度角有无皇后
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (chessboard[i][j] == 'Q')
        {
            return false;
        }
    }
    // 检查135度角有无皇后
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (chessboard[i][j] == 'Q')
        {
            return false;
        }
    }

    return true;
}

int main(int n)
{
    // 初始化chessboard
    backtacking(n, 0, chessboard);
    return result;
}

// 斐波那契数列
// 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
// 用f（x）表示爬到第x级台阶的方案数量
// 求第n级的解决方案数量，只和n-1、n-2级的解决方案数有关
int climbStairs(int n)
{
    int p = 0, q = 0, r = 1;
    for (int i = 1; i <= n; i++)
    {
        p = q;
        q = r;
        r = p + q;
    }
    return r;
}

// 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，**如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警**。给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
// 时间复杂度o（N），空间复杂度o（N）？空间复杂度优化到o（1）
int rob(int *nums, int numsSize)
{
    if (numsSize == 1)
    {
        return *nums;
    }

    int dp[numsSize];
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < numsSize; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    return max(dp[numsSize - 1], dp[numsSize - 2]);
}