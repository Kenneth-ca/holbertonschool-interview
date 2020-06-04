#!/usr/bin/python3
"""
A script that reads stdin line by line and computes metrics
"""
import sys

count = 1
sum_size = 0
status_code = {'200': 0, '301': 0, '400': 0, '401': 0, '403': 0, '404': 0,
               '405': 0, '500': 0}

try:
    for line in sys.stdin:
        ln = line.split()

        if len(ln) > 2:
            status = ln[-2]
            size = int(ln[-1])

            sum_size += size
            if status in status_code:
                status_code[status] += 1

        if count % 10 == 0:
            print("File size: {}".format(sum_size))
            for key in sorted(status_code.keys()):
                if status_code[key] != 0:
                    print("{}: {}".format(key, status_code[key]))

        count += 1

except Exception:
    pass

finally:
    print("File size: {}".format(sum_size))
    for key in sorted(status_code.keys()):
        if status_code[key] != 0:
            print("{}: {}".format(key, status_code[key]))
