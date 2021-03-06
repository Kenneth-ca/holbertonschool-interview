#!/usr/bin/python3
"""
Determines if all given boxes can be opened
"""


def FindKeys(k_found, boxes):
    """
    Return keys found from all boxes
    """
    i = 0
    while i < len(k_found):
        if boxes[k_found[i]] != [] or boxes[k_found[i]] not in k_found:
            for k in boxes[k_found[i]]:
                if k < len(boxes) and k not in k_found:
                    k_found.append(k)
        i += 1
    return k_found


def canUnlockAll(boxes):
    """
    Return True if all boxes can be opened, else return False
    """
    if (type(boxes) is not list) or (len(boxes) == 0):
        return False

    lockboxes = {}
    for i in range(len(boxes)):
        lockboxes[i] = boxes[i]
    lockboxes.pop(0)

    keys_found = FindKeys([0], boxes)

    for i in keys_found:
        lockboxes.pop(i, None)
    return not lockboxes
