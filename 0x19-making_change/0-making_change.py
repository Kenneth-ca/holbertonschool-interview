#!/usr/bin/python3
"""
Determines the fewest number of coins needed to meet a
given amount total
"""


def makeChange(coins, total):
    """
    Makes changes given a pile of coins
    """
    if total <= 0:
        return 0

    changes = 0
    idx = 0
    min_coins = 0

    new_coins = sorted(coins, reverse=True)
    my_coins = len(new_coins)
    aux = total

    while changes < total and idx < my_coins:
        while new_coins[idx] <= aux:
            changes = changes + new_coins[idx]
            min_coins += 1
            if changes == total:
                return min_coins
            aux = total - changes
        idx += 1

    return -1
