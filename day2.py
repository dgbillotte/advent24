import sys

def clean_report(report, idx_to_remove):
    clean = report.copy()
    clean.pop(idx_to_remove)
    return clean


def safe_increasing(report, backtrack=True):
    for idx, val in enumerate(report):
        if idx >= (len(report)-1):
            break
        if (report[idx+1] - report[idx]) not in range(1,4):
            if backtrack:
                safe_increasing(clean_report(report, idx), False)
            else:
                return False
    return True

def safe_decreasing(report, backtrack=True):
    for idx, val in enumerate(report):
        if idx >=(len(report)-1):
            break
        if (report[idx] - report[idx+1]) not in range(1,4):
            if backtrack:
                safe_decreasing(clean_report(report, idx), False)
            else:
                return False
    return True

def is_safe(report, backtrack=False):
    if report[0] < report[len(report)-1]:
        return safe_increasing(report, backtrack)
    return safe_decreasing(report, backtrack)


def main(argv, stdin):
    
    lines = stdin.readlines()
    safe_reports = 0
    for line in lines:
        report = [int(val) for val in line.split(' ')]
        if is_safe(report, True):
            safe_reports += 1

    print(f"There were {safe_reports} safe reports out of {len(lines)} report")


if __name__ == "__main__":
    main(sys.argv[1:], sys.stdin)
