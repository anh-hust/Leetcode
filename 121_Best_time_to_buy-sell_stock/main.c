/**
 * OK
 */
#include <stdio.h>
#include <stdlib.h>

int maxProfit(int* prices, int pricesSize) {
    int buy_price = prices[0];
    int sell_price = prices[0];
    int buy_time = 0;
    int sell_time = 0;

    int current_profit = 0;
    int max_profit = 0;

    int day;
    for (day = 1; day < pricesSize; day++) {
        // cache the last available profit. avoid if the buy_time at the last day of prices[] then cannot find available sell day anymore
        // ex: [2,4,1]
        if (prices[day] < buy_price) {
            buy_price = prices[day];
            buy_time = day;
        }
        // updatable condition
        if (prices[day] > buy_price && day > buy_time) {
            // to make sure the updatable value is the best one to update
            if (prices[day] > sell_price || sell_time <= buy_time) {
                sell_price = prices[day];
                sell_time = day;
            }
        }
        if (sell_time > buy_time) {
            current_profit = sell_price - buy_price;
            current_profit > max_profit ? max_profit = current_profit : max_profit;
        }
    }

    return max_profit;
}

int main() {
    int input[] = {2,4,1};
    int len = sizeof(input) / sizeof(input[0]);

    printf("The max profit: %d\n", maxProfit(input, len));
    return 0;
}