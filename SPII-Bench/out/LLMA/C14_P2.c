#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static void format_number(double number_value, char *destination_buffer)
{
    if (!isinf(number_value) && number_value == floor(number_value)) {
        sprintf(destination_buffer, "%lld", (long long) number_value);
    } else {
        sprintf(destination_buffer, "%.2f", number_value);
    }
}

static int compute_result(double left_operand, const char *operator_text, double right_operand, double *result_out)
{
    if (strcmp(operator_text, "+") == 0) {
        *result_out = left_operand + right_operand;
        return 1;
    }
    if (strcmp(operator_text, "-") == 0) {
        *result_out = left_operand - right_operand;
        return 1;
    }
    if (strcmp(operator_text, "*") == 0) {
        *result_out = left_operand * right_operand;
        return 1;
    }
    if (strcmp(operator_text, "/") == 0) {
        if (right_operand == 0) {
            return 0;
        }
        *result_out = left_operand / right_operand;
        return 1;
    }
    return -1;
}

int main(void)
{
    double left_operand, right_operand;
    char operator_text[16];

    scanf("%lf", &left_operand);
    scanf("%15s", operator_text);
    scanf("%lf", &right_operand);

    double result_value;
    int status = compute_result(left_operand, operator_text, right_operand, &result_value);

    if (status == -1) {
        printf("Error: invalid operator\n");
        return 0;
    }
    if (status == 0) {
        printf("Error: division by zero\n");
        return 0;
    }

    char output_buffer[64];
    format_number(result_value, output_buffer);
    printf("%s\n", output_buffer);

    return 0;
}
