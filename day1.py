import sys
from functools import reduce

def pair_append(x,y):
    x[0].append(int(y[0]))
    x[1].append(int(y[1]))
    return x


def main(args, stdin):
    lines = stdin.readlines()

    parsed_pair_lists = reduce(
        pair_append,
        [line.strip().split("   ") for line in lines],
        [[], []]
    )

    distance = sum([
        abs(p[0] - p[1]) for p in zip(*[
                sorted(l) for l in parsed_pair_lists
            ])
    ])
    print("total distance: ", distance)

    similarity = sum(
        [
            v0*len(list(filter(lambda v1: v1 == v0, parsed_pair_lists[1])))
            for v0 in parsed_pair_lists[0]
        ]
    )

    print("similarity: ", similarity)


if __name__ == "__main__":
    main(sys.argv[1:], sys.stdin)