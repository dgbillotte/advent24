import sys


def safe_increasing(report):
    for idx, val in enumerate(report):
        if idx >= (len(report)-1):
            break
        if (report[idx+1] - report[idx]) not in range(1,4):
            return False
    return True

def safe_decreasing(report):
    for idx, val in enumerate(report):
        if idx >=(len(report)-1):
            break
        if (report[idx] - report[idx+1]) not in range(1,4):
            return False
    return True

def is_safe(report):
    if report[0] == report[1]:
        return False
    if report[0] < report[1]:
        # print("testing increasing", report)
        return safe_increasing(report)
    # print("testing decreasing", report)
    return safe_decreasing(report)

def clean_report(report, idx_to_remove):
    clean = report.copy()
    clean.pop(idx_to_remove)
    return clean

def cleaned_perms(report):
    reports = []
    for i in range(len(report)):
        reports.append(clean_report(report, i))
    return reports

def main(argv, stdin):
    
    lines = stdin.readlines()
    safe_reports = 0
    safeish_reports = 0
    for line in lines:
        report = [int(val) for val in line.split(' ')]
        if is_safe(report):
            safe_reports += 1
        else:
            for cleaned_report in cleaned_perms(report):
                if is_safe(cleaned_report):
                    safeish_reports += 1
                    break

    print(f"There were\n\tsafe reports: {safe_reports}\n\tsafeish reports:{safeish_reports}\n\ttotal: {safe_reports+safeish_reports}\n\tout of {len(lines)} reports")


if __name__ == "__main__":
    main(sys.argv[1:], sys.stdin)
