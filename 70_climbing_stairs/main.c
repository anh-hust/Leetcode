#include <stdio.h>
#include <stdlib.h>

/**
 * @brief https://www.geeksforgeeks.org/dsa/count-ways-reach-nth-stair/
 */

struct climbing_stair_solutions {
    const char* name;
    const char* info;
    int (*implement)(int n);
};

/**
 * @brief climbing stair by recursive time O(2^n) spce O(n)
 *
 * @param n
 * @return f(n) = f(n-1) + f(n-2), f(1) = 1, f(2) = 2 <1.1 + 2> like fibonacci sequence
 */
int s1_climbStairs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    return s1_climbStairs(n - 1) + s1_climbStairs(n - 2);
}

/**
 * @brief climbing stair by Top-Down DP (Memoization) time O(n) spce O(n)
 * * Draw the stack frame of recursive then you will get the idea of memoization & dynamic programming
 *
 * @param n
 */
int s2_action(int n, int* mem_arr) {
    if (1 == n || 0 == n) return 1;

    if (mem_arr[n] != 0) return mem_arr[n];

    mem_arr[n] = s2_action(n - 1, mem_arr) + s2_action(n - 2, mem_arr);  // update memory
    return mem_arr[n];
}

int s2_climbStairs(int n) {
    int* memoization_arr = (int*)calloc((n + 1), sizeof(int));

    return s2_action(n, memoization_arr);
}

/**
 * @brief climbing stair by Bottom-Up DP (Tabulation) time O(n) spce O(n)
 *
 * @param n
 * @return
 */
int s3_climbStairs(int n) {
    int* fibonacci = (int*)malloc((n + 1) * sizeof(int));
    fibonacci[0] = 1;
    fibonacci[1] = 1;

    int traverser_index = 2;
    while (traverser_index < n + 1) {
        fibonacci[traverser_index] = fibonacci[traverser_index - 1] + fibonacci[traverser_index - 2];
        traverser_index += 1;
    }

    return fibonacci[n];
}

/**
 * @brief climbing stair by Space Optimized DP time O(n) spce O(1), instead of whole array to hold fibonacci sequence -> use 2 variable to hold f(n-1) & f(n-2)
 *
 * @param n
 * @return
 */
int s4_climbStairs(int n) {
    if (n == 1) return 1;
    int f_minus_1 = 1;
    int f_minus_2 = 1;

    int result = 0;
    int climb_index = 2;
    while (climb_index < n + 1) {
        result += f_minus_1 + f_minus_2;
        // update f-1 & f-2 for next iteration
        f_minus_2 = f_minus_1;
        f_minus_1 = result;
        climb_index += 1;
    }

    return result;
}

/**
 * @brief climbing stair by Matrix Exponentiation time O(logn) spce O(1)
 *
 * @param n
 * @return
 */
int s5_climbStairs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    return climbStairs(n - 1) + climbStairs(n - 2);
}

int main() {
    int solution_select;
    // init the solutions list of climbing stairs
    struct climbing_stair_solutions solutions[] = {
        {"1. Recursive", "Time O(2^n) -- Space O(n)", s1_climbStairs},
        {"2. Top-Down DP (Memoization)", "Time O(n) -- Space O(n)", s2_climbStairs},
        {"3. Bottom-Up DP (Tabulation)", "Time O(n) -- Space O(n)", s3_climbStairs},
        {"4. Space Optimized DP", "Time O(n) -- Space O(1)", s4_climbStairs},
        {"5. Matrix Exponentiation", "Time O(logn) -- Space O(1)", s5_climbStairs},
    };
    int n;
    printf("Enter the input number: ");
    scanf("%d", &n);

    printf("All the solution: \n");
    for (int i = 0; i < sizeof(solution_select) / sizeof(struct climbing_stair_solutions); i++) {
        printf("%s. Complexity info: %s\n", solutions->name, solutions->info);
    }

    printf(">> Please choose 1 solution to solve problem: \n");
    scanf("%d", &solution_select);

    printf("Number of climbing stairs: %d\n", solutions[solution_select - 1].implement(n));
    return 0;
}