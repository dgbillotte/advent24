#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sort(int* list, int len) {
    int tmp;
    for(int i=0; i < len-1; i++) {
        for(int j=0; j < len-i-1; j++) {
            if(list[j] > list[j+1]) {
                tmp = list[j];
                list[j] = list[j+1];
                list[j+1] = tmp;
            } 
        }
    }
}

int count_occurances(int* list, int len, int value) {
    int count = 0;
    for(int i=0; i < len; i++) {
        if(list[i] == value) {
            count++;
        }
    }
    return count;
}

int main() {
    int lists[2][1000] = {0};
    int* list0 = lists[0];
    int* list1 = lists[1];

    char line[15];  // lines will match /\d{5}\s{3}\d{5}\n/, which is 14 characters, add one for the \0

    // Read input line by line
    int num0, num1;
    char spaces[4];
    int idx = 0;
    while (fgets(line, sizeof(line), stdin)) {

        if (sscanf(line, "%d%3c%d", &num0, spaces, &num1) > 0) {
            list0[idx] = num0;
            list1[idx] = num1;
            idx++;
        } else {
            printf("Conversion failed.\n");
        }
    }

    printf("sorting list 0\n");
    sort(list0, idx);
    printf("sorting list 1\n");
    sort(list1, idx);
    
    printf("sorted lists\n");
    int distance = 0;
    int similarity = 0;
    for(int i=0; i< idx; i++) {
        distance += abs(list0[i] - list1[i]);
        similarity += list0[i] * count_occurances(list1, idx, list0[i]);
    }

    printf("distance: %d\nsimilarity: %d\n", distance, similarity);

    return 0;
}