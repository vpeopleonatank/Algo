#include <bits/stdc++.h>
#define MAX 30
using namespace std;

// M là khoản tiền vốn, N là số lĩnh vực đầu tư
// C là chi phí đầu tư,  P là lợi nhuận có thể


struct Field
{
    float cost;
    int profit;
};
int M, N;
Field arr[MAX];

struct Node
{
    // level: chỉ số của mang arr
    // profit: lợi nhuận từ root đến nốt này
    // bound: cận trên của lợi nhuận tối đa trong cây con của node này
    int level, profit, bound;
    float cost;
};

bool cmp(Field a, Field b)
{
    double r1 = (double)a.profit / a.cost;
    double r2 = (double)b.profit / b.cost;
    return r1 > r2;
}

// Trả về cận trên của lợi nhuận trong cây con với root là u
// hàm này sử dụng greedy để tìm cận trên của lợi nhuận tối đa
int bound(Node u, int n, int M, Field arr[])
{
    if (u.cost >= M)
        return 0;

    // khởi tạo cận lợi nhuận = lợi nhuận hiện tại
    int profit_bound = u.profit;

    // bắt đầu thêm các lĩnh vực từ 1 tới chỉ số field hiện tại
    int j = u.level + 1;
    int tot_cost = u.cost;


    // kiểm tra điều kiện chỉ số và điều kiện số tiền đầu tư
    while ((j < n) && (tot_cost + arr[j].cost <= M))
    {
        tot_cost    += arr[j].cost;
        profit_bound += arr[j].profit;
        j++;
    }

    // nếu k không là n, thêm lĩnh vực cuối cùng một phần
    // cho cận trên lợi nhuận
    if (j < n)
        profit_bound += (M - tot_cost) * arr[j].profit /
                                         arr[j].cost;

    return profit_bound;
}

int get_max_profit(int M, Field arr[], int n)
{
    sort(arr, arr + n, cmp);

    queue<Node> Q;
    // node v tích lũy
    Node u, v;

    u.level = -1;
    u.profit = u.cost = 0;
    Q.push(u);

    // rút từng lĩnh vực 1 từ cây quyết định
    // tính lợi nhuận của tất cả các con của lĩnh vực được rút
    // và giữ maxProfit
    int maxProfit = 0;
    while (!Q.empty())
    {
        // rút lĩnh vực đầu hàng
        u = Q.front();
        Q.pop();

        // nếu là nốt đầu, gán level = 0
        if (u.level == -1)
            v.level = 0;

        // nếu không có gì ở level tiếp theo
        if (u.level == n-1)
            continue;

        // hoặc nếu không phải là node cuối, thì tăng level
        // và tính lợi nhuận của các nốt con.
        v.level = u.level + 1;

        // lấy field của level hiện tại, thêm lợi cost và profit
        // của level hiện tại vào cost và profit của node u
        v.cost = u.cost + arr[v.level].cost;
        v.profit = u.profit + arr[v.level].profit;

        // nếu cost tích lũy nhỏ hơn M và profit
        // lớn hơn profit trước
        // cập nhật maxprofit
        if (v.cost <= M && v.profit > maxProfit)
            maxProfit = v.profit;

        // Lấy lợi nhuận cận trên để quyết định
        // thêm node v vào Q ko
        v.bound = bound(v, n, M, arr);

        // Nếu giá trị cận lớn hơn profit
        // thì chỉ đẩy vào Q để đánh giá lúc sau
        if (v.bound > maxProfit)
            Q.push(v);

        // Làm cùng việc, nhưng không chọn field đấy
        v.cost = u.cost;
        v.profit = u.profit;
        v.bound = bound(v, n, M, arr);
        if (v.bound > maxProfit)
            Q.push(v);
    }

    return maxProfit;
}

int main()
{
    freopen("in.knapsack", "r", stdin);
    cin >> M;
    cin >> N;

    for(int i = 0; i < N; i++)
        cin >> arr[i].cost;
    for(int i = 0; i < N; i++)
        cin >> arr[i].profit;
     cout << "Maximum possible profit = "
         << get_max_profit(M, arr, N);
        cout << 2;
    return 0;
}
