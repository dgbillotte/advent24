#include <stdio.h>
#include <stdlib.h>

const int INPUT_LINE_LENGTH = 100;
const int REPORT_MAX_VALUES = 10;

int safe_increasing(int* report, int len) {
    for(int i=0; i < len-1; i++) {
        int diff = report[i+1] - report[i];
        if(diff < 1 || diff > 3) {
            return 0;
        }
    }
    return 1;
}

int safe_decreasing(int* report, int len) {
    for(int i=0; i < len-1; i++) {
        int diff = report[i] - report[i+1];
        if(diff < 1 || diff > 3) {
            return 0;
        }
    }
    return 1;
}

int is_safe(int* report, int len) {
    if(report[0] == report[1]) {
        return 0;
    }
    if(report[0] < report[1]) {
        return safe_increasing(report, len);
    }
    return safe_decreasing(report, len);
}

int parse_values(char* line, int* values) {
    char str_value[3] = "";
    int str_idx = 0;
    int value;
    int num_values = 0;

    char cur_char;
    for(int i=0; i < INPUT_LINE_LENGTH; i++) {
        cur_char = line[i];
        if(cur_char >= '0' && cur_char <= '9') {
            str_value[str_idx] = cur_char;
            str_idx++;
        } else {
            str_value[str_idx] = 0;
            str_idx = 0;
            if(cur_char == 0) {
                break;
            }
            value = atoi(str_value);
            values[num_values] = value;
            num_values++;
        }
    }

    return num_values;
}

int main() {
    char line[INPUT_LINE_LENGTH];
    int report[REPORT_MAX_VALUES];
    int cleaned_report[REPORT_MAX_VALUES];
    int num_reports = 0;
    int safe_reports = 0;
    int safeish_reports = 0;

    while(fgets(line, sizeof(line), stdin)) {
        num_reports++;
        int len = parse_values(line, report);
        if(is_safe(report, len)) {
            safe_reports++;
        } else {
            int skip = 0;
            while(skip < len) {
                for(int i=0; i < len; i++) {
                    if(i < skip) {
                        cleaned_report[i] = report[i];
                    } else if(i == skip) {
                        continue;
                    } else {
                        cleaned_report[i-1] = report[i];
                    }
                }
                if(is_safe(cleaned_report, len-1)) {
                    safeish_reports++;
                    break;
                }
                skip++;
            }
        }
    }

    printf("There were\n\tsafe reports: %d\n\tsafeish reports: %d\n\ttotal: %d\n\tout of %d reports\n",
            safe_reports, safeish_reports, safe_reports+safeish_reports, num_reports);
}